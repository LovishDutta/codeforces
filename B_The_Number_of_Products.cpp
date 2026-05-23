#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,cnt=0,ans=0,a;
    cin>>n;
    vector<int> f(1,0);
    for(int i=0;i<n;i++){
         cin>>a;
         f.push_back(f[f.size()-1]+(a<0));
    }
    for(int i=n;i>=0;i--) if(f[i]%2) cnt++;
    for(int i=0;i<n;i++){
        
        if(f[i]%2){
            cnt--;
            ans+=cnt;
        }
        else ans+=(n-cnt-i);    
    }
    cout<<(n*(n+1))/2-ans<<" "<<ans;
}