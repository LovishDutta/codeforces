#include<bits/stdc++.h>
using namespace std;
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,ans=1e9,l=15000000,gc;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){ 
        cin>>arr[i];
        if(i==0) gc=arr[0];
        else gc=__gcd(gc,arr[i]);
    }
    vector<int> spf(l+1);
    for(int i=1;i<=l;i++) spf[i]=i;
    for(long long i=2;i*i<=l;i++){
        if(spf[i]==i){
            for(long long j=i*i;j<=l;j+=i){
                if(spf[j]==j) spf[j]=i;
            }
        }
    }
    unordered_map<int,int> mpp;
    for(int i=0;i<n;i++){
        int x=arr[i]/gc;
        while(x>1){
            int f=spf[x];
            mpp[spf[x]]++;
            while(x%f==0) x/=f;
        }
    }
    for(auto &it:mpp){
        ans=min(ans,n-it.second);
    }
    cout<<(ans==1e9?-1:ans)<<endl;
}