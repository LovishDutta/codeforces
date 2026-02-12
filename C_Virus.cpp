#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n,m;
        cin>>n>>m;
        vector<int> arr(m);
        for(int i=0;i<m;i++) cin>>arr[i];
        sort(arr.begin(),arr.end());
        vector<int> a;
        for(int i=0;i<m-1;i++){
            a.push_back(arr[i+1]-arr[i]-1);
        }
        a.push_back((n-arr[m-1])+(arr[0]-1));
        sort(a.begin(),a.end());
        int ans=0;
        int day=0;
        for(int i=a.size()-1;i>=0;i--){
            if(a[i]-2*day<=0) break;
            a[i]-=2*day;
            day+=2;
            if(a[i]==1||a[i]==2) ans+=1;
            else ans+=a[i]-1;
        }
        cout<<n-ans<<endl;
    }
}
