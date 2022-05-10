//
// Created by dongwan-kim on 2022/04/22.
//
#include<iostream>
#include<array>
using namespace std;

class Array{
public:
    int arr[1000];
    int size;

    Array(){
        size=0;
    }

    void shift(int d){
        int temp[size];
        int k=0;
        for(int i=0;i<size;i++){
            temp[i]=arr[(d+i)%size];
        }
        for(int i=0;i<size;i++){
            arr[i]=temp[i];
        }
    }

    void reverse(int q,int p){
        int temp[p-1+1];
        int k=0;
        for(int i=p;i>=q;i--){
            temp[k]=arr[i];
            k++;
        }
        k=0;
        for(int i=q;i<=p;i++){
            arr[i]=temp[k];
            k++;
        }
    }

    void print(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

};

int main(){
    int t,n;
    cin>>t>>n;
    Array *ar=new Array;
    ar->size=n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        ar->arr[i]=a;
    }
    while(t--){
        string cmd;
        cin>>cmd;
        if(cmd=="shift"){
            int a;
            cin>>a;
            ar->shift(a);
        }
        else if(cmd=="reverse"){
            int a,b;
            cin>>a>>b;
            ar->reverse(a,b);
        }
        else if(cmd=="print"){
            ar->print();
        }
    }
}