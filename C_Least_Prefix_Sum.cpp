#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n,m,cnt=0;
        cin>>n>>m;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        priority_queue<int> pq;
        priority_queue<int, vector<int>, greater<int>> pq2;
        int ps=0,pf=0;
        vector<int> pref(m,arr[0]);
        for(int i=1;i<m;i++) pref[i]=pref[i-1]+arr[i];
        for(int i=m-1;i>=0;i--){
            while(pref[i]<pref[m-1]){
                pref[m-1]-=2*pq.top();
                pq.pop();
                cnt++;
            }
            pq.push(arr[i]);
        }
        pf=pref[m-1];
        for(int i=m;i<n;i++){
            pq2.push(arr[i]);
            pf+=arr[i];
            while(pf<pref[m-1]){
                pf+=(-2*pq2.top());
                pq2.pop();
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
}