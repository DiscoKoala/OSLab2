#ifndef SHORT
#define SHORT

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int srtf(string fileName){

    process *p = new process[PC];
    process obj;
    ifstream fin;
    int i = 0;

    printf("************************************************************");
    printf("************ Scheduling algorithm : SRTF *******************");
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