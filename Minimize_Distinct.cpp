#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,cnt=0;
        cin>>n;
        vector<int> arr(n);
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(vis[arr[i]-1]==0) cnt++;
            vis[arr[i]-1]=1;
        }
        int idx1=-1,idx2=-1;
        for(int i=n-1;i>=2;i--){
            if(vis[i]==1&&vis[i-2]==1){
                idx2=i-2;
                break;
            }
        }
        for(int i=n-1;i>=3;i--){
            if(vis[i]==1&&vis[i-1]==1&&vis[i-2]==1&&vis[i-3]==1){
                idx1=i-3;
                break;
            }
        }
        for(int i=0;i<n;i++){
            if(idx1>=i){
                cout<<max(0LL,cnt-2)<<" ";
            }
            else if(idx2>=i){
                cout<<cnt-1<<" ";
            }
            else cout<<cnt<<" ";
        }
        cout<<endl;
    }
}