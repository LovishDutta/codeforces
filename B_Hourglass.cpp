#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int s,m,k;
        cin>>s>>k>>m;
        if(k>s){
            cout<<(s-(m%k)>0?s-(m%k):0)<<endl;
        }
        else{
            if((m/k)%2==0) cout<<s-(m%k)<<endl;
            else cout<<((k)-(m%k)>0?(k)-(m%k):0)<<endl;
        }
    }
}