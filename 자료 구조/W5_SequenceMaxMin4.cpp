// Created by dongwan-kim on 2022/04/21.
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

    void maxMin(){
        Node *newNode=head->next;
        for(int i=0;i<size;i++){
            int max=-1;
            int min=101;
            int p=newNode->pre->value;
            int c=newNode->value;
            int n=newNode->next->value;

            if(p!=0&&p>max)
                max=p;
            if(p!=0&&p<min)
                min=p;
            if(c!=0&&c>max)
                max=c;
            if(c!=0&&c<min)
                min=c;
            if(n!=0&&n>max)
                max=n;
            if(n!=0&&n<min)
                min=n;

            cout<<max-min<<" ";
            newNode=newNode->next;
        }
        cout<<endl;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        Sequence s;
        int b;
        cin>>b;
        for(int i=0;i<b;i++){
            int a;
            cin>>a;
            s.insert(a);
        }
        s.maxMin();
    }
}