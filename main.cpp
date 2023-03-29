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

  string fileName = argv[1];
  string schedule = argv[2];
  
  transform(schedule.begin(), schedule.end(), schedule.begin(), ::toupper);

  if(schedule == "RR"){
    char *q = argv[3];
    int quanta = int(*q);
    rr(fileName, quanta);

  } else if(schedule == "FCFS"){
    fcfs(fileName);

  } else if(schedule == "SRTF"){
    srtf(fileName);

  } else {
    cout << "Process schedule unknown." << endl;
  };
  
  return 0;
};