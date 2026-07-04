#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,flag=0,cnt=0;
        cin>>n;
        string s;
        cin>>s;
        for(int i=0;i<n;i++){
            if(s[i]=='1') cnt++;
            else if(cnt%2) flag=1;
        }
        cnt=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0') cnt++;
            else if(cnt%2) flag=1;
        }
        if(flag) cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;
    }
}