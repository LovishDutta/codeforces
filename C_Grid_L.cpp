#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int p,q,flag=0;
        cin>>p>>q;
        int x=2LL*(p+2LL*q)+1;
        for(int i=1;i*i<=x;i++){
            if(x%i==0){
                int a = i;
                int b = x/ i;
                if(a%2 ==1&&b%2==1){
                    int n =(a-1)/2;
                    int m =(b-1)/2;
                    if(n>0&& m >0&&q <= (max(n,m)+1)*min(n,m)){
                        cout <<n<<" "<<m<<endl;
                        flag = true;
                        break;
                    }
                }
            }
        }
        if(!flag) cout<<-1<<endl;
    }
}