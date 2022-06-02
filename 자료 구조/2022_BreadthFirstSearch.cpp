// Created by dongwan-kim on 2022/06/03.
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int t,n,m,a,b;
vector<int> graph[101];
bool visit[101];

void bfs(){
    queue<int>q;
    q.push(1);
    while(!q.empty()){
        int top=q.front();
        q.pop();
        if(visit[top])
            continue;
        visit[top]=true;
        cout<<top<<" ";
        for(auto i : graph[top]){
            if(!visit[i])
                q.push(i);
        }
    }
}

int main(){
    cin>>t;
    while(t--){
        cin>>n>>m;
        while(m--){
            cin>>a>>b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        bfs();
        cout<<endl;
        for(int i=0;i<101;i++){
            graph[i].clear();
            visit[i]=false;
        }
    }
}