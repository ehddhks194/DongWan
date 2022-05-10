// Created by dongwan-kim on 2022/05/02.
#include<iostream>
#include<vector>
using namespace std;

struct HeapMax{
    vector<int> v;
    int size;

    HeapMax(){
        v.push_back(-1);
        size=0;
    }

    void Size(){
        cout<<size<<endl;
    }

    bool empty(){
        if(size==0)
            return true;
        else
            return false;
    }

    void swap(int idx1, int idx2){
        v[0]=v[idx1];
        v[idx1]=v[idx2];
        v[idx2]=v[0];
    }

    void upHeap(int idx){
        if(idx==1)
            return;
        int parent=idx/2;
        if(v[parent]<v[idx]){
            swap(parent, idx);
            upHeap(parent);
        }
    }

    void downHeap(int idx){
        int left=idx*2;
        int right=idx*2+1;
        int child;
        if(left>size)
            return;
        else if(left==size){
            child=left;
        }
        else{
            if(v[left]>=v[right])
                child=left;
            else
                child=right;
        }

        if(v[child]>v[idx]){
            swap(child,idx);
            downHeap(child);
        }
    }

    void insert(int e){
        v.push_back(e);
        size++;
        upHeap(size);
    }

    int max(){
        if(empty())
            return -1;
        else
            return v[1];
    }

    void removeMax(){
        if(empty())
            cout<<-1<<endl;
        else{
            int top=v[1];
            v[1]=v[size];
            size--;
            v.pop_back();
            downHeap(1);
            cout<<top<<endl;
        }
    }

    void print(){
        if(empty())
            cout<<-1<<endl;
        else{
            for(int i=1;i<=size;i++){
                cout<<v[i]<<" ";
            }
            cout<<endl;
        }
    }
};

int main(){
    int t;
    cin>>t;
    HeapMax hm;
    while(t--){
        string cmd;
        cin>>cmd;
        if(cmd=="insert"){
            int a;
            cin>>a;
            hm.insert(a);
        }
        else if(cmd=="size"){
            hm.Size();
        }
        else if(cmd=="removeMax"){
            hm.removeMax();
        }
        else if(cmd=="max"){
            cout<<hm.max()<<endl;
        }
        else if(cmd=="print"){
            hm.print();
        }
        else if(cmd=="empty"){
            if(hm.empty())
                cout<<1<<endl;
            else
                cout<<0<<endl;
        }
    }
}