#include <bits/stdc++.h>
using namespace std;

#define INF 99999

void floydWarshalAlgo(int dist[][4])
{

    for (int k = 0; k < 4; k++)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {

                if (dist[i][j] > dist[i][k] + dist[k][j] && dist[i][k] != INF && dist[k][j] != INF)
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{

    int graph[][4] = {{0, 5, INF, 10},
                      {INF, 0, 3, INF},
                      {INF, INF, 0, 1},
                      {INF, INF, INF, 0}};

    floydWarshalAlgo(graph);
}