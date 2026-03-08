#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,m,l,ans=0;
        cin>>n>>m>>l;
        vector<int> arr(n+1,1);
        for(int i=1;i<=n;i++) cin>>arr[i];
        int ele=min(n+1,m), i=1,flag=0;
        if(m<n+1){
            for(i=1;i<=n;i++){
               // if(flag) cout<<i<<endl;
                if(flag&&ele>1) ans+=(arr[i]-arr[i-1]+1)/ele;
                else if(!flag) ans=0;
                if(n-i<=ele+1) flag=true;
                if(flag) ele=max(ele-1,1LL);
            }    
        }
        else{
            for(i=1;i<=n;i++){
                if(ele>1) ans+=(arr[i]-arr[i-1]+1)/ele;
                ele=max(ele-1,1LL);
            }
        }
        cout<<ans+(l-arr[n])<<endl;
    }
}