#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,k,p,q,ans=1e15;
        cin>>n>>k>>p>>q;
        vector<int> arr(n),pref(n),pq(n),qp(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
            
            if(i==0){
                pref[i]=min((arr[i]%p)%q,(arr[i]%q)%p);
                pq[i]=(arr[i]%p)%q;
                qp[i]=(arr[i]%q)%p;
            }
            else{
                pref[i]=min((arr[i]%p)%q,(arr[i]%q)%p)+pref[i-1];
                pq[i]=(arr[i]%p)%q+pq[i-1];
                qp[i]=(arr[i]%q)%p+qp[i-1];
            }
        }
        for(int i=0;i<=n-k;i++){
            int a=min(pq[i+k-1]-(i>0?pq[i-1]:0),qp[i+k-1]-(i>0?qp[i-1]:0))+pref[n-1]-pref[i+k-1];
            if(i>0) a+=pref[i-1];
            ans=min(ans,a);
        }
        cout<<ans<<endl;
    }
}