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
        if(n==2){
            cout<<"2 1 2 1 1 2 2 1"<<endl;
            continue;
        }
        vector<int> ans(4*n,0);
        for(int i=1;i<=n;i++){
            set<int> st;
            int prev=-1,cnt=0;
            for(int j=0;j<4*n;j++){
                if(ans[j]==0&&(prev==-1||(st.find(j-prev)==st.end()))){
                    ans[j]=i;
                    if(prev!=-1) st.insert(j-prev);
                    cnt++;
                    prev=j;
                }
                if(cnt==4) break;
            }
        }
        ans[0]=n;
        ans[4*n-1]=1;
        for(int i=0;i<4*n;i++) cout<<ans[i]<<" ";
        cout<<endl;
    }
}