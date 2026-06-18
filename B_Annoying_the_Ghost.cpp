#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,flag=1,cnt=0;
        cin>>n;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];
        for(int i=0;i<n;i++){
            if(a[i]>b[i]){
                int j=i+1;
                while(j<n&&a[j]>b[i]) j++;
                if(j==n){
                    flag=0;
                    break;
                }
                for(int k=j;k>i;k--){
                    swap(a[k],a[k-1]);
                    cnt++;
                }
            }
        }
        if(flag) cout<<cnt<<endl;
        else cout<<-1<<endl;
    }
}