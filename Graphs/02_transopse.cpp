// the transpose of any directed graph is just revserse the direction of its edges

#include<bits/stdc++.h>
using namespace std;

int main(){

    // normal graphs

    map<int,list<int>>adj;
    adj[0].push_back(1);
    adj[0].push_back(3);
    adj[0].push_back(4);
    adj[2].push_back(0);
    adj[3].push_back(2);
    adj[4].push_back(3);

    cout<<"Normal graph:"<<endl<<endl;
    for(auto x:adj){
        for(auto y:x.second){
            cout<<x.first<<"-->"<<y<<endl;
        }
    }


    map<int,list<int>>tranpose;

    for(auto x:adj){
        for(auto y:x.second){
            tranpose[y].push_back(x.first);
        }
    }
    
    cout<<"Tranposed graph:"<<endl<<endl;
    for(auto x:tranpose){
        for(auto y:x.second){
            cout<<x.first<<"-->"<<y<<endl;
        }
    }
}