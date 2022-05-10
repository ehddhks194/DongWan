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

class Queue{
public:
    int size;
    Node *head;
    Node *tail;

    Queue(){
        head=new Node;
        tail=new Node;
        size=0;
        head->next=tail;
        tail->pre=head;
    }

    void Size(){
        cout<<size<<endl;
    }

    bool isEmpty(){
        if(size==0)
            return true;
        else
            return false;
    }

    void front(){
        if(isEmpty())
            cout<<"Empty"<<endl;
        else{
            cout<<head->next->value<<endl;
        }
    }

    void rear(){
        if(isEmpty())
            cout<<"Empty"<<endl;
        else{
            cout<<tail->pre->value<<endl;
        }
    }

    void enqueue(int v){
        Node *newNode=new Node;
        newNode->value=v;
        newNode->next=tail;
        newNode->pre=tail->pre;
        tail->pre->next=newNode;
        tail->pre=newNode;
        size++;
    }

    void dequeue(){
        if(isEmpty())
            cout<<"Empty"<<endl;
        else{
            cout<<head->next->value<<endl;
            head->next=head->next->next;
            size--;
        }
    }
};


int main(){
    int t;
    cin>>t;
    Queue q;
    while(t--){
        string cmd;
        cin>>cmd;
        if(cmd=="size"){
            q.Size();
        }
        else if(cmd=="isEmpty"){
            if(q.isEmpty())
                cout<<"True"<<endl;
            else
                cout<<"False"<<endl;
        }
        else if(cmd=="front"){
            q.front();
        }
        else if(cmd=="rear"){
            q.rear();
        }
        else if(cmd=="enqueue"){
            int a;
            cin>>a;
            q.enqueue(a);
        }
        else if(cmd=="dequeue"){
            q.dequeue();
        }
    }
}