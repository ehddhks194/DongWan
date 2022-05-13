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

    Node(int key){
        this->key=key;
        parent=left=right= nullptr;
        visit=false;
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

    void print(Node* node){
        if(node== nullptr)
            return;

        print(node->left);
        cout<<node->key<<" ";
        print(node->right);
    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        BTS bts;
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            bts.insert(a);
        }
        bts.print(bts.root);
        cout<<endl;
    }
}