#include<bits/stdc++.h>
using namespace std;
int recur(int i,bool flag,vector<int>& arr){
    if(i==arr.size()) return 0;
    int ans1=0,ans2=0;
    int prevmin=1e12;
    int postmin=1e12;
    if(i>0) prevmin=arr[i]-arr[i-1];
    if(i<arr.size()-1) postmin=arr[i+1]-arr[i];
    int r=min(prevmin,postmin);
    if(flag){
        ans1=1+recur(i+1,false,arr);
    }
    else{
        if(arr[i]-arr[i-1]<=arr[i+1]-arr[i]) ans1=1+recur(i+1,true,)
    }
}
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n;
        cin>>n;
        vector<int> arr(n);
        cin>>arr[i];

    }
}