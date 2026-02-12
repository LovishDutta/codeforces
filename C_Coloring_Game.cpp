#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        long long n;
        cin>>n;
        vector<long long> arr(n);
        long long ans=0;
        for(int i=0;i<n;i++) cin>>arr[i];
        sort(arr.begin(),arr.end());
        int maxi=arr[n-1];
        // for(int i=0;i<n;i++){
        //     long long sum=arr[i];
        //     long long rem=maxi-sum;
        //     int ind=lower_bound(arr.begin(),arr.begin()+n-1)-arr.begin();
        //     if(ind!=n-1){
        //         ans+=n-ind-1;
        //     }
        // }
        for(int i=0;i<n-1;i++){
            bool a=false;
            for(int j=i+1;j<n-1;j++){
                long long sum=arr[i]+arr[j];
                if(sum>maxi){
                    ans+=n-i-1;
                    ans+=n-i-2;
                    a=true;
                }
            if(a) break;
        }
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n-1;j++){
                long long sum=arr[i]+arr[j];
                long long rem=maxi-sum;
                if(sum<maxi){
                    int ind=upper_bound(arr.begin()+j+1,arr.begin()+n-1,rem)-arr.begin();
                    if(ind!=n-1){
                        ans+=n-ind-1;
                        }
                }
               // break;
            }
        }
    }
    cout<<ans<<endl;
}
}