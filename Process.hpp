#ifndef PROCESS
#define PROCESS

#include <string>
#include <vector>
#include <queue>

class Process{
    public: 
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
        };  

        int PC = 10;


        int rr(std::string fileName, int quanta);
        int srtf(std::string fileName);
        int fcfs(std::string fileName);

        void updateVQueue(process p[], int n, std::vector<int> &readyQueue, int &currentTime, int &programsExecuted, int &contextSwitches);
        void checkNewArrivals(process p[], const int n,  const int &currentTime, std::vector<int> &readyQueue);
        int compareBursts(process p[], int n, std::vector<int>readyQueue);

        void updateQueue(process p[], int n, int quanta, std::queue<int> &readyQueue, int &currentTime, int &programsExecuted, int &contextSwitches);
        void checkNewArrivals(process p[], const int n,  const int &currentTime, std::queue<int> &readyQueue);
        void averageTimes(float &aveWaitTime, float &aveBurstTime, float & aveTurnAround, process p[]);
};

#endif
