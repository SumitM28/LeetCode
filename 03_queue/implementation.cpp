// implementation of queue
#include<bits/stdc++.h>
using namespace std;


// using arr
class Queue{

    private:
    int *arr;
    int top;
    int rear;
    int s;

    public:

    Queue(int size){
        s=size;
        arr=new int[s];
        top=0;
        rear=0;
    }

    void Enqueue(int data){
        if(rear==s){
            cout<<"Queue is overflow!";
            return;
        }
        arr[rear++]=data;
        
    }

    int Dequeue(){
        if(top==rear){
            return -1;
        }
        int data=arr[top];
        for(int i=0;i<=rear;i++){
            arr[i]=arr[i+1];
        }
        rear--;
        return data;
    }


    int peek(){
        return arr[top];
    }

    bool isEmpty(){

        return (top==rear)?1:0;
    }

};


int main(){

    Queue *q=new Queue(5);


    q->Enqueue(1);
    q->Enqueue(2);
    q->Enqueue(3);
    q->Enqueue(4);

    cout<<q->Dequeue()<<endl;
    cout<<q->peek()<<endl;
}