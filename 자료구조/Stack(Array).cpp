//Created by dongwan-kim on 2022/03/16.

#include<iostream>
#include<string>
using namespace std;

int t,n;

class StackArray{
private:
    int size=0;
    int arr[10];

public:
    bool empty();
    void top();
    void push(int X);
    void pop();
    void Array();
};

void StackArray::Array() {
    size=0;
    for(int i=0;i<10;i++){
        arr[i]=0;
    }
}

bool StackArray::empty() {
    if(size==0)
        return true;
    else
        return false;
}

void StackArray::top() {
    if(empty())
        cout<<-1<<endl;
    else{
        cout<<arr[size-1]<<endl;
    }
}

void StackArray::push(int X) {
    if(size==t){
        cout<<"FULL"<<endl;
    }
    else{
        arr[size]=X;
        size++;
    }
}

void StackArray::pop() {
    if(empty())
        cout<<-1<<endl;
    else{
        top();
        arr[size]=0;
        size--;
    }
}

int main(){

    string opr;
    int X;
    cin>>t>>n;
    StackArray ar;

    for(int i=0;i<n;i++){
        cin>>opr;
        if(opr=="empty"){
            if(ar.empty()== true)
                cout<<1<<endl;
            else
                cout<<0<<endl;
        }
        else if(opr=="top"){
            ar.top();
        }
        else if(opr=="push"){
            cin>>X;
            ar.push(X);
        }
        else if(opr=="pop"){
            ar.pop();
        }
    }

}