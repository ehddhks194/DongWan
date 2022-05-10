// Created by dongwan-kim on 2022/04/29.
#include<iostream>
#include<vector>
using namespace std;

class UnSortedSeqPQMin{
public:
    vector<int> seq;

    int size(){
        return seq.size();
    }

    bool empty(){
        return seq.size()==0;
    }

    void insert(int e){
        seq.push_back(e);
    }

    int Min(){
        if(empty())
            return -1;
        else{
            int minV=seq[0];
            for(int i=0;i<seq.size();i++){
                if(seq[i]<minV)
                    minV=seq[i];
            }
            return minV;
        }
    }

    void removeMin(){
        if(empty())
            cout<<-1<<endl;
        else{
            int mini=0;
            for(int i=0;i<seq.size();i++){
                if(seq[i]<seq[mini])
                    mini=i;
            }
            seq.erase(seq.begin()+mini);
        }
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        UnSortedSeqPQMin seq;
        vector<int> v;
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            v.push_back(a);
        }
        for(int i=0;i<n;i++){
            seq.insert(v.back());
            v.pop_back();
        }
        for(int i=0;i<n;i++){
            v.push_back(seq.Min());
            seq.removeMin();
        }
        for(int i=0;i<n;i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
}