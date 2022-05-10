// Created by dongwan-kim on 2022/04/21.
#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    int value;
    Node *parent;
    vector<Node*> childList;

    Node(){
        value=0;
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

    void insertNode(int p,int c){
        Node *parentNode=findNode(p);
        Node *newNode= new Node;
        newNode->value=c;
        newNode->parent=parentNode;
        parentNode->childList.push_back(newNode);
        nodeList.push_back(newNode);
    }

    void ancestor(int k){
        Node *curNode= findNode(k);
        while(curNode->parent!= nullptr){
            curNode=curNode->parent;
            cout<<curNode->value<<" ";
        }
        cout<<endl;
    }
};

int main(){
    int t,n;
    cin>>t>>n;
    t--;
    Tree tree;
    while(t--){
        int a,b;
        cin>>a>>b;
        tree.insertNode(a,b);
    }
    while(n--){
        int a;
        cin>>a;
        tree.ancestor(a);
    }
}