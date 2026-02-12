#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n;
        cin>>n;
        vector<int> a(n);
        vector<int> b(n);
        vector<int> c(n);
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];
        for(int i=0;i<n;i++) cin>>c[i];
        set<int> st;
        for(int i=0;i<n;i++){
            if(b[0]>a[i]) st.insert(i);
        }
        for(int j=1;j<n;j++){
            for(int i=0;i<n;i++){
                if(b[j]<=a[i]){
                    int abc=i-j<0?(n+(i-j)):(i-j);
                    if(st.find(abc)!=st.end()){
                        st.erase(abc);
                    }
                }
            }
        }
        set<int> st2;
        for(int i=0;i<n;i++){
            if(c[0]>b[i]) st2.insert(i);
        }
        for(int j=1;j<n;j++){
            for(int i=0;i<n;i++){
                if(c[j]<=b[i]){
                    int abc=i-j<0?(n+(i-j)):(i-j);
                    if(st2.find(abc)!=st2.end()){
                        st2.erase(abc);
                    }
                }
            }
        }
        cout<<n*st.size()*st2.size()<<endl;
    }
}