// Created by dongwan-kim on 2022/04/22.
#include<iostream>
#include<vector>
using namespace std;
int sum=0;
class Node{
public:
    int value;
    int data;
    vector<Node*> childList;
    Node *parent;

    Node(){
        value=0;
        data=0;
        parent= nullptr;
    }
};

class Tree{
public:
    Node *root;
    vector<Node*> nodeList;

    Tree(){
        root=new Node;
        root->value=1;
        nodeList.push_back(root);
    }

    Node *findNode(int v){
        for(int i=0;i<nodeList.size();i++){
            if(nodeList[i]->value==v)
                return nodeList[i];
        }
        return nullptr;
    }

    void insert(int p,int c){
        Node *parentNode= findNode(p);
        Node *newNode=new Node;
        newNode->value=c;
        newNode->parent=parentNode;
        parentNode->childList.push_back(newNode);
        nodeList.push_back(newNode);
    }

    void datainsert(int v, int d){
        Node *curNode= findNode(v);
        curNode->data=d;
    }

    int sumPreOrder(Node *r){
        sum += r->data;

        for(int i=0;i<r->childList.size();i++){
            sumPreOrder(r->childList[i]);
        }
        return sum;
    }
};

int main(){
    int n,m;
    cin>>n>>m;
    Tree tree;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        tree.insert(a,b);
    }
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        tree.datainsert(a,b);
    }
    while(m--){
        int a;
        cin>>a;
        cout<<tree.sumPreOrder(tree.findNode(a))<<endl;
        sum=0;
    }
}