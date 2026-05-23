#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,m;
        cin>>n>>m;
        if(n<=2){
            if(n==1) cout<<-1<<endl;
            else for(int i=0;i<n;i++) cout<<1<<" ";
            cout<<endl;
            continue;
        }
        vector<int> ans;
        while(ans.size()<n){
            ans.push_back(1);
            ans.push_back(1);
            ans.push_back(0);
            ans.push_back(m-1);
            ans.push_back(m-1);
            ans.push_back(0);
        }
        while(ans.size()>n) ans.pop_back();
        if(ans[n-2]!=ans[n-1]){
            cout<<-1<<endl;
            continue;
        }
        for(int i=0;i<n;i++) cout<<ans[i]<<" ";
        cout<<endl;
    }
}