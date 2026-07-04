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
        string a;
        for(int i=0;i<n;i++){
            if(a.size()==0||a[a.size()-1]!=s[i]){
                a.push_back(s[i]);
            }
            if(a.size()>2) break;
        }
        if(a.size()==2) cout<<2<<endl;
        else cout<<1<<endl;
    }
}