#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,k,x1=0,s1=0,z1=0,ans=0;
        cin>>n>>k;
        string s,z,x;
        cin>>s>>z;
        for(int i=0;i<n;i++){
            if(s[i]=='1') s1++;
            if(z[i]=='1') z1++;
            if((s[i]=='1'&&z[i]=='0')||(s[i]=='0'&&z[i]=='1')) x1++;
        }
        k=(1LL<<k)+1LL;
        if(k%3==0){
            ans=(k/3)*(s1*(n-s1)+z1*(n-z1)+x1*(n-x1));
        }
        else{
            ans=((k+1)/3)*(s1*(n-s1)+z1*(n-z1))+(k/3)*(x1*(n-x1));
        }
        cout<<ans<<endl;
    }
}