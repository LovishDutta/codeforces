#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    stack<pair<int,int>> st;
    int n=s.size(),cnt=0,len=0,cnt2=0;
    vector<int> ans(n+1,0);
    for(int i=0;i<n;i++){
        if(s[i]=='(') st.push({0,i});
        else{
            if(st.size()>0&&st.top().first==0){
                ans[st.top().second]+=1;
                ans[i+1]-=1;
                st.pop();
            }
            else st.push({1,i});
        }
    }
    for(int i=1;i<ans.size();i++) ans[i]+=ans[i-1];
    for(int i=0;i<ans.size();i++){
        if(ans[i]) cnt++;
        else cnt=0;
        len=max(len,cnt);
    }
    for(int i=0;i<ans.size();i++){
        if(ans[i]) cnt++;
        else cnt=0;
        if(cnt==len) cnt2++;
    }
    if(len==0) cout<<0<<" "<<1;
    else cout<<len<<" "<<cnt2;
}