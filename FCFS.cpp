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

int fcfs(){

  ifstream fin;
  int pid, arrivalTime, burstTime;

  std::cout << "************************************************************" << std::endl;
  std::cout << "************ Scheduling algorithm : FCFS *******************" << std::endl;
  std::cout << "************************************************************" << std::endl;

  fin.open("input.txt");

  return 0;
}