/*
  Wesley B Johnson
  Due date: April 04, 2023
*/

#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Process.hpp"

using namespace std;

int main(int argc, char *argv[]){

  string fileName = argv[1];
  string schedule = argv[2];

  Process procObj;
  
  transform(schedule.begin(), schedule.end(), schedule.begin(), ::toupper);

  if(schedule == "RR"){
    char *q = argv[3];
    int quanta = atoi(q);
    procObj.rr(fileName, quanta);

  } else if(schedule == "FCFS"){
    procObj.fcfs(fileName);

  } else if(schedule == "SRTF"){
    procObj.srtf(fileName);

  } else {
    cout << "Process schedule unknown." << endl;
  };
  
  return 0;
};