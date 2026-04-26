#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,f=0;
        cin>>n;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            if(a==100) f=1;
        }
        if(f) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}