#ifndef FCFS
#define FCFS
/*
  Wesley B Johnson
  Due date: April 04, 2023
  Function: First Come First Server Process Scheduler
  Source: https://www.geeksforgeeks.org/program-for-fcfs-cpu-scheduling-set-2-processes-with-different-arrival-times/?ref=rp
*/
#include <string>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <unistd.h>
#include <fstream>
#include <time.h>

using namespace std;

int PC = 10;

struct process{
    int pidNum;
    int arrival;
    int burstTime;
    int timeCompleted = 0;
    int waitTime = 0;
    int turnAround = 0;
    string processStatus;
};

int fcfs(string fileName){

    process *p = new process[PC];
    process obj;
    ifstream fin;
    int totalTime = 0;
    int i = 0;
    float aveBurstTime = 0;
    float aveWaitTime = 0;
    float aveTurnAround = 0;

    cout << "************************************************************" << endl;
    cout << "************ Scheduling algorithm : FCFS *******************" << endl;
    cout << "************************************************************" << endl << endl;

    fin.open("input.txt", ios::in);

    // Read data from file into process object and add to array.
   while(true){
        if(fin.eof()){
            break;
        };
        fin >> obj.pidNum >> obj.arrival >> obj.burstTime;
        obj.processStatus = "New Process";
        p[i] = obj;
        i++;
    };
    fin.close();

    totalTime = totalTime + p[0].arrival;

    for(i = 0; i < PC; i++){
      totalTime = totalTime + p[i].burstTime;
      p[i].timeCompleted = totalTime;
      p[i].turnAround = p[i].timeCompleted - p[i].arrival;
      p[i].waitTime = p[i].turnAround - p[i].burstTime;

      aveBurstTime = aveBurstTime + p[i].burstTime;
      aveWaitTime = aveWaitTime + p[i].waitTime;
      aveTurnAround = aveTurnAround + p[i].turnAround;

      if(totalTime < p[i+1].arrival){
        int t = p[i+1].arrival - totalTime;
        totalTime = totalTime + t;
      };
  
      cout << "Completion time: "<< p[i].timeCompleted << endl;
      cout << "Turn around time: " << p[i].turnAround << endl;
      cout << "Wait time: " << p[i].waitTime << endl;
    };

    aveBurstTime = aveBurstTime/PC;
    aveWaitTime = aveWaitTime/PC;
    aveTurnAround = aveTurnAround/PC;

    cout << "" << endl;
    cout << "*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  * " << endl;
    cout << "0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29" << endl << endl;

    cout << "Average CPU burst time: " << aveBurstTime << " ms" << endl;
    cout << "Average wait time:  " << aveWaitTime << " ms" << endl;
    cout << "Average turn around time: " << aveTurnAround << " ms" << endl;
    cout << "Total No. of Context Switches performed: 0" << " ms" << endl;

  // delete p;

  return 0;
}

#endif