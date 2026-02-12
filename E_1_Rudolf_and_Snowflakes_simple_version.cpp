#include<bits/stdc++.h>
using namespace std;
#define int long long
set<long long> st;
signed main(){
    int t;
    cin>>t;  
    for(int i=2;i<=1000000;i++){
        long long prev=i*i*i;
        long long sum=1+i+i*i;
        st.insert(sum);
        while(sum+prev<=1e18){
            sum+=prev;
            st.insert(sum);
            prev*=i;
        }
    } 
    for(int z=0;z<t;z++){
        int n;
        cin>>n;
        if(st.find(n)!=st.end()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}