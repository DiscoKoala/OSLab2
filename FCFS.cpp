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
#include "Process.hpp"

using namespace std;

int Process::fcfs(string fileName){

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
        p[i] = obj;
        i++;
    };
    fin.close();

    totalTime = totalTime + p[0].arrival;
    p[0].startTime = 0;

    // Calculate required time values.
    for(i = 0; i < PC; i++){
      totalTime = totalTime + p[i].burstTime;
      p[i].timeCompleted = totalTime;
      p[i].turnAround = p[i].timeCompleted - p[i].arrival;
      p[i].waitTime = p[i].turnAround - p[i].burstTime;
      p[i+1].startTime = p[i].timeCompleted;

      // Print top half of Gantt chart.
      printf("%*c%d",(p[i].startTime), 'P', i+1);

      // If next process arrives after previous finished,
      // calculated difference between finish time and arrival time.
      // Add difference to total time passed.
      if(totalTime < p[i+1].arrival){
        int t = p[i+1].arrival - totalTime;
        totalTime = totalTime + t;
      };
    };

    // Calculate averages.
    averageTimes(aveWaitTime, aveBurstTime, aveTurnAround, p);

    printResults(p, PC);

    cout << "\nAverage CPU burst time: " << aveBurstTime << " ms" << endl;
    cout << "Average wait time:  " << aveWaitTime << " ms" << endl;
    cout << "Average turn around time: " << aveTurnAround << " ms" << endl;
    cout << "Total No. of Context Switches performed: 0" << " ms" << endl;

  return 0;
}

// 
void Process::printResults(process p[], int n){

  // Bottom half of Gantt chart.
  printf("\n* * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");  

  // Display table.
  printf("pid  arrival  CPU-burst  finish  waiting time  turn around  No.of context\n");  
  for(int i = 0; i < n; i++){
    printf("%-2d   %-2d       %-2d         %-2d      %-2d            %-2d           %-2d\n",
            p[i].pidNum,
            p[i].arrival,
            p[i].burstTime,
            p[i].timeCompleted,
            p[i].waitTime,
            p[i].turnAround,
            p[i].contextSwitches
          );
  }
};