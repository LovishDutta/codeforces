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
        string s,ans="";
        cin>>s;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                ans.push_back('1');
                while(i+1<n&&s[i+1]=='1') i++;
            }
            if(s[i]=='0'){
                ans.push_back('0');
                while(i+1<n&&s[i+1]=='0') i++;
            }
        }
        reverse(ans.begin(),ans.end());
        while(ans.size()<n) ans.push_back('0');
        reverse(ans.begin(),ans.end());
        cout<<ans<<endl;

    }
}