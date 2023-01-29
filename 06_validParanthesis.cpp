// check the given string have valid paranthesis or not.
#include<bits/stdc++.h>
using namespace std;


bool validParanthesis(string s){
    stack<char>st;

    for(auto i: s){

        // if open bracket are present
        if(i=='(' || i=='[' || i=='{'){
            st.push(i);
        }else{

            if(st.empty() or (st.top()=='(' && i != ')') || (st.top()=='{' && i != '}')|| (st.top()=='[' && i != ']'))
                return false;
            
            st.pop();
        }
    }
    return st.empty();
}

int main(){
    string s="({[]})";
    cout<<validParanthesis(s);
}