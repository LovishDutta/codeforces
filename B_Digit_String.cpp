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
        s.push_back('1');
        int n=s.size(),flag=0,cnt=0,cnt2=0,cnt3=0,cnt4=0;
        for(int i=0;i<n;i++){
            if(s[i]=='4') cnt++;
            else if(flag&&s[i]=='2') cnt2++;
            else if(s[i]=='1'||s[i]=='3'){
                if(cnt2>0){
                    if(cnt2>cnt3){
                        cnt+=cnt3;
                        cnt3=0;
                        cnt2=0;
                    }
                }
                flag=true;
                cnt3++;
            }
        }
        cout<<cnt+cnt2<<endl;
    }
}