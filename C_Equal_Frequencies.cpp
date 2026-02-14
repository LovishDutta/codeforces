#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> f(int n){
    vector<int> ans;
    for(int i=1;i*i<=n;i++){
        if(n%i==0) ans.push_back(i);
        if(n/i!=i) ans.push_back(n/i);
    }
    return ans;
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,ans=n;
        cin>>n;
        string s;
        cin>>s;
        vector<int> a=f(n);
        map<int,int> mpp;
        for(int i=0;i<n;i++) mpp[s[i]-'a']++;
        for(int i=0;i<a.size();i++){
            if(n/a[i]>26) continue;
            // vector<int> less1;
            // vector<int> less2;
            // vector<int>> extra;
            int less1=0,extra=0;
            for(int z=0;z<26;z++){
                if(mpp.find(z)==mpp.end()) continue;
                 if(mpp[z]>a[i]) extra+=(mpp[z]-a[i]);
                else if(mpp[z]<a[i]) less1+=(a[i]-mpp[z]);
            }
            cout<<a[i]<<" "<<extra<<" "<<less1<<endl;
            ans=min(ans,max(extra,(less1-extra)/2));
            // for(int i=0;i<26;i++){
            //     if(mpp.find(i)==mpp.end()) less2.push_back(a[i]);
            //     else if(mpp[i]>a[i]) extra.push_back(mpp[i]-a[i]);
            //     else if(mpp[i]<a[i]) less1.push_back(a[i]-mpp[i]);
            // }
            // sort(less1.begin(),less1.end());
            // int k=0,j=0,l=0,cnt=0;
            // while(k<extra.size()&&j<less1.size()){
            //     if(extra[k]>less1[j]){
            //         extra[k]-=less1[j];
            //         j++;
            //         cnt+=(less1[j])
            //     }
            // }
            
        }
        cout<<ans<<endl;
    }
}