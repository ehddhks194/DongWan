//
// Created by dongwan-kim on 2022/04/22.
//
#include<iostream>
using namespace std;

class Node{
public:
    int value;
    Node *next;

    Node(){
        next= nullptr;
        value=0;
    }
};

class Single{
public:
    int size;
    Node *head;
    Node *tail;

    Single(){
        size=0;
        head=new Node;
        tail= nullptr;
        head->next=tail;
    }

    bool empty(){
        if(size==0)
            return true;
        else
            return false;
    }

    void Print(){
        if(empty())
            cout<<"empty"<<endl;
        else{
            Node *curNode=head->next;
            for(int i=0;i<size;i++){
                cout<<curNode->value<<" ";
                curNode=curNode->next;
            }
            cout<<endl;
        }
    }

    void Append(int x){
        Node *newNode=new Node;
        newNode->value=x;
        if(empty()){
            head->next=newNode;
            tail=newNode;
        }
        else{
            Node *curNode=head;
            for(int i=0;i<size;i++){
                curNode=curNode->next;
            }
            curNode->next=newNode;
            tail=newNode;
        }
        size++;
        Print();
    }

    void Delete(int idx){
        if(empty()||idx>=size)
            cout<<-1<<endl;
        else{
            Node *curNode=head;
            for(int i=0;i<idx;i++){
                curNode=curNode->next;
            }
            Node *deleteNode=curNode->next;
            curNode->next=deleteNode->next;
            cout<<deleteNode->value<<endl;
            size--;
        }
    }

    void Insert(int idx,int x){
        if(idx>size)
            cout<<"Index Error"<<endl;
        else{
            Node *curNode=head;
            for(int i=0;i<idx;i++){
                curNode=curNode->next;
            }
            Node *newNode=new Node;
            newNode->value=x;
            newNode->next=curNode->next;
            curNode->next=newNode;
            size++;
            Print();
        }
    }

    void Sum(){
        int sum=0;
        Node *curNode=head->next;
        for(int i=0;i<size;i++){
            sum += curNode->value;
            curNode=curNode->next;
        }
        cout<<sum<<endl;
    }
};

int main(){
    int m;
    cin>>m;
    Single s;
    while(m--){
        string cmd;
        cin>>cmd;
        if(cmd=="Print"){
            s.Print();
        }
        else if(cmd=="Append"){
            int a;
            cin>>a;
            s.Append(a);
        }
        else if(cmd=="Delete"){
            int a;
            cin>>a;
            s.Delete(a);
        }
        else if(cmd=="Insert"){
            int a,b;
            cin>>a>>b;
            s.Insert(a,b);
        }
        else if(cmd=="Sum"){
            s.Sum();
        }
    }
}