#include<iostream>
#include<string>
using namespace std;

int t,n,s,d,vertex;
bool graph[2000][2000];
string cmd;
int main(){
    cin>>t>>n;

    for(int i=0;i<n;i++){
        cin>>vertex;
    }

    while(t--){
        cin>>cmd;
        if(cmd=="insertEdge"){
            cin>>s>>d;
            if(graph[s][d])
                cout<<"Exist"<<endl;
            else {
                graph[s][d] = true;
                graph[d][s] = true;
            }
        }
        else if(cmd=="eraseEdge"){
            cin>>s>>d;
            if(!graph[s][d]){
                cout<<"None"<<endl;
            }
            else {
                graph[s][d] = false;
                graph[d][s] = false;
            }
        }
        else if(cmd=="incidentEdges"){
            int c=0;
            cin>>s;
            for(int i=0;i<2000;i++){
                if(graph[i][s])
                    c++;
            }
            cout<<c<<endl;
        }
    }
}