#include<bits/stdc++.h>
using namespace std;
int unset(int x) {
    if (x == 0) return 0;
    int hb = 1 << (31 - __builtin_clz(x));
    return x ^ hb;
}
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n;
        cin>>n;
        vector<int> ans;
        set<int> st;
        for(int i=0;i<(1<<n)-1;i++){
            st.insert(i);
        }
        ans.push_back((1<<n)-1);
        int prev=((1<<n)-1);
        for(int i=n-1;i>=0;i--){
            prev=(prev&ans[ans.size()-1]);
            for(int j=0;j<(1<<(n-i));j++){
                int num=j;
                num=(num<<i);
                num+=unset(prev);
                if(st.find(num)!=st.end()){
                    st.erase(num);
                    ans.push_back(num);
                }
            }
        }
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}