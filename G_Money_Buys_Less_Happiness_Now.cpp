#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
    int n,x,cnt=0,sm=0;
    cin>>n>>x;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        arr[i]*=-1;
    }
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<n;i++){
        sm+=arr[i];
        if(arr[i]<0) pq.push(arr[i]);
        while(sm<0){
            sm-=pq.top();
            pq.pop();
            cnt++;
        }
        sm+=x;
    }
    cout<<n-cnt<<endl;
    }
}