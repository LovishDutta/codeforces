#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n;
        cin>>n;
        string s;
        cin>>s;
        s.push_back('0');
        int ans=0;
        for(int i=0;i<n;i++) if(s[i]=='1') ans++;
        bool flag=true;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(flag){
                if(s[i]=='0'&&s[i+1]=='0') cnt++;
                else{
                    ans+=ceil(cnt/3.0);
                    cnt=0;
                    flag=false;
                }
            }
            else{
                if(s[i]=='0') flag=true;
                else flag=false;
            }
        }
        if(flag) ans+=ceil(cnt/3.0);
        cout<<ans<<endl;
    }
}