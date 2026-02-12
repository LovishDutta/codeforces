#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
    int n;
    cin>>n;
    vector<int> arr(n);
    vector<int> sum(n,0);
    vector<int> sum2(n,0);
    for(int i=0;i<n;i++) cin>>arr[i];
    sum[0]=arr[0];
    sum2[0]=arr[0];
    for(int i=1;i<n;i++) sum[i]=arr[i]+sum[i-1];
    for(int i=1;i<n;i++){
        sum2[i]=abs(arr[i])+sum2[i-1];
    }
    int ans=sum[0]-sum[n-1];
    for(int i=1;i<n;i++){
        ans=max(ans,(sum2[i-1])+(sum[i]-sum[n-1]));
    }
    cout<<ans<<endl;
    }
}