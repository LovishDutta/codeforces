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
        int cnt=0,ze=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1') cnt++;
            else{
                int z=0;
                while(i<n&&s[i]=='0'){
                    i++;
                    z++;
                }
                ze=max(z,ze);
                i--;
            }
        }
        cout<<(cnt+ze)<<endl;
    }
}