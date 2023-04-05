
/*  
  Wesley B Johnson
  Due date: April 04, 2023
  Function: Round Robin Scheduler
  Source: https://www.geeksforgeeks.org/round-robin-scheduling-with-different-arrival-times/?ref=rp
*/
#include <string.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <unistd.h>
#include <iomanip>
#include <queue>
#include "Process.hpp"

using namespace std;

int Process::rr(string fileName, int quanta){

  process *p = new process[PC];
  queue<int> readyQueue;
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
  printf("************* Scheduling algorithm : RR ********************\n");
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
  readyQueue.push(0);
  p[0].inQueue = true;
  p[0].startTime = 0;

  while(!readyQueue.empty()){
    updateQueue(p, PC, quanta, readyQueue, currentTime, programsExecuted, contextSwitches);
  }

  averageTimes(aveWaitTime, aveBurstTime, aveTurnAround, p);

  printResults(p, PC);
  
  cout << "\nAverage CPU burst time: " << aveBurstTime << " ms" << endl;
  cout << "Average wait time:  " << aveWaitTime << " ms" << endl;
  cout << "Average turn around time: " << aveTurnAround << " ms" << endl;
  cout << "Total No. of Context Switches performed: " << contextSwitches << endl;

return 0;
}

/*
 With each iteration, remaining burst times are checked against the quanta. 
 The process at the front of the queue is popped off the front
*/
void Process::updateQueue(process p[], int n, int quanta, queue<int> &readyQueue, int &currentTime, int &programsExecuted, int &contextSwitches){
  int i = readyQueue.front();
  readyQueue.pop();
  contextSwitches++;

  // If process is completed within given quanta burst,
  // calculate time values and give next process the CPU
  if(p[i].burstTimeRemaining <= quanta && p[i].burstTimeRemaining > 0){
    p[i].processStatus = "Complete";
    currentTime += p[i].burstTimeRemaining;
    p[i].timeCompleted = currentTime;
    p[i].waitTime = ( p[i].timeCompleted - p[i].arrival - p[i].burstTime );

    if(p[i].waitTime < 0){
      p[i].waitTime = 0;
    };
    
    p[i].turnAround = ( p[i].waitTime + p[i].burstTime );
    p[i].burstTimeRemaining = 0;

    // Printing top half of Gantt chart.
    printf("%*c%d",(p[i].startTime), 'P', i+1);

    // If the amount of processes executed is less than amount of processes,
    // check for new arrivals.
    if(programsExecuted != n){
      checkNewArrivals(p, n, currentTime, readyQueue);
    }
  }
  else{
      // If process isn't finished, calculate remaining time.
      // Increment No. of context switches
      // Check for new arrivals.
      // Push unfinished process to back of queue.
      p[i].burstTimeRemaining -= quanta;
      currentTime += quanta;
      p[i].processStatus = "In Process";
      p[i].contextSwitches++;
      p[i+1].startTime = currentTime;

      printf("%*c%d",(p[i].startTime), 'P', i+1);

      if(programsExecuted != n){
        checkNewArrivals(p, n, currentTime, readyQueue);
      };
      readyQueue.push(i);
    };
    
};

// Check to see if any process arrived during the execution of another.
// If so, push process to back of queue. 
void Process::checkNewArrivals(process p[], const int n, const int &currentTime, queue<int> &readyQueue){
  for(int i = 0; i < n; i++){
    process proc = p[i];

    if(proc.arrival <= currentTime && !proc.inQueue && proc.processStatus != "Complete"){
      p[i].processStatus = "New Process";
      p[i].inQueue = true;
      readyQueue.push(i);
    }
  }

};

