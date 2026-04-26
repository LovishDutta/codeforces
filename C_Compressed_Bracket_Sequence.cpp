#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,ans=0,cnt=1;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<int> val(n,-1);
    stack<pair<int,int>> st;
    map<int,int> mpp;
    for(int i=0;i<n;i++){
        if(i%2){
            while(!st.empty()&&st.top().first%2==0&&arr[i]!=0){
                if(st.top().second>arr[i]){
                    int idx=st.top().first,ele=st.top().second;
                    st.pop();
                    st.push({idx,ele-arr[i]});
                    mpp[cnt]++;
                    val[i]=cnt++;
                    ans+=(arr[i]-1);
                    arr[i]=0;
                }
                else if(st.top().second<arr[i]){
                    arr[i]-=st.top().second;
                    ans+=(st.top().second-1);
                    if(st.top().first-1<0||val[st.top().first-1]==-1){
                        mpp[cnt]++;
                        val[i]=cnt++;
                    }
                    else mpp[val[st.top().first-1]]++;
                    st.pop();
                }
                else{
                    ans+=(arr[i]-1);
                    arr[i]=0;
                    if(st.top().first-1<0||val[st.top().first-1]==-1){
                        mpp[cnt]++;
                        val[i]=cnt++;
                    }
                    else{
                         mpp[val[st.top().first-1]]++;
                         val[i]=val[st.top().first-1];
                    }
                    st.pop();
                }
            }
            if(arr[i]>0){
                 st.push({i,arr[i]});
                 val[i]=-1;
            }
        }
        else{
            st.push({i,arr[i]});
        }
    } 
    for(auto &it:mpp) ans+=(it.second*(it.second+1))/2;
    cout<<ans;
}