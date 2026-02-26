#include<bits/stdc++.h>
using namespace std;
#define int long long
bool check(int mid,vector<pair<int,int>>& newarr){
    int extra = 0;
    for(int i=0;i<newarr.size();i++){
        if(newarr[i].second>mid){extra += (int)(1LL<<newarr[i].first) *(newarr[i].second-mid);
        }
        else if(extra>0){
            extra -= (int)(1LL<<newarr[i].first) *(mid-newarr[i].second);
            extra=max(extra,0LL);
        }
    }
    return extra<=0;
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,m,ans=0,prev=-1;
        cin>>n>>m;
        int last=63 - __builtin_clzll(n);
        vector<int> req(64,0);
        for(int i=0;i<=last;i++){
            if((m&(1LL<<i))>0) prev=i;
            if((n&(1LL<<i))>0){
                if(prev==-1){
                    ans=-1;
                    break;
                }
                if((m&(1LL<<i))==0){
                    req[prev]+=(1LL<<(i))/(1LL<<(prev));
                }
                else req[i]+=1;
            }
        }
        if(ans==-1){
            cout<<-1<<endl;
            continue;
        }
        vector<pair<int,int>> newarr;
        for(int i=63;i>=0;i--){
            if(req[i]>0||(m&(1LL<<i))>0) newarr.push_back({i,req[i]});
        }
        int low=0,high=1e18;
        while(low<=high){
            int mid=(low+high)/2;
            if(check(mid,newarr)) high=mid-1;
            else low=mid+1;
        }
        cout<<low<<endl;
        
    }
}