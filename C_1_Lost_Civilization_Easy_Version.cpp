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
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int cnt=0;
        stack<int> st;
        for(int i=0;i<n;i++){
            if(st.size()==0){
                cnt++;
                st.push(arr[i]);
            }
            else{
                if(st.top()==arr[i]-1){
                    st.push(arr[i]);
                }
                else if(st.top()==arr[i]){
                    while(st.size()>0&&(st.top()!=arr[i]-1)) st.pop();
                    st.push(arr[i]);
                    if(st.size()==1){
                        cnt++;
                    }
                }
                else{
                    while(!st.empty()){
                        if(st.top()==arr[i]-1){
                            st.push(arr[i]);
                            break;
                        }
                        st.pop();
                    }
                    if(st.size()==0){         
                        st.push(arr[i]);
                        cnt++;
                    }
                }
            }
    }
    cout<<cnt<<endl;
    }
}