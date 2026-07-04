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
        vector<int> arr(n),flag(2*n,0),pref(2*n,0),f(2*n,0),p(2*n,0);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(int i=0;i<n;i++) arr.push_back(arr[i]);
        p[0]=arr[0];
        for(int i=1;i<2*n;i++) p[i]=arr[i]+p[i-1];
        for(int i=k;i<k+n;i++){
            int sum=p[i+k]-(i-k>0?p[i-k-1]:0);
            if(2LL*k*arr[i]>sum-arr[i]){
                 flag[i]=1;
                 if(i-n>=0) flag[i]=1;
                 if(i+n<2*n) flag[i]=1;
            }
        }
        if(!flag[0]) pref[0]=arr[0];
        f[0]=flag[0];
        for(int i=1;i<2*n;i++){
            pref[i]=pref[i-1]+(flag[i]?0:arr[i]);
            f[i]=f[i-1]+flag[i];
        }
        for(int i=k;i<k+n;i++){
            if(flag[i]){
                int sum=pref[i+k]-(i-k>0?pref[i-k-1]:0);
                int g=f[i+k]-(i-k>0?f[i-k-1]:0);
                ans+=(2*k+1-g)*arr[i]-sum;
            }
        }
        cout<<ans<<endl;
    }
}