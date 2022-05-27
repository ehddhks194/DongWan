// Created by dongwan-kim on 2022/05/27.
#include<iostream>
#include<vector>
using namespace std;

int n,m,k,v;
int graph[501][501];

int main(){
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>graph[i][j];
        }
    }

    while(m--){
        cin >> k;

        vector<int> group;
        for (int i = 0; i < k; i++) {
            cin >> v;
            group.push_back(v);
        }

        int A = 0;
        for (int i = 0; i < group.size(); i++) {
            for (int j = 0; j < group.size(); j++) {
                if (i == j)
                    continue;

                A = 0;

                if (graph[group[i]][group[j]] == 1) {
                    A = 1;
                } else {
                    for (int l = 1; l <= n; l++) {
                        if (graph[group[i]][l] == 1 && graph[l][group[j]] == 1) {
                            A = 1;
                            break;
                        }
                    }
                }
                if(A==0)
                    break;
            }
            if(A==0)
                break;
        }
        cout << A << endl;
    }
}

