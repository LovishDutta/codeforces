#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,k,cnt=0;
    cin>>n>>k;
    vector<int> arr(n),next(n),prev(n),ans(n);
    set<pair<int,int>> st;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        st.insert({arr[i],i});
        next[i]=i+1;
        prev[i]=i-1;
    }
    while(!st.empty()){
        auto it=*(st.rbegin());
        int ele=it.first,idx=it.second,c=0,p=0,i=0,j=0;
        st.erase(it);
        ans[idx]=cnt;
        for(i=next[idx];i<n&&c<k;i=next[i]){
            ans[i]=cnt;
            st.erase({arr[i],i});
            c++;
        }
        for(j=prev[idx];j>=0&&p<k;j=prev[j]){
            ans[j]=cnt;
            st.erase({arr[j],j});
            p++;
        }
        if(j>=0) next[j]=i;
        if(i<n) prev[i]=j;
        cnt=(!cnt);
    }
    for(int i=0;i<n;i++) cout<<ans[i]+1;
}