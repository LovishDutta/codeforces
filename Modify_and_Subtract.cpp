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
        for(int i=0;i<n;i++) cin>>arr[i];
        vector<int> l(n,arr[0]),r(n,arr[n-1]);
        for(int i=1;i<n;i++){
            if(l[i-1]<0){
                l[i]=-1;
            }
            else{
                l[i]=arr[i]-l[i-1];
                if(l[i]<0) l[i]=-1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(r[i+1]<0){
                r[i]=-1;
            }
            else{
                r[i]=arr[i]-r[i+1];
                if(r[i]<0) r[i]=-1;
            }
        }
        for(int i=0;i<n;i++){
            int prev=0,nxt=0;
            if(i!=0) prev=l[i-1];
            if(i!=n-1) nxt=r[i+1];
            if (prev != -1 && nxt != -1) cnt++;
        }
        cout<<cnt<<endl;
    }
}