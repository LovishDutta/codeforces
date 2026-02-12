#include<bits/stdc++.h>
using namespace std;
#define int long long
void div(int n,unordered_map<int,int>& divisors) {
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisors[i]++;
            if (i != n / i)
                divisors[n / i]++;
        }
    }
}
signed main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n;
        cin>>n;
        vector<int> arr(n);
        unordered_map<int,int> st;
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++){
             cin>>arr[i];
             if(st.find(arr[i])==st.end()) st[arr[i]]=1;
        }
        vector<int> final;
        if(st.find(1)!=st.end()) final.push_back(1);
        else final.push_back(-1);
        st[1]=0;
        for(int i=2;i<=n;i++){
            int ans=1e12;
            int mult=i;
            div(mult,mpp);
            for(auto &it:mpp){
                if(st.find(it.first)!=st.end()&&(st.find(mult/it.first)!=st.end())){
                    int a=
                    ans=min(ans,st[it.first]+st[mult/it.first]);
                }
            }
            if(ans==1e12) final.push_back(-1);
            else{
                final.push_back(ans);
                st[mult]=ans;
            }
            mpp.clear();
        }
        for(int i=0;i<n;i++){
            cout<<final[i]<<" ";
        }
        cout<<endl;
    }
}