#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
int n;
cin>>n;
vector<int> arr(n);
for(int i=0;i<n;i++) cin>>arr[i];
vector<int> ans(n,0);
int cnt=0;
for(int i=1;i<n;i++){
    ans[i]=min(arr[i],i-cnt);
    if(arr[i]<=i-cnt) cnt++;
}
for(int i=0;i<n;i++) cout<<ans[i]<<" ";
cout<<endl;
    }
}