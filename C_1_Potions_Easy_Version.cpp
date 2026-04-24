#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,cnt=0,sm=0;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<n;i++){
        sm+=arr[i];
        if(arr[i]<0) pq.push(arr[i]);
        while(sm<0){
            sm-=pq.top();
            pq.pop();
            cnt++;
        }
    }
    cout<<n-cnt;
}