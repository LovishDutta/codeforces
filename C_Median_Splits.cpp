#include<bits/stdc++.h>
using namespace std;
#define int long long
bool funct(vector<int>& arr,vector<int>& revarr){
    int flag=0,ll=-1,n=arr.size();
    for(int i=0;i<n-2;i++){
            if(arr[i]>=(i+2)/2){
                int j=i;
                while(j<n-3&&arr[j+1]==arr[i]&&arr[j+1]>=(j+3)/2) j++;
                flag=true;
                ll=j;
                break;
            }
    }
    if(flag){
        for(int i=ll+1;i<n-1;i++){
            if(arr[i]-arr[ll]>=(i-ll+1)/2) return true;
        }
        for(int i=0;i<n-ll-1;i++){
            if(revarr[i]>=(i+2)/2) return true;
        }
        return false;
    }
    else{
        for(int i=0;i<n-2;i++){
            if(revarr[i]>=(i+2)/2){
                int j=i;
                while(j<n-3&&revarr[j+1]==revarr[i]&&revarr[j+1]>=(j+3)/2) j++;
                flag=true;
                ll=j;
                break;
            }
        }
        if(flag){
            for(int i=ll+1;i<n-1;i++){
            if(revarr[i]-revarr[ll]>=(i-ll+1)/2) return true;
            }
        }
        return false;
    }
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,k,a;
        cin>>n>>k;
        vector<int> arr(n);
        vector<int> ip(n);
        vector<int> revarr(n);
        for(int i=0;i<n;i++){
            cin>>a;
            ip[i]=a;
            if(i==0) arr[i]=(a<=k);
            else arr[i]=arr[i-1]+(a<=k);
        }
        reverse(ip.begin(),ip.end());
        revarr[0]=(ip[0]<=k);
        for(int i=1;i<n;i++){
            revarr[i]=revarr[i-1]+(ip[i]<=k);
        }
        bool ans=funct(arr,revarr)||funct(revarr,arr);
        if(ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}