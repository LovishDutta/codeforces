#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        int n,m,ext=0,shift=0,last=0;
        cin>>n>>m;
        vector<int> col(m);
        vector<int> ans(m);
        vector<int> extra(m);
        for(int i=0;i<m;i++){
             cin>>col[i];
             extra[i]=col[i]-1;
            if(i!=m-1) ext+=extra[i];
             last=max(last,i+col[i]-1);
        }
        if(n-last-1>ext||last>=n){
            cout<<-1<<endl;
            return 0;
        }
        int rem=n-last-1;
        for(int i=0;i<m;i++){
            ans[i]=i+shift;
            if(rem>0){
                shift+=extra[i];
                rem-=extra[i]; 
            }
        }
        for(int i=0;i<m;i++) cout<<ans[i]+1<<" ";
        cout<<endl;
}