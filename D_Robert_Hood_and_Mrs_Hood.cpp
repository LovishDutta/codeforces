#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n,d,k,a,b,curcnt=0,maxi=0,mini=1e8,i1=0,i2=0;
        cin>>n>>d>>k;
        map<int,int> st,en;
        for(int i=0;i<k;i++){
            cin>>a>>b;
            st[a]++;
            en[b]++;
        }

        for(int i=1;i<=d;i++){
             if(en.find(i-1)!=en.end()){
                curcnt-=en[i-1];
            }
            curcnt+=st[i];
        }
        maxi=curcnt;
        mini=curcnt;
        i1=1,i2=1;
        for(int i=d+1;i<=n;i++){
            if(en.find(i-d)!=en.end()){
                curcnt-=en[i-d];
            }
            curcnt+=st[i];
            //cout<<i<<" "<<curcnt<<endl;
            if(curcnt>maxi){
                maxi=curcnt;
                i1=i-d+1;
            }
            if(curcnt<mini){
                mini=curcnt;
                i2=i-d+1;
            }
        }
        cout<<i1<<" "<<i2<<endl;
    }
}