// Created by dongwan-kim on 2022/04/11.
#include<iostream>
#include<string>
using namespace std;

class node{
public:
    node* next;
    int value;
    node(){
        value=0;
        next= nullptr;
    }
};

class Stack{
public:
    node *head;
    node *tail;
    int size;

    Stack(){
        head=tail= nullptr;
        size=0;
    }

    bool empty(){
        if(size==0)
            return true;
        else
            return false;
    }

    void top(){
        if(empty())
            cout<<-1<<endl;
        else{
            cout<<tail->value<<endl;
        }
    }

    void push(int x){
        node *newNode = new node;
        newNode->value=x;
        if(empty()){
            head=tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
        size++;
    }

    void pop(){
        if(empty())
            cout<<-1<<endl;
        else{
            top();
            node* curNode=head;
            if(size==1){
                head=tail= nullptr;
            }
            else {
                while (curNode->next != tail) {
                    curNode = curNode->next;
                }
                tail = curNode;
            }
            size--;
        }
    }
};

int main(){
    int n;
    cin>>n;

    Stack st;
    for(int i=0;i<n;i++){
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