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
        vector<int> a(n);
        vector<int> b(n);
        set<int> st;
        for(int i=0;i<n;i++){
            cin>>a[i];
            st.insert(a[i]);
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
            st.insert(b[i]);
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        for(auto &it: st){
            int idx1=lower_bound(b.begin(),b.end(),it)-b.begin();
            int idx2=lower_bound(a.begin(),a.end(),it)-a.begin();
            if(idx2-idx1<=k) ans=max(ans,it*(n-idx1));
        }
        cout<<ans<<endl;
    }
}