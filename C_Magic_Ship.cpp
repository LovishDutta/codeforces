#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    //cin>>tc;    
    while(tc--){
        int x1,y1,x2,y2,n,wr=0,wu=0;
        cin>>x1>>y1>>x2>>y2>>n;
        string s;
        cin>>s;
        if(x2<x1){
            x1*=-1;
            x2*=-1;
            for(int i=0;i<n;i++){
                if(s[i]=='R') s[i]='L';
                else if(s[i]=='L') s[i]='R';
            }
        }
        if(y2<y1){
            y1*=-1;
            y2*=-1;
            for(int i=0;i<n;i++){
                if(s[i]=='U') s[i]='D';
                else if(s[i]=='D') s[i]='U';
            }
        }
        int rr=(abs(x2-x1)),ru=(abs(y2-y1));
        for(int i=0;i<n;i++){
            if(s[i]=='L') wr--;
            else if(s[i]=='R') wr++;
            else if(s[i]=='U') wu++;
            else wu--;
        }
        int low=0,high=1e18;
        while(low<=high){
            int mid=(low+high)/2;
            int windr=wr*(mid/n),windu=wu*(mid/n);
            for(int i=0;i<mid%n;i++){
                if(s[i]=='L') windr--;
                else if(s[i]=='R') windr++;
                else if(s[i]=='U') windu++;
                else windu--;
            }
            if(abs(rr-windr)+abs(ru-windu)<=mid) high=mid-1;
            else low=mid+1;
        }
        cout<<(low<1e18?low:-1);
    }
}