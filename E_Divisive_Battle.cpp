#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,flag=0,ans=0;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(i>0&&arr[i]<arr[i-1]) flag=1;
        }
        if(!flag){
            cout<<"Bob"<<endl;
            continue;
        }
        set<int> st;
        for(int i=n-1;i>=0;i--){
            if(arr[i]==1){
                st.insert(1);
                continue;
            }
            vector<int> a;
            for(int j=2;j*j<=arr[i];j++){
                if(arr[i]%j==0){
                    a.push_back(j);
                    if(!st.empty()&&j>*(st.begin())){
                        ans=1;
                        break;
                    }
                    while(arr[i]%j==0){
                        arr[i]/=j;
                    }
                }   
            }
                if(arr[i]>1){
                    a.push_back(arr[i]);
                    if(!st.empty()&&arr[i]>*(st.begin())){
                        ans=1;
                        break;
                    }
                }
                if(ans==1||(a.size()>1)){
                ans=1;
                break;
            }
            for(auto &it:a) st.insert(it);
        }
        if(ans) cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;
    }
}