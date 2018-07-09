#include "pccb/chap2/greedy_scheduling.h"
#include <algorithm>

int greedy_scheduling(
    const int numJob, const int start[], const int end[])
{
    typedef std::pair<int, int> Job;
    Job jobs[100000];

    for (std::size_t i = 0; i < numJob; ++i) {
        jobs[i].first = start[i];
        jobs[i].second = end[i];
    }
    std::sort(jobs, jobs + numJob, [](const Job x, const Job y)
              { 
              return x.second < y.second;
              });

    int numTakeJob = 0;
    int endTime = 0;
    for (int i = 0; i < numJob; ++i) {
        // endTime < startTime that is after finish job
        if (endTime < jobs[i].first) {
            numTakeJob++;
            endTime = jobs[i].second;
        }
    }

    return numTakeJob;
}

int greedy_scheduling1(
    const int numJob, const int start[], const int end[])
{
    typedef std::pair<int, int> Job;
    Job jobs[100000];

    for (std::size_t i = 0; i < numJob; ++i) {
        jobs[i].first = start[i];
        jobs[i].second = end[i];
    }
    std::sort(jobs, jobs + numJob, [](const Job x, const Job y)
              { 
              return x.second < y.second;
              });

    int numTakeJob = 0;
    int i = 0;
    while (i < numJob) {
        int j = i;
        while (jobs[j].first < jobs[i].second) {
            ++j;
        }
        i = j;
        ++numTakeJob;
    }

    return numTakeJob;
}

