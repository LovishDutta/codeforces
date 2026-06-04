#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,mex=0;;
        cin>>n;
        vector<int> arr(n),suff(n),ans;;
        set<int> st;
        for(int i=0;i<n;i++) cin>>arr[i];
        for(int i=n-1;i>=0;i--){
            st.insert(arr[i]);
            while(st.find(mex)!=st.end()) mex++;
            suff[i]=mex;
        }
        for(int i=0;i<n;i++){
            int j=i,m=0;
            set<int> s;
            while(j<=n&&m!=suff[i]){
                s.insert(arr[j]);
                while(s.find(m)!=s.end()) m++;
                j++;
            }
            ans.push_back(suff[i]);
            if(i!=j) i=j-1;
        }
        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
        cout<<endl;
    }
}