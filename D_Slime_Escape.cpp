#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,k,lmax=0,rmax=0;
        cin>>n>>k;
        vector<int> arr(n+1);
        for(int i=1;i<=n;i++) cin>>arr[i];
        int ridx=k+1,lidx=k-1,rsum=arr[k],lsum=arr[k],prevr=k+1,prevl=k-1;
        while(true){
            for(ridx;ridx<=n;ridx++){
                if(rsum+arr[ridx]+lmax>=0){
                    rsum+=arr[ridx];
                    rmax=max(rmax,rsum-arr[k]);
                }
                else break;
            }
            for(lidx;lidx>0;lidx--){
                if(lsum+arr[lidx]+rmax>=0){
                    lsum+=arr[lidx];
                    lmax=max(lmax,lsum-arr[k]);
                }
                else break;
            }
            if(ridx==n+1||lidx==0){
                cout<<"YES"<<endl;
                break;
            }
            if(ridx==prevr&&lidx==prevl){
                cout<<"NO"<<endl;
                break;
            }
            prevr=ridx;
            prevl=lidx;
        }
    }
}