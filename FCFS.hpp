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
#include "Process.hpp"
#include "FCFS.hpp"

using namespace std;

int fcfs(string fileName){

  ifstream fin;
  int pid, arrivalTime, burstTime;
  string line;

  cout << "************************************************************" << endl;
  cout << "************ Scheduling algorithm : FCFS *******************" << endl;
  cout << "************************************************************" << endl;

  fin.open("input.txt");

  while(getline(fin, line)){
    cout << line << endl;
  };

  fin.close();
  
  return 0;
}

#endif