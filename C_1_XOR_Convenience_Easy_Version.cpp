#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n;
        cin>>n;
        vector<int> ans(n+1);
        set<int> st;
        for(int i=2;i<n;i++){
            if((i&(i+1))==0){
                 ans[i]=i/2;
            }
            else ans[i]=(i+1);
            st.insert(ans[i]);
        }
        for(int i=1;i<=n;i++){
            if(ans[n]==0){
                if(st.find(i)==st.end()) ans[n]=i;
            }
            else if(ans[1]==0){
                if(st.find(i)==st.end()) ans[1]=i;
            }
            else break;
        }
        for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
        cout<<endl;
    }
}