#include<bits/stdc++.h>
using namespace std;
int ans[10000001];
int a[10000001];
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(int i=2;i<=1e7;i++){
        for(int j=i;j<=1e7;j+=i){
            a[j]+=i;
        }
    }
    for(int i=1;i<=1e7;i++) if(a[i]+1<=1e7&&ans[a[i]+1]==0) ans[a[i]+1]=i;
    int tc=1;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
        cout<<(ans[n]==0?-1:ans[n])<<endl;
    }
}