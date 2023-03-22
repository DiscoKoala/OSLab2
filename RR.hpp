#ifndef ROUND
#define ROUND

class Round{

    public:

        Round();
        Round(string fileName, int q);

        int rr(string fileName, int quantum);

        int quantum;
};

#endif