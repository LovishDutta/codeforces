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
        for(int i=0;i<s.size();i++){
            if(s[i]>='A'&&s[i]<='Z') s[i]+=32;
        }
        vector<int> freq(26,0);
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
        }
        sort(freq.begin(),freq.end());
        cout<<freq[25]+freq[24]<<endl;
    }
}