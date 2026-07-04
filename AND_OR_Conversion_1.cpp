#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,idx=0;
        cin>>n;
        string a,b;
        cin>>a>>b;
        for(int i=0;i<n;i++){
            while(idx<n&&b[idx]==a[i]){
               idx++; 
            }
        }
        if(idx==n) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}