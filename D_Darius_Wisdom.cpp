/*
   Author: SONIT RAJ
    created: 10:31:53 24-02-2026
*/


#include<bits/stdc++.h>
using namespace std;
// ╭──────────────────────────────╮
// │        SOLVER ZONE           │
// ╰──────────────────────────────╯
void solve(){

    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    set<int>s0,s1,s2;
    vector<pair<int,int>>ans;
    for(int i=0;i<n;i++){
        if(a[i]==2)s2.insert(i);
        if(a[i]==1)s1.insert(i);
        if(a[i]==0)s0.insert(i);
    }
    int des=0;
    for(auto &x:s0){
        if(s1.count(des)){
            s1.erase(des);
            s0.insert(des);
            s1.insert(x);
            s0.erase(x);
            ans.push_back({des+1,x+1});
        }
        else if(s2.count(des)){
            s2.erase(des);
            s0.insert(des);
            s1.insert(x);
            s0.erase(x);
            ans.push_back({des+1,x+1});
        }
        des++;
    }
    






}
// ╭──────────────────────────────╮
// │             MAIN             │
// ╰──────────────────────────────╯
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // precomp_fact();  // Enable if using nCr or factorials
    int _=1;
    cin>>_;
    while(_--){
        solve();
    }
}