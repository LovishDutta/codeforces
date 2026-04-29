#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,ans=0,a;
        cin>>n;
        vector<int> arr(n);
        vector<int> vis(n+1,0);
        multiset<int> ms;
        set<int> st;
        for(int i=0;i<n;i++){
             cin>>a;
             if(a<n&&vis[a]==0){
                vis[a]=1;
                st.insert(a);
             }
             else ms.insert(a);
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                bool flag=false;
                while(ms.size()>0){
                auto it=(ms.begin());
                ms.erase(it);
                if(*it>=i&&*it%(*it-i)==i){
                    flag=true;
                    vis[i]=true;
                    break;
                }
                } 
                if(!flag){
                while(st.size()>0){
                auto it=(st.begin());
                st.erase(it);
                if(*it>=i&&*it%(*it-i)==i){
                    flag=true;
                    vis[*it]=false;
                    vis[i]=true;
                    break;
                }
                } 
                }
                if(!flag) break;
            }
            else if(st.find(i)!=st.end()) st.erase(i);
        }
        for(int i=0;i<=n;i++){
             if(!vis[i]){
            ans=i;
            break;
             }
        }
        cout<<ans<<endl;
    }
}