#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n;
        cin>>n;
        vector<int> arr(n),temp(n),ans;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            temp[i]=arr[i];
        }
        for(int i=0;i<n;i++) temp.push_back(arr[i]);
        for(int i=0;i<n;i++){
            vector<int> a(n);
            int k=0;
            a[0]=0;
            for(int j=i+1;j<i+n;j++){
                a[j-i]=max(a[j-1-i],temp[j-1]);
            }
            a[n-1]=min(a[n-1],temp[i+n-1]);
            for(int j=n-1;j>0;j--){
                int val=max(a[j],a[j-1]);
                if(a[j]!=a[j-1]&&val>temp[i+j-1]){
                    a[j-1]=max(temp[i+j-1],a[j]);
                }
            }
            for(int j=0;j<n;j++){
                k+=a[j];
              // if(i==3) cout<<a[j]<<endl;
            }
            ans.push_back(k);
        }
        for(int i=0;i<n;i++) cout<<ans[i]<<" ";
        cout<<endl;
    }
}