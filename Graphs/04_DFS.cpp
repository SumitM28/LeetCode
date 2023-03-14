// Deapth first search
#include <bits/stdc++.h>
using namespace std;

// bfs algo is a travsersal technique in which we take one node and traverse all adjajency node one by one


// approach
/*
1st create a visited DS.
2nd store in ans.
3rd make visited to node.
4th then traverse all the adjajency neigbours of the node if they are not present in visited DS then do recursive call for neighbour node.

*/


// bfs recursive
void dfs(map<int, list<int>> &adj,unordered_map<int,bool> &visited,vector<int> &ans,int node){


    ans.push_back(node);
    visited[node]=1;

    for(auto nbr:adj[node]){
        if(!visited[nbr]){
            dfs(adj,visited,ans,nbr);
        }
    }
}

// bfs iterative
void dfsIterative(map<int, set<int>> &adj,unordered_map<int,bool> &visited,vector<int> &ans,int node){

    stack<int> st;
    st.push(node);
    visited[node]=1;


    while (!st.empty())
    {
        int topNode=st.top();
        st.pop();
        ans.push_back(topNode);

        for(auto nbr:adj[topNode]){
            if(!visited[nbr]){
                st.push(nbr);
                visited[nbr]=true;
            }
        }
    }
    

}


int main()
{

    map<int, set<int>> adj;

    adj[0].insert(1);
    adj[0].insert(2);
    adj[1].insert(0);
    adj[1].insert(2);
    adj[2].insert(0);
    adj[2].insert(1);
    adj[2].insert(3);
    adj[3].insert(2);

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
            dfsIterative(adj,visited,ans,i);
        }
    }

    for(auto i:ans){
        cout<<i<<" ";
    }

}