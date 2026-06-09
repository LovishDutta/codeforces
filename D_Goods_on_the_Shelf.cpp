#include<bits/stdc++.h>
using namespace std;
#define int long long
bool check(vector<int>& arr,int swp1,int swp2){
    int n=arr.size();
    if(swp1<0||swp2<0||swp1>=n||swp2>=n) return false;
    swap(arr[swp1],arr[swp2]);
    map<int,vector<int>> mpp;
    for(int i=0;i<n;i++){
         //   cout<<arr[i]<<" ";
            mpp[arr[i]].push_back(i);
        }
       // cout<<endl;
        for(auto &it:mpp){
            for(int i=1;i<it.second.size();i++){
                if(it.second[i]!=it.second[i-1]+1){
                     swap(arr[swp1],arr[swp2]);
                     return false;
                }
            }
        }
    swap(arr[swp1],arr[swp2]);
    return true;
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,val=-1,vall=-1,ans=0;
        cin>>n;
        vector<int> arr(n);
        map<int,vector<int>> mpp;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            mpp[arr[i]].push_back(i);
        }
        for(auto &it:mpp){
            for(int i=1;i<it.second.size();i++){
                if(it.second[i]!=it.second[i-1]+1){
                    if(val==-1) val=it.first;
                    else vall=it.first;
                    break;
                }
            }
        }
        //cout<<val<<endl;
        if(val!=-1){
            vector<int> temp=mpp[val];
            int k=temp.size();
            int maxi=1,s=0,e=0;
            for(int i=0;i<k;i++){
                int len=1,end=i;
                while(end+1<k&&temp[end+1]==temp[end]+1){
                    len++;
                    end++;
                }
                if(len>maxi){
                    maxi=len;
                    s=temp[i];
                    e=temp[end];
                }
                i=end;
            }
            if(maxi>1){
                for(int i=0;i<k;i++){
                    if(temp[i]<s||temp[i]>e){
                        ans=(ans||check(arr,temp[i],s-1)||check(arr,temp[i],e+1));
                        break;
                    }
                }
                for(int i=k-1;i>=0;i--){
                    if(temp[i]<s||temp[i]>e){
                        ans=(ans||check(arr,temp[i],s-1)||check(arr,temp[i],e+1));
                        break;
                    }
                }
            }
            else{
                int val1=temp[0],val2=temp[temp.size()-1];
                ans=check(arr,val1,val2-1)||check(arr,val1,val2+1)||check(arr,val2,val1-1)||check(arr,val2,val1+1);
            }
        }
        else ans=1;
        if(vall!=-1){
            val=vall;
            vector<int> temp=mpp[val];
            int k=temp.size();
            int maxi=1,s=0,e=0;
            for(int i=0;i<k;i++){
                int len=1,end=i;
                while(end+1<k&&temp[end+1]==temp[end]+1){
                    len++;
                    end++;
                }
                if(len>maxi){
                    maxi=len;
                    s=temp[i];
                    e=temp[end];
                }
                i=end;
            }
            if(maxi>1){
                for(int i=0;i<k;i++){
                    if(temp[i]<s||temp[i]>e){
                        ans=(ans||check(arr,temp[i],s-1)||check(arr,temp[i],e+1));
                        break;
                    }
                }
                for(int i=k-1;i>=0;i--){
                    if(temp[i]<s||temp[i]>e){
                        ans=(ans||check(arr,temp[i],s-1)||check(arr,temp[i],e+1));
                        break;
                    }
                }
            }
            else{
                int val1=temp[0],val2=temp[temp.size()-1];
                ans=check(arr,val1,val2-1)||check(arr,val1,val2+1)||check(arr,val2,val1-1)||check(arr,val2,val1+1);
            }
        }
        if(ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}