#include<bits/stdc++.h>
using namespace std;
#define int long long
map<pair<int,int>,int> mpp;
int mod=1e9+7;
int recur(int idx,int sum,vector<int>& arr){
    if(arr.size()==idx) return sum==0;
    if(mpp.find({idx,sum})!=mpp.end()) return mpp[{idx,sum}];
    int pi=recur(idx+1,sum+arr[idx],arr)%mod;
    int npi=recur(idx+1,sum,arr)%mod;
    return mpp[{idx,sum}]=(pi+npi)%mod;
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        mpp.clear();
        cout<<recur(0,0,arr)<<endl;
    }
}