#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
        int n,k;
        cin>>n>>k;
        int it=sqrt(n),cnt=1;
        set<int> st;
        for(int i=1;i<=it;i++){
            if(n%i==0){
                st.insert(i);
                st.insert(n/i);
            }
        }
        if(k>st.size()){
            cout<<-1;
            return 0;
        }
        auto it2=st.begin();
        while(cnt<k){
            cnt++;
            it2++;
        }
        cout<<*(it2);
        return 0;
}