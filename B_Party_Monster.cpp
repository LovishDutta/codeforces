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
        int cnt1=0,cnt2=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') cnt1++;
            else cnt2++;
        }
        if(cnt1==cnt2) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}