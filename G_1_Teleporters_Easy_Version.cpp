#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n,c;
        cin>>n>>c;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=1;i<=n;i++){
            int a;
            cin>>a;
            pq.push(a+i);
        }
        int ans=0;
        while(!pq.empty()){
            int a=pq.top();
            pq.pop();
            if(c>=a){
                c-=a;
                ans++;
            }
            else break;
        }
        cout<<ans<<endl;
    }
}