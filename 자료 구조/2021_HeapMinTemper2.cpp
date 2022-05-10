//
// Created by dongwan-kim on 2022/05/05.
//
#include<iostream>
#include<vector>
using namespace std;

struct HeapMinTemper{
    vector<int> v;
    int size;

    HeapMinTemper(){
        v.push_back(-1);
        size=0;
    }

    bool empty(){
        if(size==0)
            return true;
        else
            return false;
    }

    void swap(int idx1,int idx2){
        v[0]=v[idx1];
        v[idx1]=v[idx2];
        v[idx2]=v[0];
    }

    void upHeap(int idx){
        if(size==1)
            return;
        else{
            int parent=idx/2;
            if(v[parent]>v[idx]){
                swap(parent,idx);
                upHeap(parent);
            }
        }
    }

    void downHeap(int idx){
        int left=idx*2;
        int right=idx*2+1;
        int child;

        if(left>size)
            return;
        else if(left==size)
            child=left;
        else{
            if(v[left]<=v[right])
                child=left;
            else
                child=right;
        }

        if(v[child]<v[idx]){
            swap(child,idx);
            downHeap(child);
        }
    }

    void insert(int e){
        v.push_back(e);
        size++;
        upHeap(size);
    }

    int removeMin(){
        if(empty())
            return -1;
        else{
            int top=v[1];
            v[1]=v[size];
            size--;
            v.pop_back();
            downHeap(1);
            return top;
        }
    }

    int min(){
        if(empty())
            return -1;
        else
            return v[1];
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
    while(t--){
        int n, p;
        cin>>n>>p;
        HeapMinTemper h;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            h.insert(a);
        }
        bool posible=false;
        int cnt=0;
        while(true){
            if(h.min()>=p){
                posible=true;
                break;
            }
            if(h.size==1){
                break;
            }
            int k1=h.removeMin();
            int k2=h.removeMin();
            h.insert((k1+k2)/2);
            cnt++;
        }

        if(posible){
            cout<<cnt<<endl;
            h.print();
        }
        else{
            cout<<"False"<<endl;
        }
    }
}
