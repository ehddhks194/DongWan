//
// Created by dongwan-kim on 2022/04/22.
//
#include<iostream>
#include<array>
using namespace std;
int n;
class Stack{
public:
    int size;
    int arr[20];
    int t;

    Stack(){
        t=-1;
        size=0;
    }

    bool empty(){
        if(size==0)
            return true;
        else
            return false;
    }

    void Size(){
        cout<<size<<endl;
    }

    void top(){
        if(empty())
            cout<<-1<<endl;
        else {
            cout << arr[t] << endl;
        }
    }

    void push(int x){
        if(size==n)
            cout<<"FULL"<<endl;
        else{
            t++;
            arr[t]=x;
            size++;
        }
    }

    void pop(){
        if(empty())
            cout<<-1<<endl;
        else{
            cout<<arr[t]<<endl;
            t--;
            size--;
        }
    }
};

int main(){
    int t;
    cin>>n>>t;
    Stack s;
    while(t--){
        string cmd;
        cin>>cmd;
        if(cmd=="size"){
            s.Size();
        }
        else if(cmd=="empty"){
            if(s.empty())
                cout<<1<<endl;
            else
                cout<<0<<endl;
        }
        else if(cmd=="top"){
            s.top();
        }
        else if(cmd=="push"){
            int a;
            cin>>a;
            s.push(a);
        }
        else if(cmd=="pop"){
            s.pop();
        }
    }
}