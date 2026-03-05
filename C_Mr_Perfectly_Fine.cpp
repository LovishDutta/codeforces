#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,a;
        cin>>n;
        vector<int> zo,oz,oo;
        for(int i=0;i<n;i++){
            string s;
            cin>>a>>s;
            if(s=="11") oo.push_back(a);
            else if(s=="10") oz.push_back(a);
            else if(s=="01") zo.push_back(a);
        }
        sort(oo.begin(),oo.end());
        sort(oz.begin(),oz.end());
        sort(zo.begin(),zo.end());
        int ans=1e12;
        if(oo.size()>0) ans=min(ans,oo[0]); 
        if(oz.size()>0&&zo.size()>0) ans=min(ans,oz[0]+zo[0]); 
        cout<<(ans==1e12?-1:ans)<<endl;
    }
}