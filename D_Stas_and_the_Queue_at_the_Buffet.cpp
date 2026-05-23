#include<bits/stdc++.h>
using namespace std;
#define int long long
static bool comp(pair<int,int>& a,pair<int,int>& b){
    return abs(a.first-a.second)>abs(b.first-b.second);
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    //cin>>tc;    
    while(tc--){
        int n,ans=0;
        cin>>n;
        vector<pair<int,int>> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i].first>>arr[i].second;
        }
        sort(arr.begin(),arr.end(),comp);
        int st=0,ed=n-1;
        for(int i=0;i<n;i++){
            if(arr[i].first>arr[i].second){
                ans+=(arr[i].first*(st))+(arr[i].second*(n-1-st));
                st++;
            }
            else{
                ans+=(arr[i].first*ed)+(arr[i].second*(n-1-ed));
                ed--;
            }
        }
        cout<<ans<<endl;
    }
}