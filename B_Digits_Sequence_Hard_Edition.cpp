#include<bits/stdc++.h>
using namespace std;
#define int long long
int dig(int k,vector<int>& temp){
    int n=0,ten=1,K=k;
    while(k>0){
        k/=10;
        ten*=10;
        n++;
    }
    ten/=10;
    return temp[n-1]+n*(K-ten+1);
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int k;
    cin>>k;
    int low=1,high=k,ten=1;
    vector<int> temp(16);
    for(int i=1;i<=15;i++){
        temp[i]=i*9LL*ten;
        ten*=10;
    }
    for(int i=2;i<=15;i++) temp[i]+=temp[i-1];
    while(low<=high){
        int mid=(low+high)/2;
        if(dig(mid,temp)<k) low=mid+1;
        else high=mid-1;
    }
    int diff=dig(low,temp)-k,cnt=0;
    while(low>0){
        if(cnt==diff){
            cout<<low%10;
            break;
        }
        low/=10;
        cnt++;
    }
}