#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,sum=0,flag=0;
        cin>>n;
        vector<int> arr;
        while(n>0){
            sum+=n%10;
            arr.push_back(n%10);
            n/=10;
        }
        int last=arr[arr.size()-1];
        sort(arr.rbegin(),arr.rend());
        int cnt=0;
        for(int i=0;i<arr.size();i++){
            if(sum>=10){
                cnt++;
                if(i<arr.size()-1&&arr[i+1]!=arr[i]&&arr[i]==last){
                     sum-=(arr[i]-1);
                }
                else sum-=(arr[i]);
            }
            else break;
        }
        cout<<cnt<<endl;
    }
}