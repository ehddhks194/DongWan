// Created by dongwan-kim on 2022/04/22.
#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    Node *parent;
    int value;
    int depth;
    vector<Node*> childList;

    Node(){
        parent= nullptr;
        value=0;
        depth=0;
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
        newNode->depth=parentNode->depth+1;
        parentNode->childList.push_back(newNode);
        nodeList.push_back(newNode);
    }

    void depth(int v){
        Node *curNode= findNode(v);
        cout<<curNode->depth<<endl;
    }
};

int main(){
    int n,m;
    cin>>n>>m;
    n--;
    Tree tree;
    while(n--){
        int a,b;
        cin>>a>>b;
        tree.insert(a,b);
    }
    while(m--){
        int a;
        cin>>a;
        tree.depth(a);
    }
}


