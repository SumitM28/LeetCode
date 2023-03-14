// check weather the graph contain any negative cycle or not
#include<bits/stdc++.h>
using namespace std;




bool isNegativeDFS(int src,int parent,unordered_map<int,list<int>> &adj, unordered_map<int,int> &visited,int sum){

    visited[src]=true;

    for(auto nbr:adj[src]){
        if(!visited[nbr]){
            bool isCycle=isNegativeDFS(nbr,src,adj,visited,sum);
            if (isCycle) return true;
        }
        else if(visited[nbr] && parent!=nbr && sum<0){
            return true;
        } 
    }
    return false;
}

int main(){



}