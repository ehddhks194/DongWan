// Created by dongwan-kim on 2022/04/11.
#include<iostream>
#include<string>
using namespace std;

int t;
class Stack{
public:
    int arr[10];
    int stackSize;

    Stack(){
        stackSize=0;
        for(int i=0;i<10;i++){
            arr[i]=0;
        }
    }

    bool empty(){
        if(stackSize==0)
            return true;
        else
            return false;
    }

    void top(){
        if(empty())
            cout<<-1<<endl;
        else{
            cout<<arr[stackSize-1]<<endl;
        }
    }

    void push(int x){
        if(stackSize==t)
            cout<<"FULL"<<endl;
        else{
            arr[stackSize]=x;
            stackSize++;
        }
    }

    void pop(){
        if(empty())
            cout<<-1<<endl;
        else {
            top();
            stackSize--;
        }
    }
};

int main(){
    int n;
    cin>>t>>n;
    Stack st;

    while(n--){
        string cmd;
        cin>>cmd;
        if(cmd=="empty"){
            if(st.empty())
                cout<<1<<endl;
            else
                cout<<0<<endl;
        }
        else if(cmd=="top"){
            st.top();
        }
        else if(cmd=="push"){
            int a;
            cin>>a;
            st.push(a);
        }
        else if(cmd=="pop"){
            st.pop();
        }
    }
}


