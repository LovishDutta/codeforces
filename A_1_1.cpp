#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        for(int i=1;i<n-1;i++){
            if(s[i-1]=='1'&&s[i+1]=='1') s[i]='1';
            // if(s2[i-1]=='1'&&s2[i+1]=='1') s2[i]='1';
        }
        int cnt1=0,cnt2=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1') cnt1++;
        }
        string s2=s;
        for(int i=1;i<n-1;i++){
             if(s2[i-1]=='1'&&s2[i+1]=='1') s2[i]='0';
        }
        for(int i=0;i<n;i++){
            if(s2[i]=='1') cnt2++;
        }
        cout<<cnt2<<" "<<cnt1<<endl;
    }
}