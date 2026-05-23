#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod=1e9+7;
int base=31;
int mod2=1e9+9;
int base2=57;
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    //cin>>tc;    
    while(tc--){
        string s,c;
        cin>>s>>c;
        int n=s.size(),k;
        cin>>k;
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            int cnt=0,hash=0,hash2=0;
            for(int j=i;j<n;j++){
                hash=(hash*base+(s[j]-'a')+1)%mod;
                hash2=(hash2*base2+(s[j]-'a')+1)%mod2;
                if(c[s[j]-'a']=='0') cnt++;
                if(cnt>k) break;
                st.insert((hash<<32)^hash2);
            }
        } 
        cout<<st.size()<<endl;
    }
}