#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n,k,cnt=-1;
        cin>>n>>k;
        queue<pair<int,int>> q;
        set<int> vis;
        q.push({n,0});
        while(!q.empty()){
            int node=q.front().first;
            int time=q.front().second;
            q.pop();
            if(vis.find(node)!=vis.end()) continue;
            vis.insert(node);
            if(node==k){ cnt=time;
            break;
        }
            if(node%2==0) q.push({node/2,time+1});
            else{
                q.push({node/2,time+1});
                q.push({(node+1)/2,time+1});
            }
        }
        cout<<cnt<<endl;
    }
}