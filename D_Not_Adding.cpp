#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,cnt=0,a,maxi=1;
    cin>>n;
    vector<int> st(1000001);
    for(int i=0;i<n;i++){
        cin>>a;
        st[a]=1;
        maxi=max(maxi,a);
    }
    for(int i=1;i<=maxi;i++){
        if(st[i]==0){
            int gc=0;
            for(int j=i*2;j<=maxi;j+=i){
                if(st[j]) gc=__gcd(gc,j);
                if(gc==i){
                    cnt++;
                    break;
                }
            }
        }
    }
    cout<<cnt<<endl;
}