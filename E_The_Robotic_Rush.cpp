#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n,m,k;
        cin>>n>>m>>k;
    vector<int> arr(n), b(m);
    for (int i = 0; i < n; i++) cin>>arr[i];
    for (int i = 0; i < m; i++) cin>>b[i];
    sort(arr.begin(),arr.end());
    sort(b.begin(),b.end());
    string s;
    cin>>s;
    vector<pair<int,int>> lft(n),ri(n);
    int alive = n;
    for (int i = 0; i < n; i++)
    {
        int ind = lower_bound(b.begin(),b.end(),arr[i]) - b.begin();
        int ind2 = ind-1;
        
        if(ind<m){
            ri[i] = {abs(arr[i] - b[ind]),i};
        }
        else ri[i] = {1e16,i};
        if(ind2>=0&&ind2<m) lft[i] = {abs(arr[i] - b[ind2]),i};
        else lft[i] = {1e16,i};
    }

    sort(lft.begin(),lft.end());
    sort(ri.begin(),ri.end());
    
    int start = 0;
    int lp = 0, rp = 0;
    vector<int> vis(n,0);
    for (int i = 0; i < k; i++)
    {
        if(alive>0){
            if(s[i]=='L') start--;
            else start++;
            if(start<0){
                while(lp<n&&lft[lp].first<=abs(start)) {
                    if(vis[lft[lp].second]) {lp++; continue;}
                    vis[lft[lp].second] = true;
                    alive--;
                    lp++;
                }
            }
            else{
                while(rp<n&&ri[rp].first<=abs(start)) {
                    if(vis[ri[rp].second]){rp++; continue;}
                    vis[ri[rp].second] = true;
                    alive--;
                    rp++;
                }
            }
        }
        if(alive>0) cout<<alive<<" ";
        else cout<<0<<" ";
    }
    cout<<endl;
    }
}