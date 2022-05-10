//Created by dongwan-kim on 2022/04/13.
#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    Node* parent;
    int value;
    vector<Node*> childList;

    Node(){
        parent= nullptr;
        value=0;
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

    void insertNode(int parentv,int v){
        Node *parentNode= findNode(parentv);
        Node *newNode=new Node;
        newNode->value=v;
        newNode->parent=parentNode;
        parentNode->childList.push_back(newNode);
        nodeList.push_back(newNode);
    }

    void postOrderTraversal(Node *r){
        for(int i=0;i<r->childList.size();i++){
            postOrderTraversal(r->childList[i]);
        }
        if(r==root){
            cout<<0<<" ";
        }
        else
        cout<<r->parent->value<<" ";
    }
};

int main(){
    int t,n;
    cin>>t;
    while(t--){
        Tree tree;
        cin>>n;
        while(n--){
            int a,b;
            cin>>a>>b;
            tree.insertNode(a,b);
        }
        tree.postOrderTraversal(tree.root);
        cout<<endl;
    }
}
