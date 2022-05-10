//Created by dongwan-kim on 2022/04/09.
#include<iostream>
#include<string>
#include<array>
using namespace std;

class ShiftArray{
public:
    int arr[10000];
    int size;

    ShiftArray(int n,int s){
        size=n;
        for(int i=0;i<n;i++){
            int k;
            cin>>k;
            arr[i]=k;
        }
        Shift(s);
    }

    void Shift(int a){
        int index=a%size;
        index=size-index;
        for(int i=0;i<size;i++){
            if(index==size)
                index=0;
            cout<<arr[index]<<" ";
            index++;
        }
        cout<<endl;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        ShiftArray arr(n,d);
    }
}