#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        map<int,vector<int> > mpp;
        for(int i=0;i<n;i++){
            mpp[arr[i]].push_back(i+1);
        }
        int ans=2,ansl=1,ansr=1,ansa=arr[0];
        for(auto &it2:mpp){
            int prev=-1,curfreq=0,l=1,r=1,a=it2.first;
            for(auto& it: it2.second){
                if(prev!=-1&&it-prev<=curfreq){
                    curfreq++;
                    curfreq-=(it-prev-1);
                    r=it;
                }
                else{
                    l=it;
                    r=it;
                    curfreq=1;
                }
                if(2*curfreq>ans){
                    ansl=l;
                    ansr=r;
                    ansa=a;
                    ans=2*curfreq;
                }
                prev=it;
            }
        }
        cout<<ansa<<" "<<ansl<<" "<<ansr<<endl;
    }
}