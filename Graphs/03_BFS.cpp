// Breadth first search
#include <bits/stdc++.h>
using namespace std;

// bfs algo is a travsersal technique in which we take one node and traverse all adjajency node one by one


// approach
/*
1st create a visited DS.
2nd create a queue.
3rd push source node in queue.
4th mark visited = true for source node
5th traverse queue untill is not empty
6th take frontNode in front queue then pop
7th then traverse all the adjajency node of the frontnode if they are not present in visited DS then push them in queue and make true for visited

*/


// bfs
void bfs(map<int, list<int>> &adj,unordered_map<int,bool> &visited,vector<int> &ans,int node){


    // create queue
    queue<int>q;
    q.push(node);
    visited[node]=1;


    while (!q.empty())
    {
        // take frontnode
        int frontNode=q.front();
        q.pop();

        // push in ans
        ans.push_back(frontNode);


        // traverse all neibours
        for(auto nbr:adj[node]){
            if(!visited[nbr]){
                q.push(nbr);
                visited[nbr]=1;
            }
        }
    }
    
}


int main()
{

    map<int, list<int>> adj;

    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);

    for (auto x : adj)
    {
        for (auto y : x.second)
        {
            cout << x.first << "-->" << y << endl;
        }
    }


    int vertex=4;
    unordered_map<int,bool> visited(vertex);
    vector<int> ans;
    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            bfs(adj,visited,ans,i);
        }
    }

    for(auto i:ans){
        cout<<i<<" ";
    }

}