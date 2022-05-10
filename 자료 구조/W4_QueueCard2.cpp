#include<iostream>
#include<string>
using namespace std;

int n;

class Queue{
public:
    int arr[100];
    int queueSize;
    int front;
    int rear;
    int score;

    Queue(){
        queueSize=0;
        front=0;
        rear=0;
        score=0;
    }

    bool empty(){
        if(queueSize==0)
            return true;
        else
            return false;
    }

    void updateidx(){
        front %= n;
        rear %= n;
    }

    void enqueue(int v){
        arr[rear]=v;
        rear++;
        updateidx();
        queueSize++;
    }

    int dequeue(){
        int k=arr[front];
        front++;
        updateidx();
        queueSize--;
        return k;
    }

};

int main(){
    int t;
    cin>>t;
    while(t--){
        Queue q1;
        Queue q2;

        cin>>n;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            q1.enqueue(a);
        }
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            q2.enqueue(a);
        }

        for(int i=0;i<n;i++) {
            int a = q1.dequeue();
            int b = q2.dequeue();
            if(a>b){
                q1.score++;
                cout<<"Round"<<i+1<<" "<<q1.score<<":"<<q2.score<<endl;
                q1.arr[q1.front]+=(a-b);
            }
            else if(a<b) {
                q2.score++;
                cout << "Round" << i+1 << " " << q1.score << ":" << q2.score << endl;
                q2.arr[q2.front] += (b - a);
            }
            else{
                cout << "Round" << i+1 << " " << q1.score << ":" << q2.score << endl;
            }
        }
        if(q1.score>q2.score){
            cout<<"Winner P1"<<endl;
        }
        else if(q2.score>q1.score){
            cout<<"Winner P2"<<endl;
        }
        else{
            cout<<"Draw"<<endl;
        }
    }
}