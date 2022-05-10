#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    int value;
    vector<Node*> childList;
    Node* parent;

    Node(){
        value=0;
        parent= nullptr;
    }
};

class Tree {
public:
    Node *root;
    vector<Node *> nodeList;

    Tree() {
        root = new Node;
        root->value = 1;
        nodeList.push_back(root);
    }

    Node *findNode(int v) {
        for (int i = 0; i < nodeList.size(); i++) {
            if (nodeList[i]->value == v)
                return nodeList[i];
        }
        return nullptr;
    }

    void insertNode(int parentv, int childv) {
        Node *parentNode = findNode(parentv);
        Node *newNode = new Node();
        newNode->value = childv;
        newNode->parent = parentNode;
        parentNode->childList.push_back(newNode);
        nodeList.push_back(newNode);
    }

    void preorderTraversal(Node *r) {
        if (r == root) {
            cout << 0 << " ";
        }
        else{
            cout<<r->parent->value<<" ";
        }
        for(int i=0;i<r->childList.size();i++){
            preorderTraversal(r->childList[i]);
        }
    }
};


int main() {
    int t, n;
    cin >> t;
    while (t--) {
        Tree tree;
        cin >> n;
        while (n--) {
            int a, b;
            cin >> a >> b;
            tree.insertNode(a, b);
        }
        tree.preorderTraversal(tree.root);
        cout << endl;
    }
}