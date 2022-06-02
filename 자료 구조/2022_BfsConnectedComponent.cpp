// Created by dongwan-kim on 2022/06/03.
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int k,m,n,a,b,t;
vector<int> graph[101];
bool visit[101];

int bfs(int x){
    queue<int> q;
    q.push(x);
    int connected=0;
    while(!q.empty()){
        int front=q.front();
        q.pop();
        if(visit[front])
            continue;
        visit[front]=true;
        connected++;
        for(auto i : graph[front]){
            if(!visit[i])
                q.push(i);
        }
    }
    return connected;
}

int main(){
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        while(m--){
            cin>>a>>b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        while(k--){
            cin>>a;
            cout<<bfs(a)<<endl;
            for(int i=0;i<101;i++){
                visit[i]=false;
            }
        }
        for(int i=0;i<101;i++){
            graph[i].clear();
        }
    }
}