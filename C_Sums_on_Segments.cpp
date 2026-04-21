#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,idx=-1,mini=0,maxi=0;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]!=1&&arr[i]!=-1) idx=i;
        }
        if(idx!=-1){
            int sum=0,sum2=0,sum3=0,mm=0,mn=0,mm2=0,mn2=0;
            for(int i=idx-1;i>=0;i--){
                sum+=arr[i];
                sum2+=arr[i];
                sum3+=arr[i];
                if(sum>0) sum=0;
                if(sum2<0) sum2=0;
                mini=min(mini,sum);
                maxi=max(maxi,sum2);
                mm=max(mm,sum3);
                mn=min(mn,sum3);
            }
            sum=0,sum2=0,sum3=0;
            for(int i=idx+1;i<n;i++){
                sum+=arr[i];
                sum2+=arr[i];
                sum3+=arr[i];
                if(sum>0) sum=0;
                if(sum2<0) sum2=0;
                mini=min(mini,sum);
                maxi=max(maxi,sum2);
                mm2=max(mm2,sum3);
                mn2=min(mn2,sum3);
            }
            set<int> st;
            for(int i=mini;i<=maxi;i++) st.insert(i);
            for(int i=mn+mn2;i<=mm+mm2;i++) st.insert(i+arr[idx]);
            cout<<st.size()<<endl;
            for(auto &it:st) cout<<it<<" ";
            cout<<endl;
        }
        else{
            int sum=0,sum2=0;
            for(int i=0;i<n;i++){
                sum+=arr[i];
                sum2+=arr[i];
                if(sum>0) sum=0;
                if(sum2<0) sum2=0;
                mini=min(mini,sum);
                maxi=max(maxi,sum2);
            }
            cout<<(maxi-mini+1)<<endl;
            for(int i=mini;i<=maxi;i++) cout<<i<<" ";
            cout<<endl;
        }
    }
}