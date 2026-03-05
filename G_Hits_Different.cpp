#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,ans=0;
        cin>>n;
        int cnt=0,k=n;
        while(k-cnt>0){
            k-=cnt;
            cnt++;
        }
        int l=k,r=k;
        for(int i=cnt;i>=1;i--){
            for(int z=l;z<=r;z++){
                ans+=(((i-1)*i)/2+z)*(((i-1)*i)/2+z);
            }
            l=max(1LL,l-1);
            r=min(r,i-1);
        }
        cout<<ans<<endl;
    }
}