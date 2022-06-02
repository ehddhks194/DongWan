// Created by dongwan-kim on 2022/06/03.
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int t,n,m,a,b,k;
vector<int> graph[101];
bool visit[101];

int bfs(int start,int end){
    queue<pair<int,int>> q;
    q.push({start,0});
    while(!q.empty()){
        int front=q.front().first;
        int cnt=q.front().second;
        q.pop();
        if(front==end)
            return cnt;
        if(visit[front])
            continue;
        visit[front]=true;
        for(auto i : graph[front])
            if(!visit[i])
                q.push({i,cnt+1});
    }
    return 0;
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
            cin>>a>>b;
            cout<<bfs(a,b)<<endl;
            for(int i=0;i<101;i++){
                visit[i]=false;
            }
        }
        for(int i=0;i<101;i++){
            graph[i].clear();
        }
    }

}