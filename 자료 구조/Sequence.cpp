#include<iostream>
#include<string>
using namespace std;

struct Node{
private:
    Node* pre;
    Node* next;
    int data;
public:
    Node(){
        pre= nullptr;
        next= nullptr;
        data=0;
    }

    friend class Iterator;
    friend class Sequence;
};

class Iterator{
    Node* node;
public:
    Iterator(){
        node= nullptr;
    }
    Iterator(Node* n) {
        node = n;
    }

    Iterator* operator++(){
        node=node->next;
        return this;
    }

    Iterator* operator--(){
        node=node->pre;
        return this;
    }

    friend class Sequence;
};

class Sequence{
private:
    Node* head;
    Node* tail;
    int size;
public:
    Sequence(){
        head=new Node;
        tail=new Node;
        head->next=tail;
        tail->pre=head;
        size=0;
    }

    Node* begin(){
        return head->next;
    }

    Node* end(){
        return tail;
    }

    void insert(Iterator &p,int e){
        Node* newNode=new Node;
        newNode->data=e;

        p.node->pre->next=newNode;
        newNode->pre=p.node->pre;

        newNode->next=p.node;
        p.node->pre=newNode;

        size++;
    }

    void erase(Iterator &p){
        if(size==0){
            cout<<"Empty"<<endl;
        }
        else{
            Node* deleteNode=p.node;

            deleteNode->pre->next=deleteNode->next;
            deleteNode->next->pre=deleteNode->pre;

            p.node=begin();
            delete deleteNode;
            size--;
        }
    }

    void print(){
        if(size==0)
            cout<<"Empty"<<endl;
        else{
            Node* curNode=head->next;
            for(int i=0;i<size;i++){
                cout<<curNode->data<<" ";
                curNode=curNode->next;
            }
            cout<<endl;
        }
    }

    void find(int e){
        if(size==0)
            cout<<"Empty"<<endl;
        else{
            Node* curNode=head->next;
            int index=0;
            for(int i=0;i<size;i++){
                if(curNode->data==e){
                    cout<<index<<endl;
                    break;
                }
                else{
                    curNode=curNode->next;
                    index++;
                }
            }
            if(index==size)
                cout<<-1<<endl;
        }
    }
};


int main(){
    int m;
    cin>>m;

    Sequence seq;
    Iterator p = Iterator(seq.begin());

    for(int i=0;i<m;i++){
        string opr;
        cin>>opr;
        if(opr=="begin")
            p=seq.begin();
        else if(opr=="end")
            p=seq.end();
        else if(opr=="insert"){
            int a;
            cin>>a;
            seq.insert(p,a);
        }
        else if(opr=="erase")
            seq.erase(p);
        else if (opr=="++")
            ++p;
        else if (opr=="--")
            --p;
        else if (opr=="print")
            seq.print();
        else if (opr=="find") {
            int a;
            cin >> a;
            seq.find(a);
        }
    }
}