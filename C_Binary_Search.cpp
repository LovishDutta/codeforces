#include<bits/stdc++.h>
using namespace std;
int main(){
    int mod=1e9+7;
        int n,x,pos;
        cin>>n>>x>>pos;
        int l=0,r=n,s=x-1,large=n-x,cnt=0;
        long long ans=1;
        while(l<r){
            int mid=(l+r)/2;
            if(mid<pos){
                ans=(ans*s)%mod;
                s--;
                l=mid+1;
                cnt++;
            }
            else if(mid>pos){
                ans=(ans*large)%mod;
                large--;
                r=mid;
                cnt++;
            }
            else{
                l=mid+1;
            }
            if(!ans) break;
        }
        if(!ans) cout<<0<<endl;
        else{
            for(int i=n-cnt-1;i>=1;i--){
                ans=(ans*i)%mod;
            }
            cout<<ans<<endl;
        }
}