#include <iostream>

using namespace std;

class Stack{
private:
    char* arr;
    int topIndex;
    int size;
public:
    Stack(int maxSize){
        arr = new char[maxSize];
        topIndex = -1;
        size = 0;
    }
    ~Stack(){
        delete[] arr;
    }

    void push(int data){
        arr[++topIndex] = data;
        size++;
    }
    char pop(){
        size--;
        return arr[topIndex--];
    }
    bool empty(){
        return (size == 0);
    }
    char top(){
        return arr[topIndex];
    }

};

int main(){
    string sik;
    cin >> sik;
    Stack st(sik.size());
    for(int i = 0; i < sik.size(); i++){
        if( 'A' <= sik[i] && sik[i] <= 'Z'){
            cout << sik[i];
        }
        if(sik[i] == '('){
            st.push('(');
        }
        if(sik[i] == ')'){
            while(!st.empty() && st.top()!='('){
                cout << st.pop();
            }
            st.pop();
        }
        if(sik[i] == '*' || sik[i] == '/'){
            while(!st.empty() && st.top()!='('&& st.top()!= '+' && st.top() != '-'){
                cout << st.pop();
            }
            st.push(sik[i]);
        }
        if(sik[i] == '+' || sik[i] == '-'){
            while(!st.empty() && st.top()!='(' ) {
                cout << st.pop();
            }
            st.push(sik[i]);
        }
    }
    while(!st.empty()){
        cout << st.pop();
    }

}