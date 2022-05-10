//
// Created by dongwan-kim on 2022/04/22.
//
#include<iostream>
#include<array>
using namespace std;

class Stack{
public:
    int arr[100];
    int t;
    int size;
    Stack(){
        t=-1;
        size=0;
    }

    void push(int a){
        arr[++t]=a;

    }

    int pop(){
        return arr[t--];
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        Stack st;
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
