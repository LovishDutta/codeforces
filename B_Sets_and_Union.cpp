#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,orr=0,ans=0,cnt=0;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            int a,val=0;
            cin>>a;
            for(int j=0;j<a;j++){
                int b;
                cin>>b;
                val=(val|(1LL<<b));
            }
            arr[i]=val;
            orr=orr|val;
        }
        for(int j=0;j<63;j++){
            if((orr&(1LL<<j))>0){
                int val=0;
                for(int i=0;i<n;i++){
                    if((arr[i]&(1LL<<j))==0) val=val|arr[i];
                }
                ans=max(ans,(long long)__builtin_popcountll(val));
            }
        }
        cout<<ans<<endl;
    }
}