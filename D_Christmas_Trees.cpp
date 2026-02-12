#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    //cin>>tc;    
    while(tc--){
        int n,m,sum=0;
        cin>>n>>m;
        map<int,int> mpp;
        vector<int> arr(n);
        queue<pair<int,int>> q;
        vector<int> ans;
        for(int i=0;i<n;i++){
             cin>>arr[i];
             mpp[arr[i]]++;
             q.push({arr[i],0});
        }
        while(!q.empty()){
            int k=q.size();
            for(int i=0;i<k;i++){
                int ele=q.front().first;
                int cnt=q.front().second;
                q.pop();
                if(cnt!=0) ans.push_back(ele);
                sum+=cnt;
                if(ans.size()==m) break;
                if(mpp.find(ele+1)==mpp.end()){
                    q.push({ele+1,cnt+1});
                    mpp[ele+1]++;
                }
                if(mpp.find(ele-1)==mpp.end()){
                    q.push({ele-1,cnt+1});
                    mpp[ele-1]++;
                }
            }
            if(ans.size()==m) break;
        }
        cout<<sum<<endl;
        for(int i=0;i<m;i++) cout<<ans[i]<<" ";
    }
}