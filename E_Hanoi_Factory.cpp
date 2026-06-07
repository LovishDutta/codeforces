#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,h=0,ans=0;
    cin>>n;
    vector<vector<int>> arr(n,vector<int>(3));
    for(int i=0;i<n;i++) cin>>arr[i][1]>>arr[i][0]>>arr[i][2];
    sort(arr.rbegin(),arr.rend());
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty()&&arr[st.top()][1]>=arr[i][0]){
            h-=arr[st.top()][2];
            st.pop();
        }
        st.push(i);
        h+=arr[i][2];
        ans=max(ans,h);
    }
    cout<<ans<<endl;
}