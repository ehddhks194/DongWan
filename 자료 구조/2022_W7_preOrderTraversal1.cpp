// Created by dongwan-kim on 2022/04/22.
#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    Node* parent;
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
    Node* root;
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
        Node *parentNode=findNode(p);
        Node *newNode= new Node;
        newNode->value=c;
        newNode->parent=parentNode;
        newNode->depth=parentNode->depth+1;
        parentNode->childList.push_back(newNode);
        nodeList.push_back(newNode);
    }

    void preorder(Node *r){
        cout<<r->depth<<" ";
        for(int i=0;i<r->childList.size();i++){
            preorder(r->childList[i]);
        }
    }
};

int main(){
    int t,n;
    cin>>t;
    while(t--){
        Tree tree;
        cin>>n;
        n--;
        for(int i=0;i<n;i++){
            int a,b;
            cin>>a>>b;
            tree.insert(a,b);
        }
        tree.preorder(tree.root);
        cout<<endl;
    }
}