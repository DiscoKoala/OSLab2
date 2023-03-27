#ifndef SHORT
#define SHORT

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "SRTF.hpp"

using namespace std;

int srtf(string fileName){

    ifstream fin;
    int pid, arrivalTime, burstTime;
    string line;

    printf("************************************************************");
    printf("************ Scheduling algorithm : SRTF *******************");
    printf("************************************************************");

    fin.open("input.txt");

    while(getline(fin, line)){
        cout << line << endl;
    };

    fin.close();
    
  return 0;
}
#endif