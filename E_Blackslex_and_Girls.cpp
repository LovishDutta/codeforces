#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n,x,y,xspent=0,flag2=0;
        cin>>n>>x>>y;
        string s;
        cin>>s;
        vector<int> one;
        vector<int> zero;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            if(s[i]=='1') one.push_back(a);
            else zero.push_back(a);
        }
        bool flag=true;
        for(int i=0;i<one.size();i++){
            int c1=one[i]/2+1,c2=one[i]/2;
            if(one[i]%2==0){
                 c2-=1;
                 flag2++;
            }
            if(c1<=y&&c2<=x){
                y-=c1;
                x-=c2;
                xspent+=c2;
            }
            else if(c1>y){
                flag=false;
                break;
            }
            else{
                one[i]-=x;
                xspent+=x;
                x=0;
                if(one[i]>y){
                    flag=false;
                    break;
                }
                else y-=one[i];
            }
        }
        if(one.size()==n&&x>y+flag2) flag=false;
        if(xspent<=y){
            x+=xspent;
            y-=xspent;
        }
        else{
            x+=y;
            y=0;
        }
        
        for(int i=0;i<zero.size();i++){
            int c1=zero[i]/2+1,c2=zero[i]/2;
            if(zero[i]%2==0){
                c2-=1;
                flag2++;
            }

            if(c1<=x&&c2<=y){
                x-=c1;
                y-=c2;
            }
            else if(c1>x){
                flag=false;
                break;
            }
            else{
                zero[i]-=y;
                y=0;
                if(zero[i]>x){
                    flag=false;
                    break;
                }
                else x-=zero[i];
            }
        }
        
        if(zero.size()==n&&y>x+flag2) flag=false;
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}