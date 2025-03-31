#include "priority_que.h"

int main()
{
    JobQueue jobQueue;

    Job jobA("This is job A", 5);
    Job jobB("This is job B", 2);
    Job jobC("This is job C", 9);
    Job jobD("This is job D", 8);
    Job jobE("This is job E", 1);

    jobQueue.insert(jobA);
    jobQueue.insert(jobB);
    jobQueue.insert(jobC);
    jobQueue.insert(jobD);
    jobQueue.insert(jobE);


    jobQueue.runHighestPriority(); // jobC (priority 9)
    jobQueue.runHighestPriority(); // jobD (priority 8)
    jobQueue.runHighestPriority(); // jobA (priority 5)
    jobQueue.runHighestPriority(); // jobB (priority 2)
    jobQueue.runHighestPriority(); // jobE (priority 1)

    return 0;
}