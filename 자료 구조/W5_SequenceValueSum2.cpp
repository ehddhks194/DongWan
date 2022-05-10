// Created by dongwan-kim on 2022/04/21.
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

class Sequence{
public:
    int size;
    Node *head;
    Node *tail;
    Node *p;

    Sequence(){
        size=0;
        head=new Node;
        tail=new Node;
        head->next=tail;
        tail->pre=head;
        p=head->next;
    }

    void insert(int v){
        Node *newNode=new Node;
        newNode->value=v;

        newNode->pre=p->pre;
        newNode->next=p;
        p->pre->next=newNode;
        p->pre=newNode;
        size++;
    }

    void sum(){
        int sum=0;
        Node *curNode=head->next;
        for(int i=0;i<size;i++){
            sum += curNode->pre->value;
            sum += curNode->value;
            sum += curNode->next->value;
            cout<<sum<<" ";
            curNode=curNode->next;
            sum=0;
        }
        cout<<endl;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        Sequence s;
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            s.insert(a);
        }
        s.sum();
    }
}