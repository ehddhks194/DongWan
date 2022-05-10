#include<iostream>
using namespace std;

class Node{
public:
    int value;
    Node *next;

    Node(){
        value=0;
        next= nullptr;
    }
};

class Single{
public:
    int size;
    Node *head;
    Node *tail;

    Single(){
        head= nullptr;
        tail= nullptr;
        size=0;
    }

    bool empty(){
        if(size==0)
            return true;
        else
            return false;
    }

    void print(){
        if(empty()){
            cout<<"empty"<<endl;
        }
        else {
            Node *curNode = head;
            for (int i = 0; i < size; i++) {
                cout << curNode->value << " ";
                curNode = curNode->next;
            }
            cout << endl;
        }
    }

    void Append(int x){
        Node *newNode=new Node;
        newNode->value=x;
        if(empty()){
            head=tail=newNode;
        }
        else{
            Node *curNode=head;
            while(curNode->next!= nullptr)
                curNode=curNode->next;
            curNode->next=newNode;
            tail=newNode;
        }
        size++;
        print();
    }

    void Delete(int idx){
        if(empty()||idx>=size){
            cout<<-1<<endl;
        }

        else{
            if(idx==0){
                cout<<head->value<<endl;
                head=head->next;
            }
            else {
                Node *curNode = head;
                for (int i = 1; i < idx; i++)
                    curNode = curNode->next;
                Node *deleteNode = curNode->next;
                cout << deleteNode->value<<endl;
                curNode->next = deleteNode->next;
                delete deleteNode;
            }
            size--;
        }
    }

    void insert(int idx,int x){
        if(idx>size){
            cout<<"Index Error"<<endl;
        }
        else{
            Node *curNode=head;
            for(int i=1;i<idx;i++){
                curNode=curNode->next;
            }
            Node *newNode=new Node;
            newNode->value=x;
            newNode->next=curNode->next;
            curNode->next=newNode;
            size++;
            print();
        }
    }

    void Min(){
        if(empty()){
            cout<<"empty"<<endl;
        }
        else {
            int min=head->value;
            Node *curNode = head;
            for (int i = 0; i < size; i++) {
                if (curNode->value<min)
                    min=curNode->value;
                curNode=curNode->next;
            }
            cout<<min<<endl;
        }
    }
};

int main(){
    int m;
    cin>>m;
    Single s;
    while(m--){
        string cmd;
        cin>>cmd;
        if(cmd=="Append"){
            int a;
            cin>>a;
            s.Append(a);
        }
        else if(cmd=="Print"){
            s.print();
        }
        else if(cmd=="Insert"){
            int a,b;
            cin>>a>>b;
            s.insert(a,b);
        }
        else if(cmd=="Delete"){
            int a;
            cin>>a;
            s.Delete(a);
        }
        else if(cmd=="Min"){
            s.Min();
        }
    }
}