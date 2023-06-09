#ifndef PROCESS
#define PROCESS

#include <string>
#include <vector>
#include <queue>

class Process{
    public: 
        // Process object struct
        struct process{
            int pidNum;
            int arrival;
            int burstTime;
            int burstTimeRemaining;
            int timeCompleted = 0;
            int startTime = 0;
            int waitTime = 0;
            int turnAround = 0;
            std::string processStatus;
            bool inQueue = false;
            int contextSwitches = 0;
        };  

        // Process count.
        int PC = 4;

        // Scheduling algorithm declarations.
        int rr(std::string fileName, int quanta);
        int srtf(std::string fileName);
        int fcfs(std::string fileName);

        void updateQueue(process p[], int n, int quanta, std::queue<int> &readyQueue, int &currentTime, int &programsExecuted, int &contextSwitches);
        void updateVQueue(process p[], int n, int &currentTime, int &programsExecuted, int &contextSwitches);
        
        void checkNewArrivals(process p[], const int n,  const int &currentTime, std::queue<int> &readyQueue);
        
        void averageTimes(float &aveWaitTime, float &aveBurstTime, float & aveTurnAround, process p[]);

        void printResults(process p[], int n);
};

#endif
