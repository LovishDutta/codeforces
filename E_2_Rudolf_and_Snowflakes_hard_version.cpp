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
            if (prev > 1e18 / i) break;
            prev*=i;
        }
    } 
    for(int z=0;z<t;z++){
        int n;
        cin>>n;
        bool flag=false;
        if(st.find(n)!=st.end()) flag=true;
        long long d=sqrt(4*n-3);
        if(d*d==4*n-3&&(d-1)%2==0&&(d-1)/2>1) flag=true;
        if(flag) cout<<"YES";
        else cout<<"NO";
        cout<<endl;
    }
}