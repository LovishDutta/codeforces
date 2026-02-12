#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                for(int j=i;j<n&&j<i+k+1;j++){
                    if(s[j]=='0') s[j]='2';
                }
            }
            
        }
        for(int i=0;i<n;i++) if(s[i]=='0') ans++;
        cout<<ans<<endl;
    }
}