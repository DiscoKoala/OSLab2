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

    process *p = new process[PC];
    process obj;
    ifstream fin;
    int i = 0;

    printf("************************************************************");
    printf("************* Scheduling algorithm : RR ********************");
    printf("************************************************************");

    fin.open("input.txt");

   while(true){

        if(fin.eof()){
            break;
        };

        // Read data from file into process object and add to array.
        fin >> obj.pidNum >> obj.arrival >> obj.burstTime;
        obj.processStatus = "New Process";
        p[i] = obj;
        i++;
    };

    fin.close();

  return 0;
}

#endif