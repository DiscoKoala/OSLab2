#ifndef ROUND
#define ROUND
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

using namespace std;

void updateQueue(process p[], int n, int quanta, queue<int> &readyQueue, int burstTime, int &programsExecuted);

void checkNewArrivals(process p[], const int n, const int currentTime, queue<int> &readyQueue);

int rr(string fileName, int quanta){

  process *p = new process[PC];
  queue<int> readyQueue;
  process obj;
  ifstream fin;
  int i = 0;
  int currentTime = 0;
  int programsExecuted = 0;


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
    obj.processStatus = "New Process";
    p[i] = obj;
    i++;
  };
  fin.close();

  readyQueue.push(0);
  p[0].inQueue = true;

  while(!readyQueue.empty()){
    updateQueue(p, PC, quanta, readyQueue, currentTime, programsExecuted);
  }
  

return 0;
}

void updateQueue(process p[], int n, int quanta, queue<int> &readyQueue, int currentTime, int &programsExecuted){
  int i = readyQueue.front();
  readyQueue.pop();

  if(p[i].burstTime <= quanta){
    p[i].processStatus = "Complete";
    currentTime += p[i].burstTimeRemaining;
    p[i].timeCompleted = currentTime;
    p[i]. waitTime = ( p[i].timeCompleted - p[i].arrival - p[i]. burstTime );
    p[i].turnAround = ( p[i].waitTime + p[i].burstTime );

    if(p[i].waitTime < 0){
      p[i].waitTime = 0;
    };

    p[i].burstTimeRemaining = 0;

    if(programsExecuted != n){
      checkNewArrivals(p, n, currentTime, readyQueue);
    }
    else{
      p[i].burstTimeRemaining -= quanta;
      currentTime += quanta;

      if(programsExecuted != n){
        checkNewArrivals(p, n, currentTime, readyQueue);
      };

      readyQueue.push(i);
    };
  };
};

void checkNewArrivals(process p[], const int n, const int currentTime, queue<int> &readyQueue){
  for(int i = 0; i < n; i++){
    process proc = p[i];

    if(proc.arrival <= currentTime && !proc.inQueue && proc.processStatus != "Complete"){
      p[i].processStatus = "New Process";
      readyQueue.push(i);
    }
  }

};


#endif