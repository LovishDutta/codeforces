#include<bits/stdc++.h>
using namespace std;
int spf[10000001];
pair<int,int> f(int n){
    if(n<=5) return {-1,-1};
    int ele=n;
    vector<int> even,odd;
    while(n!=1){
        if(spf[n]%2&&spf[n]!=1){
            if(odd.size()==0||odd[odd.size()-1]!=spf[n]) odd.push_back(spf[n]);
        }
        else{
            if(even.size()==0||even[even.size()-1]!=spf[n]) even.push_back(spf[n]);
        }
        n=n/spf[n];
        if(n%2&&n!=1){
            for(int i=0;i<even.size();i++) if(__gcd(even[i]+n,ele)==1) return {even[i],n};
            if(ele%2) for(int i=0;i<odd.size();i++) if(__gcd(odd[i]+n,ele)==1) return {odd[i],n};
            odd.push_back(n);
        }
        else if(n!=1){
            for(int i=0;i<odd.size();i++) if(__gcd(odd[i]+n,ele)==1) return {odd[i],n};
            even.push_back(n);
        }
    }
    return {-1,-1};
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=1e7;i++) spf[i]=i;
    for(int i=2;i*i<=10000000;i++){
    if(spf[i]==i){
        for(int j=i*i;j<=10000000;j+=i){
            if(spf[j]==j)
                spf[j]=i;
        }
    }
    }
    vector<int> arr(n);
    vector<pair<int,int>> ans(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        ans[i]=f(arr[i]);
    }
    for(int i=0;i<n;i++) cout<<ans[i].first<<" ";
    cout<<endl;
    for(int i=0;i<n;i++) cout<<ans[i].second<<" ";
}