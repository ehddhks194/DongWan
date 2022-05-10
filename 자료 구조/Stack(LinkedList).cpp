#include<iostream>
#include<string>
using namespace std;

struct node{
    int data;
    node* next;
};

class SingleLinkedList{
private:
    node* head;
    node* tail;
    int listSize;
public:
    SingleLinkedList();
    bool empty();
    void append(int x);
    int deleteNode();

    friend class Stack;
};

SingleLinkedList::SingleLinkedList() {
    head= nullptr;
    tail= nullptr;
    listSize =0;
}

bool SingleLinkedList::empty() {
    if(listSize==0)
        return true;
    else
        return false;
}

void SingleLinkedList::append(int x) {
    node* newNode=new node;
    newNode->data=x;

    if(empty())
        head=tail=newNode;
    else{
        tail->next=newNode;
        tail=newNode;
    }
    listSize++;
}

int SingleLinkedList::deleteNode() {
    int value=tail->data;

    if(listSize==1){
        delete head;
        head=tail= nullptr;
    }
    else{
        node* curNode=head;
        while(curNode->next != tail){
            curNode=curNode->next;
        }
        delete curNode->next;
        curNode->next= nullptr;
        tail=curNode;
    }
    listSize--;
    return value;
}

class Stack{
private:
    SingleLinkedList ll;
    int size;
public:
    Stack();
    bool empty();
    void pop();
    void top();
    void push(int x);
};

Stack::Stack() {
    ll=SingleLinkedList();
    size=0;
}

bool Stack::empty() {
    if(size==0)
        return true;
    else
        return false;
}

void Stack::top() {
    if(empty())
        cout<<-1<<endl;
    else
        cout<<ll.tail->data<<endl;
}

void Stack::push(int x) {
    ll.append(x);
    size++;
}

void Stack::pop() {
    if(empty())
        cout<<-1<<endl;
    else{
        cout<<ll.deleteNode()<<endl;
        size--;
    }
}

int main(){
    string opr;
    int n,X;
    cin>>n;
    Stack st;

    for(int i=0;i<n;i++){
        cin>>opr;
        if(opr=="empty"){
            if(st.empty()== true)
                cout<<1<<endl;
            else
                cout<<0<<endl;
        }
        else if(opr=="top"){
            st.top();
        }
        else if(opr=="push"){
            cin>>X;
            st.push(X);
        }
        else if(opr=="pop"){
            st.pop();
        }
    }
}