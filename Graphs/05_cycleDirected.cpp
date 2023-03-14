// check cycle is present in directed graph or not
#include <bits/stdc++.h>
using namespace std;

bool solve(int node, unordered_map<int, set<int>> &adj, unordered_map<int, bool> &visited, unordered_map<int, bool> dfsVisited)
{

    visited[node] = true;
    dfsVisited[node] = true;

    for (auto nbr : adj[node])
    {
        if (!visited[nbr])
        {
            bool isCycle = solve(nbr, adj, visited, dfsVisited);
            if (isCycle)
            {
                return true;
            }
        }
        else if (dfsVisited[nbr])
        {
            return true;
        }
    }

    dfsVisited[node] = false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    // Write your code here.

    unordered_map<int, set<int>> adj;

    for (int i = 0; i < edges.size(); i++)
    {

        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].insert(v);
    }

    // do dfs
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            bool isCycle = solve(i, adj, visited, dfsVisited);
            if (isCycle)
            {
                return true;
            }
        }
    }
    return 0;
}

int main(){
    
}