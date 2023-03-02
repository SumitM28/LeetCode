// graph is a non linear data structure having collection of vertices/nodes/vertex and the edege

// the graph can be represente by 2 ways
// 1st is using 2D matrix
// using linked list
// 2nd is adjacency list

#include <bits/stdc++.h>
using namespace std;

int main()
{

    // graph using 2D matrix
    // int graph[4][4] = {
    //     {0, 1, 1, 0},
    //     {1, 0, 1, 0},
    //     {1, 1, 0, 1},
    //     {0, 0, 1, 0},
    // };

    // /* output of graph
    // 0-->1
    // 0-->2
    // 1-->0
    // 1-->2
    // 2-->0
    // 2-->1
    // 2-->3
    // 3-->2
    // */
    // for (int i = 0; i < 4; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         if (graph[i][j] == 1)
    //         {
    //             cout << i << "-->" << j << endl;
    //         }
    //     }
    // }


    // usign adjacency list
    map<int,list<int>>adj;

    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);


    for(auto x:adj){
        for(auto y:x.second){
            cout<<x.first<<"-->"<<y<<endl;
        }
    }

}