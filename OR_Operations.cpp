#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,orr=0,cnt=0;
        cin>>n;
        vector<int> arr(n),temp;
        for(int i=0;i<n;i++){
             cin>>arr[i];
             orr=orr|arr[i];
        }
        for(int i=0;i<n;i++){
            int ele=arr[i],j=i+1;
            while(j<n&&ele!=orr){
                ele=ele|arr[j];
                j++;
                cnt++;
            }
            temp.push_back(ele);
            i=j-1;
        }
        int s=temp.size();
        if(s>1&&temp[s-1]!=temp[s-2]) cnt++;
        cout<<cnt<<endl;
    }
}