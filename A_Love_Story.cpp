#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        string s;
        cin>>s;
        string s2="codeforces";
        int cnt=0;
        for(int i=0;i<10;i++) if(s[i]!=s2[i]) cnt++;
        cout<<cnt<<endl;
    }
}