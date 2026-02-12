#include<bits/stdc++.h>
using namespace std;
int main(){
        double m,n;
        cin>>m>>n;
        double ans=m;
        for(int i=1;i<m;i++){
            double div=(double)i/m;
            int k=n-1;
            while(div!=1&&k&&div>0.0001){
                div*=(double)i/m;
                k--;
            }
            ans-=div;
        }
    cout<<fixed<<setprecision(12)<<ans;

}