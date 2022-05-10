//Created by dongwan-kim on 2022/04/14.
#include<iostream>
#include<string>
using namespace std;

class Node{
public:
    Node *next;
    int value;

    Node(){
        next= nullptr;
        value=0;
    }
};

class Queue{
public:
    int queuesize;
    Node *head;
    Node *tail;

    Queue(){
        queuesize=0;
        head= nullptr;
        tail= nullptr;
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
            cout<<head->value<<endl;
    }

    void rear(){
        if(isEmpty())
            cout<<"Empty"<<endl;
        else
            cout<<tail->value<<endl;
    }

    void enqueue(int v){
        Node *newNode=new Node;
        newNode->value=v;
        if(isEmpty()){
            head=tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
        queuesize++;
    }

    void dequeue(){
        if(isEmpty())
            cout<<"Empty"<<endl;
        else{
            Node *deleteNode=head;
            head=deleteNode->next;
            cout<<deleteNode->value<<endl;
            delete deleteNode;
            queuesize--;
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
