// Created by dongwan-kim on 2022/04/12.
#include<iostream>
#include<vector>
using namespace std;

int t,n;
vector<int>nodev;
vector<int>nodedepth;

class Node{
public:
    Node* parent;
    int value;
    vector<Node*> childList;

    Node(){
        value=0;
        parent= nullptr;
    }

    Node(Node* p,int v){
        value=v;
        parent=p;
    }
};

class Tree{
public:
    Node *root;

    Tree(){
        root=new Node();
    }
    void postOrderTraversal(Node *r){
        for(int i=0;i<r->childList.size();i++){
            postOrderTraversal(r->childList[i]);
        }

        cout<<r->value<<" ";
    }

    void makeTree(){
        int depth=-1;
        Node *curNode=root;
        for(int i=0;i<n;i++){
            if(nodedepth[i]==0){
                root->value=1;
                depth=nodedepth[i];
                curNode=root;
            }
            else{
                if(nodedepth[i]>depth){
                    Node *newNode=new Node(curNode,nodev[i]);
                    curNode->childList.push_back(newNode);
                    curNode=newNode;
                }
                else if(nodedepth[i]==depth){
                    Node *newNode=new Node(curNode->parent,nodev[i]);
                    curNode->parent->childList.push_back(newNode);
                    curNode=newNode;
                }
                else if(nodedepth[i]<depth){
                    while(depth!=nodedepth[i]){
                        curNode=curNode->parent;
                        depth--;
                    }
                    Node *newNode=new Node(curNode->parent,nodev[i]);
                    curNode->parent->childList.push_back(newNode);
                    curNode=newNode;
                }
            }
            depth=nodedepth[i];
        }
    }
};


int main(){

    cin>>t;
    while(t--){
        nodedepth.clear();
        nodev.clear();
        Tree tree;
        cin>>n;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            nodev.push_back(a);
        }

        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            nodedepth.push_back(a);
        }
        tree.makeTree();
        tree.postOrderTraversal(tree.root);
        cout<<endl;
    }
}


