#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,k;
        cin>>n>>k;
        if(k<n||k>=2*n){
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
        if(n==3&&k==5){
            cout<<"1 2 3 1 2 3"<<endl;
            continue;
        }
        if(k<=n+n/2){
            int req=k-n;
            for(int i=1;i<2*req+1;i+=2){
                cout<<i<<" "<<i+1<<" "<<i<<" "<<i+1<<" ";
            }
            for(int i=2*req+1;i<=n;i++){
                cout<<i<<" "<<i<<" ";
            }
            cout<<endl;
        }
        else{
            vector<int> ans(2*n);
            ans[0]=1;
            ans[1]=2;
            ans[2*n-1]=n;
            ans[2*n-2]=n-1;
            int val=3,val2=1,req=2*n-1-k,idx=3;
            for(int i=2;i<2*n-3;i+=2) ans[i]=val++;
            for(int i=3;i<=2*n-3;i+=2) ans[i]=val2++;
            while(req>0){
                swap(ans[idx],ans[idx+1]);
                req--;
                idx+=4;
            }
            for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
            cout<<endl;
        }
    }
}