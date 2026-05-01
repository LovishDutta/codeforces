#include<bits/stdc++.h>
using namespace std;
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,k,ans=1e9,cnt=1;
    map<int,multiset<int>> mpp;
    cin>>n>>k;
    vector<int> arr(n);
    vector<int> arr2(2e5+1,0),cost(2e5+1);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        arr2[arr[i]]++;
        if(arr2[arr[i]]>=k) ans=0;
    }
    sort(arr.rbegin(),arr.rend());
    while(arr[0]!=0){
        for(int i=0;i<n;i++){
            if(arr[i]==0) break;
            arr2[arr[i]/2]++;
            cost[arr[i]/2]+=cnt;
            if(arr2[arr[i]/2]>=k){
                ans=min(ans,cost[arr[i]/2]);
            }
            arr[i]/=2;
        }
        cnt++;
    }
    cout<<ans<<endl;
}