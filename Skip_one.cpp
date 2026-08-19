#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,k,fl=1,cnt=0,sum=0,maxi=0;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        for(int i=0;i<n;i++){
            if(arr[i]<=k){
                cnt++;
                k-=arr[i];
                maxi=max(maxi,arr[i]);
            }
            else{
                if(fl){
                    maxi=max(maxi,arr[i]);
                    k+=maxi;
                    k-=arr[i];
                    fl=0;
                    cnt++;
                }
                else{
                    break;
                }
            }
        }
        cout<<cnt<<endl;
    }
}