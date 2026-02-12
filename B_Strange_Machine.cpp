#include<bits/stdc++.h>
using namespace std;
int num(string&s ,int a){
    int ans=0;
    int i=0;
    while(a!=0){
        if(i==s.size()) i=0;
        if(s[i]=='B') a=a/2;
        else a-=1;
        i++;
        ans++;
    }
    return ans;
}
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n,q;
        cin>>n>>q;
        string s;
        cin>>s;
        vector<int> a(q);
        for(int i=0;i<q;i++) cin>>a[i];
        int cnt=0;
        for(auto& it:s) if(it=='A') cnt++;
        vector<int> ans(q);
        if(cnt==n){
             for(int i=0;i<q;i++){
            ans[i]=a[i];
        }
        }
        else{
            for(int i=0;i<q;i++){
               
                ans[i]=num(s,a[i]);
            }
        }
         for(int i=0;i<q;i++) cout<<ans[i]<<endl;
    }
}