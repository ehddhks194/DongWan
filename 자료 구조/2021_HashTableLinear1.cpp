//
// Created by dongwan-kim on 2022/05/19.
//
#include<iostream>
using namespace std;

#define NOITEM 0
#define ISITEM 1
#define AVAILABLE 2

struct Entry{
    int key;
    string value;
    int valid;

    Entry(){
        key=0;
        value="";
        valid=NOITEM;
    }

    Entry(int key, string value){
        this->key=key;
        this->value=value;
        valid=ISITEM;
    }

};

struct HashTable{
    Entry* table;
    int capacity;

    HashTable(int N){
        capacity=N;
        table = new Entry[capacity];
    }

    int hashfnc(int key){
        return key % capacity;
    }

    void put(int k, string v){
        int idx= hashfnc(k);
        int cnt=1;

        while(table[idx].valid==ISITEM && cnt<=capacity){
            idx= hashfnc(idx+1);
            cnt++;
        }

        if(cnt>capacity) return;
        table[idx]=Entry(k,v);
        cout<<cnt<<endl;
    }

    void erase(int k){
        int idx= hashfnc(k);
        int cnt=1;

        while(table[idx].valid != NOITEM && cnt<=capacity){
            if(table[idx].valid==ISITEM && table[idx].key==k){
                table[idx].valid=AVAILABLE;
                return;
            }

            idx= hashfnc(idx+1);
            cnt++;
        }
        cout<<"None"<<endl;
    }

    void find(int k){
        int idx= hashfnc(k);
        int cnt=1;

        while(table[idx].valid != NOITEM && cnt<=capacity){
            if(table[idx].valid==ISITEM && table[idx].key==k){
                 cout<<table[idx].value<<endl;
                 return;
            }

            idx= hashfnc(idx+1);
            cnt++;
        }
        cout<<"None"<<endl;
    }

};

int main(){
    int t,n;
    cin>>t>>n;
    HashTable* ht = new HashTable(n);

    while(t--){
        string cmd;
        cin>>cmd;

        if(cmd=="put"){
            int a;
            string b;
            cin>>a>>b;
            ht->put(a,b);
        }
        else if(cmd=="erase"){
            int a;
            cin>>a;
            ht->erase(a);
        }
        else if(cmd=="find"){
            int a;
            cin>>a;
            ht->find(a);
        }
    }
}
