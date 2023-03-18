//  Gas Station
#include <bits/stdc++.h>
using namespace std;

int gasStation(vector<int> &gas, vector<int> &cost)
{

    int totalDiff = 0, n = cost.size(), fuel = 0, index = 0;

    for (int i = 0; i < n; i++)
    {
        int diff = gas[i] - cost[i];

        totalDiff += diff;
        fuel += diff;

        if (fuel < 0)
        {
            fuel = 0;
            index = i + 1;
        }
    }

    return (totalDiff < 0) ? -1 : index;
}

int main()
{
}