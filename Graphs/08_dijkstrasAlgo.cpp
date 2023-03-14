// find the sortest path between node from the source node.

#include <bits/stdc++.h>
using namespace std;
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int src)
{

    // create adj list
    unordered_map<int, list<pair<int, int>>> adj;

    for (int i = 0; i < edges; i++)
    {

        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // create a distance DS
    vector<int> dist(vertices);

    for (int i = 0; i < vertices; i++)
    {
        dist[i] = INT_MAX;
    }

    dist[src] = 0;
    // create a set
    set<pair<int, int>> st;
    st.insert({0, src});

    while (!st.empty())
    {

        // take front node
        auto top = *(st.begin());
        int nodeDist = top.first;
        int topNode = top.second;

        st.erase(st.begin());

        // traverse the neighbour
        for (auto nbr : adj[topNode])
        {

            if (nodeDist + nbr.second < dist[nbr.first])
            {

                auto record = st.find({dist[nbr.first], nbr.first});

                if (record != st.end())
                {
                    st.erase(record);
                }

                // update the distance
                dist[nbr.first] = nodeDist + nbr.second;
                st.insert({dist[nbr.first], nbr.first});
            }
        }
    }
    return dist;
}

int main(){
    
}