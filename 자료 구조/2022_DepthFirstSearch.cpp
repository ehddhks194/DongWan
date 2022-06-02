// Created by dongwan-kim on 2022/06/03.
#include<iostream>
#include<vector>
using namespace std;

int t,m,n,a,b;
vector<int> graph[101];
bool visit[101];

void dfs(int x){
    cout<<x<<" ";
    visit[x]=true;
    for(int i=0;i<graph[x].size();i++){
        int next = graph[x][i];
        if(!visit[next]){
            visit[next]=true;
            dfs(next);
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
        dfs(1);
        cout<<endl;
        for(int i=0;i<101;i++){
            graph[i].clear();
            visit[i]=false;
        }
    }
}