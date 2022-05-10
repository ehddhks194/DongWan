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

    void convolution(Iterator &p){
        int n1=p.node->pre->data;
        int n2=p.node->data;
        int n3=p.node->next->data;

        cout<<n1*1+3*n2+1*n3<<" ";
    }
};


int main(){
    int t;
    cin>>t;

    for(int i=0;i<t;i++){
        Sequence seq;
        Iterator p = Iterator(seq.begin());
        int n;
        cin>>n;
        for(int j=0;j<n;j++){
            int k;
            cin>>k;
            seq.insert(p,k);
        }
        p=seq.begin();

        for(int j=0;j<n;j++){
            seq.convolution(p);
            ++p;
        }
        cout<<endl;
    }
    return 0;
}