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
        while(true){
            bool flag=false;
            for(int i=0;i<n;i++){
                if(arr[i]==-1) continue;
                for(int j=0;j<n;j++){
                    if(arr[j]==-1) continue;
                    if((arr[i]&arr[j])==0){
                        arr[i]=arr[i]+arr[j];
                        arr[j]=-1;
                        ans++;
                        flag=true;
                        break;
                    }
                }
                //if(flag) break;
            }
            if(!flag||ans==n-1) break;
        }
        //cout<<ans<<endl;
        if(ans==n-1) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}