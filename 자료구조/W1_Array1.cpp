//Created by dongwan-kim on 2022/04/09.
#include<iostream>
#include<array>
#include<string>
using namespace std;

class Array{
public:
    int arr[10000];
    int size;

    Array(int a){
        for(int i=0;i<10000;i++){
            arr[i]=0;
        }

        size=a;
    }

    void at(int i){
        cout<<arr[i]<<endl;
    }

    void add(int idx,int v){
        for(int i=size;i>=idx;i--){
            arr[i+1]=arr[i];
        }
        arr[idx]=v;
        size++;
    }

    void remove(int idx){
        for(int i=idx+1;i<size;i++){
            arr[i-1]=arr[i];
        }
        arr[size]=0;
        size--;
    }

    void set(int idx,int v){
        arr[idx]=v;
        cout<<arr[idx]<<endl;
    }

    void print(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void find_max(){
        int max=-1;
        for(int i=0;i<size;i++){
            if(max<arr[i])
                max=arr[i];
        }
        cout<<max<<endl;
    }
};

int main(){
    int n,t;
    cin>>n>>t;
    Array arr(n);

    while (t--){
        string cmd;
        cin>>cmd;
        if(cmd=="at"){
            int a;
            cin>>a;
            arr.at(a);
        }
        else if(cmd=="add"){
            int a,b;
            cin>>a>>b;
            arr.add(a,b);
        }
        else if(cmd=="remove"){
            int a;
            cin>>a;
            arr.remove(a);
        }
        else if(cmd=="set"){
            int a,b;
            cin>>a>>b;
            arr.set(a,b);
        }
        else if(cmd=="print"){
            arr.print();
        }
        else if(cmd=="find_max"){
            arr.find_max();
        }
    }
}