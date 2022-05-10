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
        value=0;
        next= nullptr;
        pre= nullptr;
    }
};

class Double{
public:
    int size;
    Node *head;
    Node *tail;

    Double(){
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

    void print(){
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
            tail->pre=newNode;
            newNode->next=tail;
            newNode->pre=head;
        }
        else{
            newNode->next=tail;
            tail->pre->next=newNode;
            newNode->pre=tail->pre;
            tail->pre=newNode;
        }
        size++;
        print();
    }

    void Delete(int idx){
        if(empty()||idx>=size)
            cout<<-1<<endl;
        else{
            Node *curNode=head->next;
            for(int i=0;i<idx;i++){
                curNode=curNode->next;
            }
            curNode->pre->next=curNode->next;
            curNode->next->pre=curNode->pre;
            cout<<curNode->value<<endl;
            size--;
        }
    }

    void Print_reverse(){
        if(empty())
            cout<<"empty"<<endl;
        else{
            Node *curNode=tail->pre;
            for(int i=0;i<size;i++){
                cout<<curNode->value<<" ";
                curNode=curNode->pre;
            }
        }
    }

    void Update(int x,int y){
        if(empty())
            cout<<"empty"<<endl;
        else{
            int k=0;
            Node *curNode=head->next;
            for(int i=0;i<size;i++){
                if(curNode->value==x){
                    curNode->value=y;
                    k++;
                }
                curNode=curNode->next;
            }
            if(k==0)
                cout<<"Not found"<<endl;
            else{
                print();
            }
        }
    }
};

int main(){
    int m;
    cin>>m;
    Double d;
    while(m--){
        string cmd;
        cin>>cmd;
        if(cmd=="Print"){
            d.print();
        }
        else if(cmd=="Append"){
            int a;
            cin>>a;
            d.Append(a);
        }
        else if(cmd=="Delete"){
            int a;
            cin>>a;
            d.Delete(a);
        }
        else if(cmd=="Print_reverse"){
            d.Print_reverse();
        }
        else if(cmd=="Update"){
            int a,b;
            cin>>a>>b;
            d.Update(a,b);
        }
    }
}