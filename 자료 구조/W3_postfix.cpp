// Created by dongwan-kim on 2022/04/12.
#include<iostream>
#include<string>
using namespace std;

class Stack{
public:
    int size;
    int arr[100];

    Stack(){
        size=0;
        for(int i=0;i<100;i++){
            arr[i]=0;
        }
    }

    void push(int v){
        arr[size]=v;
        size++;
    }

    int pop(){
        return arr[--size];
    }
};

int main(){
    int t;
    cin>>t;
    Stack st;
    while(t--){
        string str;
        cin>>str;
        for(int i=0;i<str.length();i++){
            if(str[i]-'0'>0&&str[i]-'0'<10){
                st.push(str[i]-'0');
            }
            else{
                int a=st.pop();
                int b=st.pop();
                if(str[i]=='+'){
                    st.push(a+b);
                }
                else if(str[i]=='-'){
                    st.push(b-a);
                }
                else if(str[i]=='*'){
                    st.push(a*b);
                }
            }
        }
        cout<<st.pop()<<endl;
    }
}
