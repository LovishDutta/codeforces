#include<bits/stdc++.h>
using namespace std;
#define int long long
bool check(int& mid,string& s){
    int prev=-1,next=-1;
    for(int i=0;i<s.size();i++){
        if(prev==-1&&s[i]=='*'&&i>next) prev=i;
        if(s[i]=='P'){
            if(prev==-1){
                next=i+mid;
            }
            else{
                if(i-prev>mid){
                     return false;
                }
                else{
                    next=max((mid-2*(i-prev)),(mid-(i-prev))/2)+i;
                    prev=-1;
                }
            }
        }
    }
    return prev==-1;
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    int low=1,high=2*n;
    while(low<=high){
        int mid=(low+high)/2;
        if(check(mid,s)) high=mid-1;
        else low=mid+1;
    }
    cout<<low<<endl;
}