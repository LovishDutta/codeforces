#include<bits/stdc++.h>
using namespace std;
#define int long long
int score(string s, string a, int idx) {
    int open= 0;
    int matched= 0;
    
    for (int i = 0; i < s.size(); i++) {
        if (a[i] == '1' || i == idx) continue;
        
        if (s[i] == '(') {
            open++;
        } else if (s[i] == ')') {
            if (open > 0) {
                open--;
                matched += 2;
            }
        }
    }
    return matched;
}

int cntr(string s, string a, int idx) {
    int mx = score(s, a, idx);
    if (mx == 0) return 0;

    int open = 0;
    int pair = 0;

    for (int i = 0; i < s.size(); i++) {
        if (a[i] == '1' || i == idx) continue;

        if (s[i] == '(') {
            open++;
        } else if (s[i] == ')') {
            if (open > 0) {
                open--;
                pair++;
            }
        }
    }
    return pair;
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,k;
        cin>>n>>k;
        string s,s2;
        cin>>s;
        string ans(n,'0');
        int val=score(s,ans,-1);
        for(int i=0;i<n;i++){
            if(k==0) break;
            int a=score(s,ans,i);
            if(a<val){
                ans[i]='1';
                val=a;
                k--;
            }
            
        }
        // int cnt=cntr(s,ans,-1);
        // for(int i=0;i<n;i++){
        //     if(k==0) break;
        //     if(ans[i]=='1') continue;
        //     int b=cntr(s,ans,i);
        //     if(b<cnt){
        //         ans[i]='1';
        //         k--;
        //         cnt=b;
        //     }
        // }
        cout<<ans<<endl;
    }
}