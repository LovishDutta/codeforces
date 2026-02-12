#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        if(n%2==0){ cout<<-1;
        cout<<endl;
    }
        else{
        vector<int> arr;
       for(int k=1;k<=n;k+=2){
        arr.push_back(k);
       }
       for(int k=2;k<=n;k+=2){
        arr.push_back(k);
       }
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    }
}