#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    //cin>>tc;    
    while(tc--){
        int n,ans=0;
        string s;
        cin>>n;
        map<int,int> mpp;
        for(int i=0;i<n;i++){
            cin>>s;
            int a=0;
            for(auto &it: s) a=(a^(1<<(it-'a')));
            mpp[a]++;
        }
        for(auto &it: mpp){
            ans+=(it.second*(it.second-1))/2;
            for(int i=0;i<26;i++){
                if(((it.first^(1<<i))>it.first)&&mpp.find(it.first^(1<<i))!=mpp.end()) ans+=(it.second*mpp[(it.first^(1<<i))]);
            }
        }
        cout<<ans<<endl;
    }
}