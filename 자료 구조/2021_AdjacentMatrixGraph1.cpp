// Created by dongwan-kim on 2022/05/27.
#include<iostream>
#include<string>
using namespace std;

int t,n,vertex,s,d;
string cmd;

bool graph[2000][2000];

int main(){
    cin>>t>>n;

    for(int i=0;i<n;i++){
        cin>>vertex;
    }

    while(t--){
        cin>>cmd>>s>>d;

        if(cmd=="insertEdge"){
            if(graph[s][d]){
                cout<<"Exist"<<endl;
            }
            else{
                graph[s][d]= true;
                graph[d][s]=true;
            }
        }
        else if(cmd=="eraseEdge"){
            if(!graph[s][d])
                cout<<"None"<<endl;
            else{
                graph[s][d]=false;
                graph[d][s]=false;
            }
        }
        else if(cmd=="isAdjacentTo"){
            if(graph[s][d])
                cout<<"True"<<endl;
            else
                cout<<"False"<<endl;
        }
    }
}