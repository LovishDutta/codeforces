#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n,sum=0;
        cin>>n;
        vector<int> a(n),b(n);
        map<int,int> idx;
        set<int> st;
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++){
            cin>>b[i];
            idx[b[i]]=i;
        }
        int shift=0;
        for(int i=0;i<n;i++){
            if(st.find(b[i])!=st.end()) shift--;
            if(idx.find(a[i])==idx.end()){
                sum=1;
                break;
            }
            sum=(sum+idx[a[i]]+shift-i);
            cout<<sum<<endl; 
            if(sum%2){
                if(i<n-2){
                    swap(a[n-1],a[n-2]);
                    sum--;
                }
                else{
                    sum=1;
                    break;
                }
            }
            st.insert(a[i]);
            shift++;
            if(st.find(b[i])!=st.end()) shift--;
        }
        if(sum%2) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}