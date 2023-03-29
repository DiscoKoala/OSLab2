#ifndef FCFS
#define FCFS
/*
  Wesley B Johnson
  Due date: April 04, 2023
  Function: First Come First Server Process Scheduler
*/
#include <string>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <unistd.h>
#include <fstream>
#include <time.h>

using namespace std;

int PC = 26;

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
    process obj, obj1;
    ifstream fin;
    int totalTime = 0;
    int i = 0;

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

    totalTime = totalTime + p[0].arrival;

    for(i = 0; i < PC; i++){
      totalTime = totalTime + p[i].burstTime;
      p[i].timeCompleted = totalTime;
      p[i].turnAround = p[i].timeCompleted - p[i].arrival;
      p[i].waitTime = p[i].turnAround - p[i].burstTime;

      if(totalTime < p[i+1].arrival){
        int t = p[i+1].arrival - totalTime;
        totalTime = totalTime + t;
      };
  
      cout << "Completion time: "<< p[i].timeCompleted << endl;
      cout << "Turn around time: " << p[i].turnAround << endl;
      cout << "Wait time: " << p[i].waitTime << endl;
    };

    fin.close();
  
  return 0;
}

#endif