#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,m,ans=0,idx=0;
        cin>>n>>m;
        vector<int> a(n),b(m+1); 
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=1;i<=m;i++) cin>>b[i];
        for(int i=0;i<n;i++) pq.push(b[a[i]]);
        for(int i=1;i<=m;i++) pq.push(b[i]);
        for(int i=0;i<n;i++){
            ans+=pq.top();
            pq.pop();
        }
        cout<<ans<<endl;
        
    }
}