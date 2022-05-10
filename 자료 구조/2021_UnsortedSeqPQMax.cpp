// Created by dongwan-kim on 2022/04/29.
#include<iostream>
#include<vector>
using namespace std;

class UnsortedSeqPQMax{
public:
    vector<int>seq;

    bool empty(){
        return seq.size()==0;
    }

    int size(){
        return seq.size();
    }

    void insert(int e){
        seq.push_back(e);
    }

    int max(){
        if(empty())
            return -1;
        else{
            int maxV=seq[0];
            for(int i=0;i<seq.size();i++){
                if(seq[i]>maxV)
                    maxV=seq[i];
            }
            return maxV;
        }
    }

    void removeMax(){
        if(empty())
            cout<<-1<<endl;
        else{
            int maxi=0;
            for(int i=0;i<seq.size();i++){
                if(seq[i]>seq[maxi])
                    maxi=i;
            }
            seq.erase(seq.begin()+maxi);
        }
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        UnsortedSeqPQMax seq;
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
            v.push_back(seq.max());
            seq.removeMax();
        }
        for(int i=0;i<n;i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
}