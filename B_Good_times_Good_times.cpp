#include<bits/stdc++.h>
using namespace std;
#define int long long
bool funct(int n){
    map<int,int> mpp;
    while(n>0){
        mpp[n%10]++;
        n/=10;
        if(mpp.size()>2) return false;
    }
    return true;
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int x,ans=-1;
        cin>>x;
        for(int i=2;i<=11;i++){
            if(funct(x*i)){
                ans=i;
                break;
            }
        }
        for(int i=10;i<=1e8;i*=10){
            if(funct(x*(i+1))){
                ans=i+1;
                break;
            }
        }
        cout<<ans<<endl;
    }
}