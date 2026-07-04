#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,flag=1;
        cin>>n;
        vector<int> a(n),b(n),c(n);
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++){
            cin>>b[i];
            c[i]=b[i]-a[i];
        }
        for(int i=n-1;i>=1;i--){
            if(c[i]<0){
                c[i-1]+=c[i];
            }
        }
        if(c[0]<0) flag=0;
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}