#ifndef ROUND
#define ROUND

#include <string.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <unistd.h>
#include <iomanip>
#include <time.h>

using namespace std;

int rr(string fileName, int quantum){

    ifstream fin;
    int pid, arrivalTime, burstTime;
    string line;

    printf("************************************************************");
    printf("************* Scheduling algorithm : RR ********************");
    printf("************************************************************");

    fin.open("input.txt");

    while(getline(fin, line)){
        cout << line << endl;
    };

    fin.close();

  return 0;
}

#endif