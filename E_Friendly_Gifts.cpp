#include<bits/stdc++.h>
using namespace std;
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,ans=0;
        cin>>n;
        vector<int> arr(n);
        vector<vector<int>> start(n/2+1);
        vector<vector<int>> end(n/2+1);
        for(int i=0;i<n;i++) cin>>arr[i];
        for(int i=0;i<n;i++){
            vector<int> freq(n+1);
            int maxi=arr[i],mini=arr[i];
            for(int j=i;j<n;j++){
                freq[arr[j]]++;
                maxi=max(maxi,arr[j]);
                mini=min(mini,arr[j]);
                if(freq[arr[j]]>1) break;
                int len=maxi-mini+1;
                if(len>n/2) break;
                if(len==j-i+1){
                    start[len].push_back(mini);
                    end[len].push_back(maxi);
                }
            }
        }
        for(int i=n/2;i>=1;i--){
            sort(start[i].begin(),start[i].end());
            // if(i==4){
            //     for(int i=0;i<end[4].size();i++) cout<<end[4][i]<<endl;
            // }
        }
        for(int i=n/2;i>=1;i--){
            for(auto &it:end[i]){
                int lb=lower_bound(start[i].begin(),start[i].end(),it+1)-start[i].begin();
                // if(i==4){
                //     cout<<it<<" "<<end[i][lb]<<endl;
                // }
                if(lb<start[i].size()&&start[i][lb]==it+1){
                    ans=i;
                    break;
                }
            }
            if(ans>0) break;
        }
        cout<<ans<<endl;
    }
}