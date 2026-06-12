#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,k,ans=0;
        cin>>n>>k;
        vector<int> arr(n,0);
        while(k>0){
            for(int i=0;i<n;i++){
                if(k==0) break;
                arr[i]+=k;
                k--;
            }
            for(int i=n-1;i>=0;i--){
                if(k==0) break;
                arr[i]+=k;
                k--;
            }
        }
        for(int i=0;i<n;i++) ans=max(ans,arr[i]);
        cout<<ans<<endl;
    }
}