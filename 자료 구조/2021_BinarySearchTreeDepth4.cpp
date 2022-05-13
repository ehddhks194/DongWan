//
// Created by dongwan-kim on 2022/05/13.
//
#include<iostream>
using namespace std;
struct Node{
    int key;
    Node* right;
    Node* left;
    Node* parent;
    bool visit;
    int depth;

    Node(int key){
        this->key=key;
        parent=left=right= nullptr;
        visit=false;
        depth=0;
    }
};

struct BTS {
    Node *root;

    BTS() {
        root = nullptr;
    }

    Node *search(Node *curNode, int key) {
        if (curNode == nullptr)
            return nullptr;

        if (curNode->key == key)
            return curNode;
        else if (curNode->key < key)
            return search(curNode->right, key);
        else
            return search(curNode->left, key);
    }

    void insert(int key) {
        if (search(root, key) != nullptr)
            return;

        Node *newNode = new Node(key);
        if (root == nullptr) {
            root = newNode;
            return;
        }

        Node *curNode = root;
        Node *parentNode = nullptr;

        while (curNode != nullptr) {
            parentNode = curNode;
            if (curNode->key < key) {
                curNode = curNode->right;
            } else {
                curNode = curNode->left;
            }
        }

        newNode->parent = parentNode;
        newNode->depth=parentNode->depth+1;
        if (parentNode->key < key) {
            parentNode->right = newNode;
        } else
            parentNode->left = newNode;
    }

    void remove(int key) {
        Node *deleteNode = search(root, key);
        if (deleteNode == nullptr)
            return;

        Node *parentNode = deleteNode->parent;
        Node *child;

        if (deleteNode->left == nullptr && deleteNode->right == nullptr) {
            child = nullptr;
        } else if (deleteNode->left == nullptr && deleteNode->right != nullptr) {
            child = deleteNode->right;
        } else if (deleteNode->left != nullptr && deleteNode->right == nullptr) {
            child = deleteNode->left;
        } else {
            child = deleteNode->right;
            while (child->left != nullptr) {
                child = child->left;
            }
            deleteNode->key = child->key;
            deleteNode = child;
            parentNode = deleteNode->parent;
            child = deleteNode->right;
        }

        if (parentNode == nullptr) {
            root = child;
            root->parent = nullptr;
        } else if (deleteNode == parentNode->left) {
            parentNode->left = child;
            if (child != nullptr) child->parent = parentNode;
        } else {
            parentNode->right = child;
            if (child != nullptr) child->parent = parentNode;
        }
        delete deleteNode;
    }

    void height(Node* node){
        int c=0;
        while(node != nullptr){
            node=node->parent;
            c++;
        }
        cout<<c<<endl;
    }

    void printDepth(int data) {
        Node *curNode = root;
        int depth = 0;

        while (curNode->key != data) {
            if (data < curNode->key) {
                curNode = curNode->left;
            } else if (data > curNode->key) {
                curNode = curNode->right;
            }
            depth++;
        }

        cout<<depth<<"\n";
    }
};
};

int main(){
    int t;
    cin>>t;
    BTS bts;
    while(t--){
        string cmd;
        cin>>cmd;
        if(cmd=="insert"){
            int a;
            cin>>a;
            bts.insert(a);
        }
        else if(cmd=="delete"){
            int a;
            cin>>a;
            bts.remove(a);
        }
        else if(cmd=="height"){
            int a;
            cin>>a;
            bts.height(bts.search(bts.root,a));
        }
    }
}
