#include<bits/stdc++.h>
using namespace std;
#define int long long
int stps(int x){
    return __builtin_ctzll(x) + 1;
}
int funct(int prev,int ele){
    int cnt=1,cur=prev+1;
    while(cur<ele){
        int steps=stps(cur);
        if(steps+cur<=ele){
            cur=cur+steps;
        }
        else{
            cur++;
            cnt++;
        }
    }
    return cnt;
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;   
    vector<int> p(33);
    p[0]=1;
    for(int i=1;i<=32;i++) p[i]=2LL*p[i-1]; 
    while(tc--){
        int n,k,h,ans=0;
        cin>>n>>k>>h;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        for(int i=1;i<n;i++){
            if(arr[i]<=arr[i-1]){
                ans+=k*(arr[i-1]-arr[i]);
            }
            else{
                int idx=lower_bound(p.begin(),p.end(),arr[i])-p.begin();
                if(p[idx]!=arr[i]){
                    int prev=p[idx-1];
                    int steps=funct(prev,arr[i]);
                    ans+=min(h*steps,k*(p[idx]-arr[i]));
                }
            }
        }
        cout<<ans<<endl;
    }
}