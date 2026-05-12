#include<bits/stdc++.h>
using namespace std;
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m,ele;
    cin>>n>>m;
    vector<int> spf(1e7+1);
    vector<int> a(n),b(m);
    for(int i=1;i<=1e7;i++) spf[i]=i;
    for(long long i=2;i<=1e7;i++){
        if(spf[i]==i){
            for(long long j=i*i;j<=1e7;j+=i){
                if(spf[j]==j) spf[j]=i;
            }
        }
    }
    map<int,int> mpp;
    vector<int> arr1,arr2;
    for(int i=0;i<n;i++){
        cin>>ele;
        a[i]=ele;
        while(ele!=1){
            mpp[spf[ele]]++;
            ele/=spf[ele];
        }
    }
    for(int i=0;i<m;i++){
        cin>>ele;
        b[i]=ele;
        while(ele!=1){
            mpp[spf[ele]]--;
            ele/=spf[ele];
        }
    }
    for(int i=0;i<n;i++){
        int ele=1;
         while(a[i]!=1){
            if(mpp.find(spf[a[i]])!=mpp.end()){
                if(mpp[spf[a[i]]]>0){
                    ele*=spf[a[i]];
                    mpp[spf[a[i]]]--;
                }
                if(mpp[spf[a[i]]]==0) mpp.erase(spf[a[i]]);
            }
            a[i]/=spf[a[i]];
        }
        if(ele>1) arr1.push_back(ele);
    }
    for(int i=0;i<m;i++){
        int ele=1;
         while(b[i]!=1){
            if(mpp.find(spf[b[i]])!=mpp.end()){
                if(mpp[spf[b[i]]]<0){
                    ele*=spf[b[i]];
                    mpp[spf[b[i]]]++;
                }
                if(mpp[spf[b[i]]]==0) mpp.erase(spf[b[i]]);
            }
            b[i]/=spf[b[i]];
        }
        if(ele>1) arr2.push_back(ele);
    }
    if(arr1.size()==0) arr1.push_back(1);
    if(arr2.size()==0) arr2.push_back(1);
    cout<<arr1.size()<<" "<<arr2.size()<<endl;
    for(int i=0;i<arr1.size();i++) cout<<arr1[i]<<" ";
    cout<<endl;
    for(int i=0;i<arr2.size();i++) cout<<arr2[i]<<" ";
}