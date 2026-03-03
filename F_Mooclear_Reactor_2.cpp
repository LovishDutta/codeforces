#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,m;
        cin>>n>>m;
        vector<pair<int,int>> arr(n);
        vector<pair<int,int>> q(m);
        for(int i=0;i<n;i++) cin>>arr[i].first>>arr[i].second;
        for(int i=0;i<m;i++) cin>>q[i].first>>q[i].second;
        vector<int> pl(n+2,0);
        vector<int> last(n+1,0);
        sort(arr.rbegin(),arr.rend());
        int i=0,start=0;
        vector<int> cnt(n+2,0);
        for(int i=0;i<n;i++){
            if(arr[i].second<start) continue;
            pl[start]+=arr[i].first;
            pl[arr[i].second+1]-=arr[i].first;
            cnt[start]++;
            cnt[arr[i].second+1]--;
            if(cnt[start]>start){
                last[start]=arr[i].first;
                start++;
                if(start>0) cnt[start]+=cnt[start-1];
            }
        }
        int maxi=pl[0];
        last[0]=pl[0]-last[0];
        for(int i=1;i<=n;i++){
            pl[i]+=pl[i-1];
            maxi=max(maxi,pl[i]);
            last[i]=max(last[i-1],pl[i]-last[i]);
        }
        for(int i=0;i<m;i++) cout<<max(maxi,last[q[i].second]+q[i].first)<<" ";
        cout<<endl;
    }
}