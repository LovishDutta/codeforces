#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,k,sum=0,cnt=0;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
             cin>>arr[i];
             sum+=arr[i]/2;
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if((sum+arr[i]/2+arr[j]/2)>k) cnt++;
            }
        }
        cout<<cnt<<endl;
    }
}