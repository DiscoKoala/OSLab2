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
    printf("************************************************************\n\n");

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

    updateVQueue(p, PC, currentTime, programsExecuted, contextSwitches);

    averageTimes(aveWaitTime, aveBurstTime, aveTurnAround, p);
    printResults(p, PC);

  cout << "\nAverage CPU burst time: " << aveBurstTime << " ms" << endl;
  cout << "Average wait time:  " << aveWaitTime << " ms" << endl;
  cout << "Average turn around time: " << aveTurnAround << " ms" << endl;
  cout << "Total No. of Context Switches performed: " << contextSwitches << endl;
  
  return 0;
}

void Process::updateVQueue(process p[], int n, int &currentTime, int &programsExecuted, int &contextSwitches){
  int min = INT_MAX;
  int complete = 0;
  int idx = 0;
  bool check = false;

  // Loop process until all processes are completed.
  while (complete != n){

    // If a new process arrived with a shorter remaining time,
    // Preempt current process for new process.
    for(int i = 0; i < n; i++){
      if (p[i].burstTimeRemaining < min && (p[i].burstTimeRemaining > 0) && (p[i].arrival <= currentTime)){
        min = p[i].burstTimeRemaining;
        idx = i;
        check = true;
        p[i].contextSwitches++;
        p[i].startTime = currentTime;
        contextSwitches++;

        // Top half of Gantt chart.
        cout << 'P' << i+1;
      };
    };

    // If nothing arrived with a shorter remaining time, go to top of loop.
    if (check == false && complete < n){
      currentTime++;
      continue;
    };

    // Decrement remaining burst time of current process.
    p[idx].burstTimeRemaining--;
    min = p[idx].burstTimeRemaining;
    if(min == 0){
      min = INT_MAX;
    }

    // When process is finsihed, calculate time values
    if(p[idx].burstTimeRemaining == 0){
      complete++;
      check = false;

      p[idx].timeCompleted = currentTime + 1;
      p[idx].waitTime = ( p[idx].timeCompleted - p[idx].arrival - p[idx].burstTime );
      p[idx].turnAround = (p[idx].waitTime + p[idx].burstTime);

      if(p[idx].waitTime < 0){
        p[idx].waitTime = 0;
      };
    }

    // Top half of Gantt chart and increment time.
    cout << "  ";
    currentTime++;
  };
};

// Calculate averages 
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
