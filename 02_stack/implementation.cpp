#include<bits/stdc++.h>
using namespace std;

class Stack{

    public:
    int *arr;
    int s;
    int top;

    Stack(int size){
        s=size;
        arr=new int[s];
        top=-1;

    }

    void push(int data){
        if(top+1<s){
            top++;
            arr[top]=data;
        }else{
            cout<<"stack overflow!"<<endl;
        }
    }

    void pop(){

        if(top>-1){
            top--;
        }else{
            cout<<"stack underflow!"<<endl;
        }
    }

    int peek(){
        if(top!=-1 && top<+1 !=s){
            return arr[top];
        }else{
            return -1;
        }
    }
    void printStack(){
        while(top!=-1){
            cout<<arr[top--]<<" ";
        }
    }
};

int main(){

    Stack *st=new Stack(5);


    st->push(1);
    st->push(2);
    st->push(3);
    st->push(4);
    st->push(5);
    st->pop();
    st->pop();
    cout<<st->peek()<<endl;
    st->printStack();
    
}