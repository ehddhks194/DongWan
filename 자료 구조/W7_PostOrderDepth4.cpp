//Created by dongwan-kim on 2022/04/13.
#include<iostream>
#include<vector>
using namespace std;

vector<int> nodeV;
vector<int> nodeD;
int t,n;

class Node{
public:
    Node *parent;
    int value;
    vector<Node*> childList;

    Node(){
        parent= nullptr;
        value=0;
    }

    Node(Node *parentN,int V){
        parent=parentN;
        value=V;
    }
};

class Tree{
public:
    Node *root;

    Tree(){
        root=new Node();
    }

    void makeTree(){
        int depth=-1;
        Node *curNode=root;
        for(int i=nodeD.size()-1;i>=0;i--){
            if(nodeD[i]==0){
                root->value=1;
                depth=nodeD[i];
            }
            else{
                if(nodeD[i]>depth){
                    Node *newNode=new Node(curNode,nodeV[i]);
                    curNode->childList.push_back(newNode);
                    curNode=newNode;
                }
                else if(nodeD[i]==depth){
                    Node *newNode=new Node(curNode->parent,nodeV[i]);
                    curNode->parent->childList.push_back(newNode);
                    curNode=newNode;
                }
                else if(nodeD[i]<depth){
                    while(depth!=nodeD[i]){
                        curNode=curNode->parent;
                        depth--;
                    }
                    Node *newNode=new Node(curNode->parent,nodeV[i]);
                    curNode->parent->childList.push_back(newNode);
                    curNode=newNode;
                }
                depth=nodeD[i];
            }
        }
    }

    void preOrder(Node* r){
        cout<<r->value<<" ";

        for(int i=r->childList.size()-1;i>=0;i--){
            preOrder(r->childList[i]);
        }
    }
};

int main(){
    cin>>t;
    while(t--){
        Tree tree;
        nodeD.clear();
        nodeV.clear();
        cin>>n;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            nodeV.push_back(a);
        }
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            nodeD.push_back(a);
        }
        tree.makeTree();
        tree.preOrder(tree.root);
        cout<<endl;
    }
}
