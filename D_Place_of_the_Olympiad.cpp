#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int i=0;i<t;i++){
        double n,m,b;
        cin>>n;
        cin>>m;
        cin>>b;
        double maxb=(double)ceil((double)b/(double)n);
        long long ans=ceil((double)maxb/(double)(m-maxb+1));
        cout<<ans<<endl;
    }
    
}
