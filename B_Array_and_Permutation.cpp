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
        vector<int> p(n);
        vector<int> a(n);
        map<int,int> mpp;
        for(int i=0;i<n;i++){
             cin>>p[i];
             mpp[p[i]]=i;
        }
        for(int i=0;i<n;i++) cin>>a[i];
        int f=0,prev=-1;
        bool flag=true;
        for(int i=0;i<n;i++){
           if(mpp[a[i]]<f){
            flag=false;
            break;
           }
           f=max(f,mpp[a[i]]);
           
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}