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
    vector<Node*> nodeList;
    Node *root;

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

    void insert(int x,int y){
        Node *parentNode= findNode(x);
        Node *newNode= findNode(y);
        if(newNode!= nullptr||parentNode== nullptr){
            cout<<-1<<endl;
        }
        else {
            Node *newNode=new Node;
            newNode->value = y;
            newNode->parent = parentNode;
            parentNode->childList.push_back(newNode);
            nodeList.push_back(newNode);
        }
    }

    void deleteNode(int x){
        Node *deleteNode= findNode(x);
        if(deleteNode== nullptr)
            cout<<-1<<endl;
        else {
            for (int i = 0; i < deleteNode->childList.size(); i++) {
                deleteNode->parent->childList.push_back(deleteNode->childList[i]);
                deleteNode->childList[i]->parent = deleteNode->parent;
            }
            for (int i = 0; i<deleteNode->parent->childList.size(); i++) {
                if (deleteNode->parent->childList[i] == deleteNode)
                    deleteNode->parent->childList.erase(deleteNode->parent->childList.begin() + i);
            }
            for (int i = 0; i < nodeList.size(); i++) {
                if (nodeList[i] == deleteNode)
                    nodeList.erase(nodeList.begin() + i);
            }
            delete deleteNode;
        }
    }

    void parent(int x){
        Node *childNode= findNode(x);
        if(childNode== nullptr)
            cout<<-1<<endl;
        else
            cout<<childNode->parent->value<<endl;

    }

    void child(int x){
        Node *curNode=findNode(x);
        if(curNode== nullptr||curNode->childList.empty())
            cout<<-1<<endl;
        else{
            for(int i=0;i<curNode->childList.size();i++){
                cout<<curNode->childList[i]->value<<" ";
            }
            cout<<endl;
        }
    }

    void maxChild(int x){
        Node *curNode=findNode(x);
        if(curNode== nullptr||curNode->childList.empty())
            cout<<-1<<endl;
        else{
            int max=-1;
            for(int i=0;i<curNode->childList.size();i++){
                if(curNode->childList[i]->value>max)
                    max=curNode->childList[i]->value;
            }
            cout<<max<<endl;
        }
    }
};

int main(){
    int t;
    cin>>t;
    Tree tree;
    while(t--){
        string cmd;
        cin>>cmd;
        if(cmd=="insert"){
            int a,b;
            cin>>a>>b;
            tree.insert(a,b);
        }
        else if(cmd=="parent"){
            int a;
            cin>>a;
            tree.parent(a);
        }
        else if(cmd=="child"){
            int a;
            cin>>a;
            tree.child(a);
        }
        else if(cmd=="delete"){
            int a;
            cin>>a;
            tree.deleteNode(a);
        }
        else if(cmd=="maxChild"){
            int a;
            cin>>a;
            tree.maxChild(a);
        }
    }
}
