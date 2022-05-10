// Created by dongwan-kim on 2022/04/22.
#include<iostream>
#include<array>
using namespace std;

class Array{
public:
    int arr[1000];
    int size;

    Array(){
        for(int i=0;i<1000;i++){
            arr[i]=0;
        }
        size=0;
    }

    void shift(int d){
        int temp[size];
        int k=size;
        for(int i=0;i<size;i++){
            temp[i]=arr[(k-d)%size];
            k++;
        }
        for(int i=0;i<size;i++){
            arr[i]=temp[i];
        }
    }

    void reverse(int q,int p){
        int temp[p-q+1];
        int m=0;
        for(int i=p;i>=q;i--){
            temp[m]=arr[i];
            m++;
        }
        m=0;
        for(int i=q;i<=p;i++){
            arr[i]=temp[m];
            m++;
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