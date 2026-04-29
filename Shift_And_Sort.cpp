#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,f=1,prev=0;
        cin>>n;
        vector<int> arr(n);
        vector<int> vis(n,0);
        for(int i=0;i<n;i++) cin>>arr[i];
        for(int i=0;i<n-2;i++){
            if(arr[i]>arr[i+1]&&arr[i+1]>arr[i+2]){
                f=0;
                break;
            }
        }
        for(int i=0;i<n-1;i++){
            if(arr[i]>arr[i+1]){
                if(vis[i]==true){
                    f=0;
                    break;
                }
                int avg1=(arr[i]+arr[i+1]+1)/2.0;
                int avg2=(arr[i]+arr[i+1])/2;
                int last=0;
                if(i>0) last=arr[i-1];
                if(avg2<last){
                    f=0;
                    break;
                }
                arr[i]=avg2;
                arr[i+1]=avg1;
                vis[i+1]=true;
            }
        }
        if(f) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}