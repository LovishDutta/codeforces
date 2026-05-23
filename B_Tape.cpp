#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> arr(n),temp;
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n-1;i++) temp.push_back(arr[i+1]-arr[i]);
    int ans=n,rem=n-k;
    sort(temp.begin(),temp.end());
    for(int i=0;i<rem;i++){
        ans+=(temp[i]-1);
    }
    cout<<ans<<endl;
}