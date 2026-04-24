#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod=1e9+7;
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,cnt=0,mini;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
             cin>>arr[i];
             if(i==0) mini=arr[0];
             else mini=(mini&arr[i]);
        }
        vector<int> fact(n+1);
        fact[0]=1;
        for(int i=1;i<=n;i++) fact[i]=(fact[i-1]*i)%mod;
        for(int i=0;i<n;i++) if(arr[i]==mini) cnt++;
        cout<<(((cnt*(cnt-1))%mod)*(fact[n-2]))%mod<<endl;
    }
}