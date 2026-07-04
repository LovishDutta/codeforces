#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;
    vector<int> spf(1e6+1);
    for(int i=1;i<=1e6;i++) spf[i]=i;
    for(int i=2;i<=1e6;i++){
        if(spf[i]==i){
            for(int j=i*i;j<=1e6;j+=i){
                if(spf[j]==j) spf[j]=i;
            }
        }
    }    
    while(tc--){
        int n,sum=0;
        cin>>n;
        map<int,int> mpp;
        while(n>1){
            mpp[spf[n]]++;
            n=n/spf[n];
        }
        for(auto &it:mpp) sum+=it.second;
        cout<<(mpp.size()+sum-1)<<endl;
    }
}