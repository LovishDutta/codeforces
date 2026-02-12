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
       int ans=0;
       int i=0;
       while(i<n){
        s+=s[i];
        if(s[i]=='1') break;
        i++;
       }
       int prev=-1;
       for(i=0;i<s.size();i++){
        if(s[i]=='1'){
            if(prev==-1) prev=i;
            else{
                ans=max(ans,i-prev-1);
                prev=i;
            }
        }
       }
        cout<<ans<<endl;
    }
}