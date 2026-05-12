#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,k,q,st;
        cin>>n>>k;
        vector<int> pos(n);
        vector<int> delay(n);
        for(int i=0;i<n;i++) cin>>pos[i];
        for(int i=0;i<n;i++) cin>>delay[i];
        cin>>q;
        for(int i=0;i<q;i++){
            cin>>st;
            int idx=lower_bound(pos.begin(),pos.end(),st)-pos.begin(),t=0,dir=1,prev=st;
            vector<int> vis(n,0);
            while(true){
                if(idx<0||idx>=n){
                    cout<<"YES"<<endl;
                    break;
                }
                t+=abs(pos[idx]-prev);
                prev=pos[idx];
                if(vis[idx]>2*k){
                    cout<<"NO"<<endl;
                    break;
                }
                vis[idx]++;
                if(t%k==delay[idx]) dir=!dir;
                if(dir) idx++;
                else idx--;
            }
        }

    }
}