//
// Created by dongwan-kim on 2022/04/22.
//
#include<iostream>
using namespace std;

class Node{
public:
    Node *next;
    Node *pre;
    int value;

    Node(){
        next= nullptr;
        pre= nullptr;
        value=0;
    }
};

class Stack{
public:
    Node *head;
    Node *tail;
    int size;

    Stack(){
        head=new Node;
        tail=new Node;
        head->next=tail;
        tail->pre=head;
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
        if(size==0)
            cout<<-1<<endl;
        else{
            cout<<tail->pre->value<<endl;
        }
    }

    void push(int x){
        Node *newNode=new Node;
        newNode->value=x;
        newNode->next=tail;
        newNode->pre=tail->pre;
        tail->pre->next=newNode;
        tail->pre=newNode;
        size++;
    }

    void pop(){
        if(empty())
            cout<<-1<<endl;
        else{
            cout<<tail->pre->value<<endl;
            tail->pre->pre->next=tail;
            tail->pre=tail->pre->pre;
            size--;
        }
    }
};

int main(){
    int n;
    cin>>n;
    Stack s;
    while(n--){
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