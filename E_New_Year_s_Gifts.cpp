#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n,m,k,a,cnt=0;
        cin>>n>>m>>k;
        multiset<int> st;
        vector<vector<int>> vec(n,vector<int>(2));
        for(int i=0;i<m;i++){
            cin>>a;
            st.insert(a);
        } 
        for(int i=0;i<n;i++){
           cin>>vec[i][1]>>a>>vec[i][0];
           vec[i][0]-=a;
           k-=a;
        } 
        sort(vec.begin(),vec.end());
        for(int i=n-1;i>=0;i--){
            if(st.size()==0) break;
            auto it=st.lower_bound(vec[i][1]);;
            if((it!=st.end())){
                st.erase(it);
                vec[i][0]=0;      
            }
        }
        for(int i=0;i<n;i++){
            if(vec[i][0]<=k){
                k-=vec[i][0];
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
}