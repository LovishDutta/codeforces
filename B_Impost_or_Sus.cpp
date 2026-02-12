#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        string s;
        cin>>s;
        int ans=0;
        if(s[0]=='u'){
            ans++;
            s[0]='s';
        }
        if(s[s.size()-1]=='u'){
            ans++;
            s[s.size()-1]='s';
        }
        for(int i=1;i<s.size()-1;i++){
            int j=i;
            int cnt=0;
            while(j<s.size()-1&&s[j]=='u'){
                 cnt++;
                 j++;
            }
            ans+=cnt/2;
            i=j;
        }
        cout<<ans<<endl;
    }
}