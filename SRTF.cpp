/*  
  Wesley B Johnson
  Due date: April 04, 2023
  Function: Shortest Remaing Time First Scheduler
  Source: https://www.geeksforgeeks.org/shortest-remaining-time-first-preemptive-sjf-scheduling-algorithm/?ref=rp
*/
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include "Process.hpp"

using namespace std;

int Process::srtf(string fileName){

    std::vector<int> readyQueue;
    process *p = new process[PC];
    process obj;
    ifstream fin;
    int i = 0;
    int currentTime = 0;
    int programsExecuted = 0;
    int contextSwitches = 0;
    float aveBurstTime = 0;
    float aveWaitTime = 0;
    float aveTurnAround = 0;

    printf("************************************************************\n");
    printf("************ Scheduling algorithm : SRTF *******************\n");
    printf("************************************************************\n");

    fin.open("input.txt");

   while(true){

    if(fin.eof()){
        break;
    };

    // Read data from file into process object and add to array.
    fin >> obj.pidNum >> obj.arrival >> obj.burstTime;
    obj.burstTimeRemaining = obj.burstTime;
    obj.processStatus = "New Process";
    p[i] = obj;
    i++;
   };
    fin.close();

 // Initiaillzing queue with first process.
  readyQueue.push_back(0);
  p[0].inQueue = true;

  while(!readyQueue.empty()){
    updateVQueue(p, PC, readyQueue, currentTime, programsExecuted, contextSwitches);
  }

  averageTimes(aveWaitTime, aveBurstTime, aveTurnAround, p);
  
  cout << "Average CPU burst time: " << aveBurstTime << " ms" << endl;
  cout << "Average wait time:  " << aveWaitTime << " ms" << endl;
  cout << "Average turn around time: " << aveTurnAround << " ms" << endl;
  cout << "Total No. of Context Switches performed: " << contextSwitches << endl;
  return 0;
}

void Process::updateVQueue(process p[], int n, vector<int> &readyQueue, int &currentTime, int &programsExecuted, int &contextSwitches){
  int complete = 0;
  bool check;

  // Loop process until all processes are completed.
  while (complete != n){

    if(int i = compareBursts(p, PC, currentTime, readyQueue) > 0){
      contextSwitches++;
      check = true;

      if(p[i].burstTimeRemaining <= 0){
        p[i].processStatus = "Complete";
        p[i].timeCompleted = currentTime + 1;
        p[i].waitTime = ( p[i].timeCompleted - p[i].arrival - p[i].burstTime );

        if(p[i].waitTime < 0){
          p[i].waitTime = 0;
        };
        
        p[i].turnAround = ( p[i].waitTime + p[i].burstTime );
        p[i].burstTimeRemaining = 0;

        if(programsExecuted != n){
          checkNewArrivals(p, n, currentTime, readyQueue);
        }
        readyQueue.erase(readyQueue.begin()+(i-1));
        complete++;
      }

      else{
          p[i].burstTimeRemaining--;
          p[i].processStatus = "In Process";

          if(programsExecuted != n){
            checkNewArrivals(p, n, currentTime, readyQueue);
          };
        };
    };
    currentTime++;
  };
};

void Process::checkNewArrivals(process p[], const int n, const int &currentTime, vector<int> &readyQueue){
  for(int i = 0; i < n; i++){
    process proc = p[i];

    if(proc.arrival <= currentTime && !proc.inQueue && proc.processStatus != "Complete"){
      p[i].processStatus = "New Process";
      p[i].inQueue = true;
      readyQueue.push_back(i);
    };
  };
};

void Process::averageTimes(float &aveWaitTime, float &aveBurstTime, float & aveTurnAround, process p[]){

  for(int i = 0; i < PC; i++){
    aveBurstTime += p[i].burstTime;
    aveWaitTime += p[i].waitTime;
    aveTurnAround += p[i].turnAround;
  };

  aveBurstTime = aveBurstTime/PC;
  aveWaitTime = aveWaitTime/PC;
  aveTurnAround = aveTurnAround/PC;


};

int Process::compareBursts(process p[], int n, int &currentTime, vector<int>readyQueue){
  int min = p[0].burstTimeRemaining;
  int idx = 0;

  for(int i = 0; i < n; i++){
    if (p[i].burstTimeRemaining < min && p[i].arrival <= currentTime){
      min = p[i].burstTimeRemaining;
      idx = i;
    };
  };
  return idx;
};
