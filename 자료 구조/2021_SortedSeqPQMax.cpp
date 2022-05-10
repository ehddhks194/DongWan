// Created by dongwan-kim on 2022/04/29.
#include<iostream>
#include<vector>
using namespace std;

class SortedSeqPQMax{
public:
    vector<int>seq;

    int size(){
        return seq.size();
    }

    bool empty(){
        return seq.size()==0;
    }

    void insert(int e){
        int idx=0;
        for(idx=0;idx<seq.size();idx++){
            if(seq[idx]<e)
                break;
        }
        seq.insert(seq.begin()+idx,e);
    }

    int max(){
        if(empty())
            return -1;
        else{
            return seq[0];
        }
    }

    void removeMax(){
        if(empty())
            cout<<-1<<endl;
        else{
            seq.erase(seq.begin());
        }
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        SortedSeqPQMax seq;
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
