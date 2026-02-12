#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n;
        cin>>n;
        vector<int> a(n);
        vector<int> level(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++) cin>>level[i];
        sort(a.begin(),a.end());
        int ans=0;
        vector<int> preflevel(n,level[0]);
        for(int i=1;i<n;i++) preflevel[i]=preflevel[i-1]+level[i];
        for(int i=0;i<a.size();i++){
            int x=a[i];
            int sw=n-i;
            int idx = upper_bound(preflevel.begin(), preflevel.end(), sw) - preflevel.begin() - 1;
            if(idx>=0){
                ans=max(ans,x*(idx+1));
                //cout<<x<<" "<<idx<<endl;
            }
        }
        cout<<ans<<endl;
    }
}