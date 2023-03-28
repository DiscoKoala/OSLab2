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

    process p[50];
    process obj, obj1;
    ifstream fin;
    int totalTime = 0;
    int i = 0;

    cout << "************************************************************" << endl;
    cout << "************ Scheduling algorithm : FCFS *******************" << endl;
    cout << "************************************************************" << endl;

    fin.open("input.txt", ios::in);

    // Read data from file into process object and add to array.
   while(true){
        if(fin.eof()){
            break;
        };
        fin >> obj.pidNum >> obj.arrival >> obj.burstTime;
        obj.processStatus = "New Process";
        totalTime += obj.burstTime;
        p[i] = obj;
        i++;
    };

    p[0].waitTime = 0;
    p[0].timeCompleted = p[0].burstTime;
    p[0].turnAround = p[0].burstTime;

    for(i = 1; i < totalTime; i++){
      obj = p[i];

  
    };

    fin.close();
  
  return 0;
}

#endif