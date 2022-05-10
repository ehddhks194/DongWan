//Created by dong wan-kim on 2022/04/21.
#include<iostream>
#include<string>
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

class DoubleLinkedList{
public:
    int size;
    Node *p;
    Node *head;
    Node *tail;

    DoubleLinkedList(){
        head=new Node;
        tail=new Node;
        head->next=tail;
        tail->pre=head;
        p=head->next;
        size=0;
    }

    void begin(){
        p=head->next;
    }

    void end(){
        p=tail;
    }

    bool empty(){
        if(size==0)
            return true;
        else
            return false;
    }

    void insert(int v){
        Node *newNode=new Node;
        newNode->value=v;
        p->pre->next=newNode;
        newNode->pre=p->pre;
        newNode->next=p;
        p->pre=newNode;
        size++;
    }

    void erase(){
        if(empty())
            cout<<"Empty"<<endl;
        else if(p != tail){
            Node *deleteNode=p;
            deleteNode->pre->next=deleteNode->next;
            deleteNode->next->pre=deleteNode->pre;
            delete deleteNode;
            begin();
            size--;
        }
    }

    void nextP(){
        if(p != tail)
            p=p->next;
    }

    void prevP(){
        if(p != head->next)
            p=p->pre;
    }

    void print(){
        if(empty())
            cout<<"Empty";
        else{
            Node *curNode=head;
            for(int i=0;i<size;i++){
                curNode=curNode->next;
                cout<<curNode->value<<" ";
            }
        }
        cout<<endl;
    }

    void find(int v){
        Node *curNode=head;
        int k=0;
        for(int i=0;i<size;i++){
            curNode=curNode->next;
            if(curNode->value==v) {
                cout << i << " ";
                k++;
            }
        }
        if(k==0)
            cout<<-1;
        cout<<endl;
    }
};

int main(){
    int t;
    cin>>t;
    DoubleLinkedList d;
    while(t--){
        string cmd;
        cin>>cmd;
        if(cmd=="begin"){
            d.begin();
        }
        else if(cmd=="find"){
            int a;
            cin>>a;
            d.find(a);
        }
        else if(cmd=="end"){
            d.end();
        }
        else if(cmd=="insert"){
            int a;
            cin>>a;
            d.insert(a);
        }
        else if(cmd=="erase"){
            d.erase();
        }
        else if(cmd=="nextP"){
            d.nextP();
        }
        else if(cmd=="prevP"){
            d.prevP();
        }
        else if(cmd=="print"){
            d.print();
        }
    }
}