/*
  Wesley B Johnson
  Due date: April 04, 2023
*/

#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "FCFS.hpp"
#include "RR.hpp"
#include "SRTF.hpp"

using namespace std;

int main(string fileName, string schedule, int quantum){

  transform(schedule.begin(), schedule.end(), schedule.begin(), ::toupper);

  if(schedule == "ROUNDROBIN"){
    rr(fileName, quantum);

  } else if( schedule == "FCFS"){
    fcfs(fileName);

  } else if(schedule == "SRTF"){
    srtf(fileName);

  } else {
    cout << "Process schedule unknown." << endl;
  };
  

  return 0;
};