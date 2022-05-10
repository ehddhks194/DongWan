//Created by dongwan-kim on 2022/04/14.
#include<iostream>
#include<string>
using namespace std;

int n;
class Queue{
public:
    int queuesize;
    int arr[10000];
    int frontIdx;
    int rearIdx;

    Queue(){
        arr[10000]={};
        queuesize=0;
        frontIdx=0;
        rearIdx=0;
    }

    void updateidx(){
        frontIdx %= n;
        rearIdx  %= n;
    }

    bool isEmpty(){
        if(queuesize==0)
            return true;
        else
            return false;
    }

    void size(){
        cout<<queuesize<<endl;
    }

    void front(){
        if(isEmpty())
            cout<<"Empty"<<endl;
        else
            cout<<arr[frontIdx]<<endl;
    }

    void rear(){
        if(isEmpty())
            cout<<"Empty"<<endl;
        else
            cout<<arr[rearIdx-1]<<endl;
    }

    void enqueue(int v){
        if(queuesize>=n)
            cout<<"Full"<<endl;
        else{
            arr[rearIdx]=v;
            rearIdx++;
            updateidx();
            queuesize++;
        }
    }

    void dequeue(){
        if(isEmpty())
            cout<<"Empty"<<endl;
        else{
            cout<<arr[frontIdx]<<endl;
            frontIdx++;
            updateidx();
            queuesize--;
        }
    }
};

int main(){
    int t;
    cin>>n>>t;
    Queue q;
    while(t--){
        string cmd;
        cin>>cmd;
        if(cmd=="isEmpty"){
            if(q.isEmpty())
                cout<<"True"<<endl;
            else
                cout<<"False"<<endl;
        }
        else if(cmd=="size"){
            q.size();
        }
        else if(cmd=="enqueue"){
            int a;
            cin>>a;
            q.enqueue(a);
        }
        else if(cmd=="dequeue"){
            q.dequeue();
        }
        else if(cmd=="front"){
            q.front();
        }
        else if(cmd=="rear"){
            q.rear();
        }
    }
}

