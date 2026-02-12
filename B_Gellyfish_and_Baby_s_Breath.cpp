#include<bits/stdc++.h>
using namespace std;
#define int long long
long long MOD = 998244353;
long long pw(long long base, long long exp) {
    long long res = 1;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return res;
}
signed main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n;
        cin>>n;
        vector<int> p(n);
        vector<int> q(n);
        for(int i=0;i<n;i++) cin>>p[i];
        for(int i=0;i<n;i++) cin>>q[i];
        vector<pair<int,int> > pref1;
        vector<pair<int,int> > pref2;
        pref1.push_back({p[0],0});
        pref2.push_back({q[0],0});
        for(int i=1;i<n;i++){
            if(pref1[i-1].first<p[i]) pref1.push_back({p[i],i});
            else pref1.push_back(pref1[i-1]);
            if(pref2[i-1].first<q[i]) pref2.push_back({q[i],i});
            else pref2.push_back(pref2[i-1]);
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(pref1[i].first>pref2[i].first) ans.push_back((pw(2,pref1[i].first)+pw(2,q[i-pref1[i].second]))%MOD);
            else if(pref1[i].first<pref2[i].first) ans.push_back((pw(2,pref2[i].first)+pw(2,p[i-pref2[i].second]))%MOD);
            else if(q[i-pref1[i].second]>p[i-pref2[i].second]) ans.push_back((pw(2,pref1[i].first)+pw(2,q[i-pref1[i].second]))%MOD);
            else ans.push_back((pw(2,pref2[i].first)+pw(2,p[i-pref2[i].second]))%MOD);
        }
        for(int i=0;i<n;i++) cout<<ans[i]<<" ";
        cout<<endl;
    }
}