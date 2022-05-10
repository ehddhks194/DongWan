//Created by dongwan-kim on 2022/04/11.
#include<iostream>
#include<string>
using namespace std;


class Node{
public:
    Node *next;
    int value;

    Node() {
        next = nullptr;
        value = 0;
    }
};

class SingleLinkedList{
public:
    Node *head;
    Node *tail;
    int listSize;

    SingleLinkedList(){
        head= nullptr;
        tail= nullptr;
        listSize=0;
    }

    bool empty(){
        if(listSize==0)
            return true;
        else
            return false;
    }

    void print(){
        Node *curNode = head;
        if(empty()) {
            cout << "empty";
        }
        else{
            for(int i=0;i<listSize;i++){
                cout<<curNode->value<<" ";
                curNode=curNode->next;
            }
            cout<<endl;
        }
    }

    void Append(int x){
        Node *newNode=new Node;
        newNode->value=x;
        newNode->next= nullptr;

        if(empty()){
            head=tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
        listSize++;
        print();
    }

    int Delete(int idx){
        if(empty()||idx>=listSize)
            return -1;
        Node *curNode=head;
        if(idx==0){
            if(listSize==1){
                head=tail= nullptr;
            }
            else{
                head=head->next;
            }
        }
        else{
            Node *preNode=head;
            for(int i=1;i<idx;i++){
                preNode=preNode->next;
            }
            curNode=preNode->next;
            preNode->next = curNode->next;
            if(curNode==tail) {
                tail = preNode;
            }
        }
        int k=curNode->value;
        delete curNode;
        listSize--;
        return k;
    }

    void Insert(int idx, int v){
        if(idx>listSize)
            cout<<"Index error"<<endl;
        else{
            if(idx==listSize)
                Append(v);
            else if(idx==0){
                Node *newNode=new Node;
                newNode->value=v;
                newNode->next=head;
                head=newNode;
                listSize++;
            }
            else{
                Node *newNode=new Node;
                newNode->value=v;
                Node *curNode=head;
                for(int i=1;i<idx;i++){
                    curNode=curNode->next;
                }
                newNode->next=curNode->next;
                curNode->next=newNode;
                listSize++;
            }
            print();
        }
    }

    void sum(){
        if(empty())
            cout<<0<<endl;
        else{
            Node *curNode=head;
            int sum=0;
            for(int i=0;i<listSize;i++){
                sum += curNode->value;
                curNode=curNode->next;
            }
            cout<<sum<<endl;
        }
    }
};

int main(){
    int m;
    cin>>m;

    SingleLinkedList sl;

    while(m--){
        string cmd;
        cin>>cmd;
        if(cmd=="Print"){
            sl.print();
        }
        else if(cmd=="Append"){
            int a;
            cin>>a;
            sl.Append(a);
        }
        else if(cmd=="Delete"){
            int a;
            cin>>a;
            cout<<sl.Delete(a)<<endl;
        }
        else if(cmd=="Insert"){
            int a,b;
            cin>>a>>b;
            sl.Insert(a,b);
        }
        else if(cmd=="Sum"){
            sl.sum();
        }
    }
}