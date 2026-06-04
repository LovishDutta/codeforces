#include<bits/stdc++.h>
using namespace std;
#define int long long
bool check(int mid,vector<int>& arr){
    int cnt=0;
    for(int i=0;i<arr.size();i++){
        if(mid<arr[i]){
            cnt+=(arr[i]-mid);
        }
    }
    return cnt<=mid;
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,a;
        cin>>n;
        vector<int> adj(n+1);
        vector<int> arr;
        for(int i=2;i<=n;i++){
            cin>>a;
            adj[a]++;
        }
        for(int i=0;i<=n;i++) if(adj[i]>0) arr.push_back(adj[i]);
        sort(arr.begin(),arr.end());
        int m=arr.size(),ans=m+1,prev=0,flag=0;
        for(int i=m-1;i>=0;i--){
            arr[i]=max(arr[i]-(i+2),0LL);
        }
        sort(arr.begin(),arr.end());
        int low=0,high=arr[m-1];
        while(low<=high){
            int mid=(low+high)/2;
            if(check(mid,arr)) high=mid-1;
            else low=mid+1;
        }
        cout<<ans+low<<endl;
    }
}