#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n,c;
        cin>>n>>c;
        int ans=0;
        vector<int> arr(n+1); 
        vector<int> st;
        st.push_back(-1e15);
        for(int i=1;i<=n;i++){
            cin>>arr[i];
            st.push_back(arr[i]+min(i,n-i+1));
        }
        sort(st.begin(),st.end());
        vector<int> pref(n+1,0);
        for(int i=1;i<=n;i++){
            pref[i]=pref[i-1]+st[i];
        }
        for(int i=1;i<=n;i++){
            int start=arr[i]+i;  
            int idx=lower_bound(st.begin(),st.end(),arr[i]+min(i,n-i+1))-st.begin();
            
            int low=1;
            int high=idx-1;
            int cnt=0;
            int cost=c;
            if(cost>=start){
                cost-=start;
                cnt++;
                
                while(low<=high){
                    int mid=(low+high)/2;
                    if(pref[mid]>cost) high=mid-1;
                    else low=mid+1;
                }
                if(high>=1){
                    cost-=pref[high];
                    cnt+=high;
                }
                low=idx+1;
                high=n;
                while(low<=high){
                int mid=(low+high)/2;
                if(pref[mid]>cost+pref[idx]) high=mid-1;
                else low=mid+1;
            }
            
            if(high>=idx+1) cnt+=high-idx; 
            }
            ans=max(ans,cnt);
        }
        cout<<ans<<endl;
    }
}