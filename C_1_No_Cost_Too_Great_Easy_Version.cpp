#include<bits/stdc++.h>
using namespace std;
#define int long long
bool f(vector<int> a,unordered_set<int>& st){
    
    for(int i=0;i<a.size();i++){
        for (int p = 2; (long long)p * p <= a[i]; p++) {
            if (a[i] % p == 0) {
                if(st.find(p)!=st.end()) return true;
                st.insert(p);
                
                while (a[i] % p == 0) a[i] /= p;
            }
        }
         if (a[i] > 1) { 
            if (st.find(a[i]) != st.end()) return true;
            st.insert(a[i]);
        }
    }
    return false;
}
bool f2(int i,unordered_set<int>& st){
        for (int p = 2; (long long)p * p <= i; p++) {
            if (i % p == 0) {
                if(st.find(p)!=st.end()) return true;
                //st.insert(p);
                while (i % p == 0) i /= p;
            }
        }
         if (i > 1) { 
            if (st.find(i) != st.end()) return true;
           // st.insert(i);
        }
    return false;
}

signed main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n;
        cin>>n;
        vector<int> a(n);
        vector<int> b(n);
        int even=0;
        for(int i=0;i<n;i++){
             cin>>a[i];
             if(a[i]%2==0) even++;
        }
        for(int i=0;i<n;i++) cin>>b[i];
        int ans=0;
        unordered_set<int> used;
        if(f(a,used)) ans=0; 
        else if(even==1) ans=1;
        else{
            ans=2;
           for(int i=0;i<n;i++){
            if(f2(a[i]+1,used)){
                ans=1;
                break;
            }
           }
        }
        cout<<ans<<endl;
    }
}