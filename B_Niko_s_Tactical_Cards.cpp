#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n;
        cin>>n;
        vector<int> a(n);
        vector<int> b(n);
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];
        int posk=0;
        int negk=0;
        for(int i=0;i<n;i++){
          int l=posk-a[i];
          int m=negk-a[i];
          int n=b[i]-negk;
          int o=b[i]-posk;
          posk=max(max(l,m),max(n,o));
          negk=min(min(l,m),min(n,o));
        }
        cout<<posk<<endl;
    }
}