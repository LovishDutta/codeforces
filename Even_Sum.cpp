#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,ans=0;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=0;j<n;j++){
                if(i==j) continue;
                sum+=arr[j];
            }
            if(sum%2==0){
                ans=1;
                break;
            }
        }
        if(ans) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}