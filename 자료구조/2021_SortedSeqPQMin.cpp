// Created by dongwan-kim on 2022/04/29.

#include<iostream>
#include<vector>
using namespace std;

class SortedSeqPQMin{
public:
    vector<int> seq;

    bool empty(){
        return seq.size()==0;
    }

    int size(){
        return seq.size();
    }

    void insert(int e){
       int idx=0;
       for(idx=0;idx<seq.size();idx++){
           if(seq[idx]>e)
               break;
       }
       seq.insert(seq.begin()+idx,e);
    }

    int min(){
        if(empty())
            return -1;
        else{
            return seq[0];
        }
    }

    void removeMin(){
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
        SortedSeqPQMin seq;
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
        for(int i=0;i<n;i++) {
            v.push_back(seq.min());
            seq.removeMin();
        }
        for(int i=0;i<n;i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }

}