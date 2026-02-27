#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int m,flag=1,flag2=0;
        cin>>m;
        vector<int> arr(m);
        set<int> st;
        for(int i=0;i<m;i++){
            cin>>arr[i];
            if(i>0&&arr[i]<arr[i-1]) flag2=1;
        }
        if(!flag2){
            cout<<"Bob"<<endl;
            continue;
        }
        for(int i=m-1;i>=0;i--){
            if(arr[i]==1){
                st.insert(1);
            }
            else{
                vector<int> ans;
                int n=arr[i];
                int cnt = 0;
                for(int j = 2; j * j <= n; j++){
                    if(n % j == 0){
                    cnt++;
                 while(n % j == 0){
                n /= j;
                ans.push_back(j);
                if(!st.empty()&&j>*(st.begin())){
                    flag=0;
                    break;
                }
                }
                }
                }
            if(n > 1){
                ans.push_back(n);
                cnt++;
               if(!st.empty()&&n>*(st.begin())) flag=0;
             }
            if(flag==0||cnt>1){
                flag=0;
                break;
            }
            for(auto &it: ans){
                st.insert(it);
            }
            }
        }
        if(flag) cout<<"Bob"<<endl;
        else cout<<"Alice"<<endl;
    }
}