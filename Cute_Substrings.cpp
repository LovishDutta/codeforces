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
        int ans=0;
        for(int i=0;i<n;i++){
            int len=0;
            for(int j=i;j<n;j++){
                if((j-i)%2==0&&(s[j]=='u'||s[j]=='o')){
                    len++;
                }
                else if((j-i)%2==1&&(s[j]=='w')) len++;
                else break;
                if(len%2==1) ans=max(ans,len);
            }
        }
        cout<<ans<<endl;
    }
}