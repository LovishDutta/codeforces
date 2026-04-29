#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int k,x,a,loss=0;
        cin>>k>>x>>a;
        for(int i=0;i<=x;i++){
            int c=(loss/(k-1))+1;
            loss+=c;
            if(loss > a) break;
        }
        if(a>=loss) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}