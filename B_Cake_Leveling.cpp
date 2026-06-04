#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,cur=0,sum=0,extra=0;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        for(int i=0;i<n;i++){
            extra=sum-cur*i;
            sum+=arr[i];
            arr[i]+=extra;
            if(i==0) cur=(cur*i+arr[i])/(i+1);
            else cur=min(cur,(cur*i+arr[i])/(i+1));
            cout<<cur<<" ";
            
        }
        cout<<endl;
    }
}