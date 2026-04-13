#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,m,ele=-1,cnt=1,ans=0;
        cin>>n>>m;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]==ele){
                cnt++;
            }
            else{
                ele=arr[i];
                cnt=1;
            }
            ans=max(ans,cnt);
        }
        if(ans<m) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}