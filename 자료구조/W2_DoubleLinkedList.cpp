// Created by dongwan-kim on 2022/04/11.
#include<iostream>
#include<string>
using namespace std;

class Node{
public:
    Node *pre;
    Node *next;
    int value;

    Node(){
        pre= nullptr;
        next= nullptr;
        value=0;
    }
};

class DoubleLinkedList{
public:
    Node *head;
    Node *tail;
    int listSize;

    DoubleLinkedList(){
        head=tail= nullptr;
        listSize=0;
    }

    bool empty(){
        if(listSize==0)
            return true;
        else
            return false;
    }

    void print(){
        if(empty())
            cout<<"empty"<<endl;
        else{
            Node *curNode = head;
            for(int i=0;i<listSize;i++){
                cout<<curNode->value<<" ";
                curNode=curNode->next;
            }
            cout<<endl;
        }
    }

    void Append(int v){
        Node *newNode=new Node;
        newNode->value=v;
        if(empty()){
            head=tail=newNode;
        }
        else {
            tail->next = newNode;
            newNode->pre = tail;
            tail = newNode;
        }
        listSize++;
        print();
    }

    int Delete(int idx){
        if(empty()||idx>=listSize){
            return -1;
        }
        Node* deleteNode=head;
            if(idx==0){
                if(listSize==1){
                    head=tail= nullptr;
                }
                else{
                    head=head->next;
                    head->pre= nullptr;
                }
            }
            else{
                for(int i=0;i<idx;i++){
                    deleteNode=deleteNode->next;
                }
                if(deleteNode==tail){
                    tail=deleteNode->pre;
                    tail->next= nullptr;
                }
                else {
                    deleteNode->pre->next = deleteNode->next;
                    deleteNode->next->pre = deleteNode->pre;
                }
        }
            int k=deleteNode->value;
            delete deleteNode;
            listSize--;
            return k;
    }

    void print_reverse(){
        if(empty())
            cout<<"empty";
        Node *curNode=tail;
        for(int i=0;i<listSize;i++){
            cout<<curNode->value<<" ";
            curNode=curNode->pre;
        }
        cout<<endl;
    }

    void max(){
        if(empty())
            cout<<"empty"<<endl;
        Node *curNode=head;
        int max=-1;
        for(int i=0;i<listSize;i++){
            if(curNode->value>max){
                max=curNode->value;
            }
            curNode=curNode->next;
        }
        cout<<max<<endl;
    }
};

int main() {
    int m;
    cin >> m;
    DoubleLinkedList dl;

    while (m--) {
        string cmd;
        cin >> cmd;
        if (cmd == "Print") {
            dl.print();
        } else if (cmd == "Print_reverse") {
            dl.print_reverse();
        } else if (cmd == "Append") {
            int a;
            cin >> a;
            dl.Append(a);
        } else if (cmd == "Delete") {
            int a;
            cin >> a;
            cout<<dl.Delete(a)<<endl;
        } else if (cmd == "Max") {
            dl.max();
        }
    }
}