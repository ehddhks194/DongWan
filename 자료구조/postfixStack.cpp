#include<iostream>
#include<string>
using namespace std;

int t,n;
class Stack{
private:
    int size=-1;
    int arr[100];
public:
    void push(int x);
    int pop();
};

void Stack::push(int x) {
    size++;
    arr[size]=x;
}

int Stack::pop() {
         return arr[size--];
}

int main(){
   cin>>t;
   string str;
   Stack st;
   for(int i=0;i<t;i++){
       cin>>str;
       for(int j=0;j<str.length();j++){
           if(str[j]-'0'>=0&&str[j]-'0'<=9){
               st.push(str[j]-'0');
           }
           else{
               int a=st.pop();
               int b=st.pop();
               if(str[j]=='+'){
                   st.push(a+b);
               }
               else if(str[j]=='-'){
                   st.push(b-a);
               }
               else if(str[j]=='*'){
                   st.push(a*b);
               }
           }
       }
       cout<<st.pop()%10<<endl;
   }
    return 0;
}

