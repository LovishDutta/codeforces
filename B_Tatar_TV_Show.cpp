#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,k,cnt=0;
        cin>>n>>k;
        string s;
        cin>>s;
        for(int i=0;i<n-k;i++){
            if(s[i]=='1'){
                s[i]='0';
                if(s[i+k]=='1') s[i+k]='0';
                else s[i+k]='1';
            }
        }
        //cout<<s<<endl;
        for(int i=0;i<n;i++) if(s[i]=='1') cnt++;
        if(cnt!=0) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}