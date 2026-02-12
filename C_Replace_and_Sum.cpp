#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n,q;
        cin>>n>>q;
        vector<int> a(n);
        vector<int> b(n);
        vector<vector<int>> quer(q,vector<int>(2,0));
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];
        for(int i=0;i<q;i++) cin>>quer[i][0]>>quer[i][1];
        a[n-1]=max(a[n-1],b[n-1]);
        for(int i=n-2;i>=0;i--){
            a[i]=max(max(a[i],a[i+1]),b[i]);
        }
        vector<int> pref(n,a[0]);
        for(int i=1;i<n;i++) pref[i]=pref[i-1]+a[i];
        for(int i=0;i<q;i++){
            int prev=quer[i][0]-2>=0?pref[quer[i][0]-2]:0;
            cout<<(pref[quer[i][1]-1]-prev)<<" ";
        }
        cout<<endl;
    }
}