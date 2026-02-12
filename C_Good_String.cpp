#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        string s;
        cin>>s;
        int ans=s.size();
        for(char c='0';c<='9';c++){
            for(char d='0';d<='9';d++){
                bool flag=true;
                int cnt=0;
                for(int i=0;i<s.size();i++){
                    if(flag&&s[i]==c) flag=false;
                    else if(!flag&&s[i]==d) flag=true;
                    else cnt++;
                }
                if(!flag&&c!=d) cnt++;
                ans=min(ans,cnt);
            }
        }
        cout<<ans<<endl;
    }
}