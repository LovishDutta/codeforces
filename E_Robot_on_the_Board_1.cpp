#include<bits/stdc++.h>
using namespace std;
#define int long long
int f(string s,int n){
    int init=1,pos=1,maxi=0,mini=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='0'){
            if(pos+1>n) break;
            else pos++;
        }
        else{
            if(pos-1<=0){
                if(init+1+maxi<=n) init++;
                else break;
            }
            else pos--;
        }
        maxi=max(maxi,pos-init);
    }
    return init;
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,m;
        cin>>n>>m;
        string s;
        cin>>s;
        string s1,s2;
        for(int i=0;i<s.size();i++){
            if(s[i]=='L') s1.push_back('1');
            else if(s[i]=='R') s1.push_back('0');
            else if(s[i]=='D') s2.push_back('0');
            else if(s[i]=='U') s2.push_back('1');
        }
        cout<<f(s2,n)<<" "<<f(s1,m)<<endl;
    }
}