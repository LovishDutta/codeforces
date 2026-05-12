#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,k,cnt=0,mini=1e9,i1=0,i2=0;
    cin>>n>>k;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    for(int i=0;i<n;i++){
        int idx=lower_bound(b.begin(),b.end(),k-a[i])-b.begin();
        if(idx<n){
            if(a[i]+b[idx]<mini){
                mini=a[i]+b[idx];
                i1=i;
                i2=idx;
            }
        }
    }
    a[i1]=1e9;
    b[i2]=1e9;
    int e=n-2;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    for(int i=0;i<n-1;i++){
        if(b[i]+a[e]<k) cnt++;
        else e--;
    }
    cout<<1<<" "<<(n-cnt);
}