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

int main(int argc, char *argv[]){

  string fileName = argv[0];
  string schedule = argv[1];
  char *q = argv[2];
  int quantum = int(*q);

  transform(schedule.begin(), schedule.end(), schedule.begin(), ::toupper);

  if(schedule == "RR"){
    rr(fileName, quantum);

  } else if(schedule == "FCFS"){
    cout << "Hello." << endl;
    fcfs(fileName);

  } else if(schedule == "SRTF"){
    srtf(fileName);

  } else {
    cout << "Process schedule unknown." << endl;
  };
  
  return 0;
};