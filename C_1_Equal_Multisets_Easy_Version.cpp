#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,k;
        cin>>n>>k;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];
        bool flag=true;
        if(k<=(n+1)/2){
            for(int i=0;i<n;i++){
                if(a[i]==b[i]||b[i]==-1) continue;
                else{
                    flag=false;
                    break;
                }
            }
            if(flag) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
            continue;
        }
        for(int i=0;i<n-k;i++){
            if(a[i]==b[i]||b[i]==-1) continue;
            else{
                    flag=false;
                    break;
                }
        }
        for(int i=n-1;i>k-1;i--){
            if(a[i]==b[i]||b[i]==-1) continue;
            else{
                    flag=false;
                    break;
                }
        }
        if(!flag){
            cout<<"NO"<<endl;
            continue;
        }
        set<int> st;
        int cnt=0;
        for(int i=n-k;i<=k-1;i++) st.insert(a[i]);
        for(int i=n-k;i<=k-1;i++){
            if(st.find(b[i])!=st.end()) st.erase(b[i]);
            else if(b[i]==-1) cnt++;
        }
        if(cnt<st.size()) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;

    }
}