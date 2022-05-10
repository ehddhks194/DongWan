// Created by dongwan-kim on 2022/04/22.
#include<iostream>
#include<array>
using namespace std;

class Array{
public:
    int arr[10000];
    int size;

    Array(){
        for(int i=0;i<10000;i++)
            arr[i]=0;
        size=0;
    }

    void add(int idx,int z){
        for(int i=size-2;i>=idx;i--){
            arr[i+1]=arr[i];
        }
        arr[idx]=z;
    }

    void remove(int idx){
        for(int i=idx;i<size;i++){
            arr[i]=arr[i+1];
        }
        arr[size-1]=0;
    }

    void set(int idx, int z){
        arr[idx]=z;
    }

    void print(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void find(int z){
        int k=0;
        for(int i=0;i<size;i++){
            if(arr[i]==z){
                cout<<i<<endl;
                k++;
                break;
            }
        }
        if(k==0)
            cout<<-1<<endl;
    }
};

int main(){
    int t,n;
    cin>>t>>n;
    Array ar;
    ar.size=n;
    while(t--){
        string cmd;
        cin>>cmd;
        if(cmd=="add"){
            int a,b;
            cin>>a>>b;
            ar.add(a,b);
        }
        else if(cmd=="print"){
            ar.print();
        }
        else if(cmd=="remove"){
            int a;
            cin>>a;
            ar.remove(a);
        }
        else if(cmd=="find"){
            int a;
            cin>>a;
            ar.find(a);
        }
        else if(cmd=="set"){
            int a,b;
            cin>>a>>b;
            ar.set(a,b);
        }
    }
}