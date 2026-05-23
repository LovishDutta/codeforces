#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,ans=0;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        if(n==1&&arr[0]<3){
            cout<<0<<endl;
            continue;
        }
        int i=0,j=n-1,cnt=0;
        while(i<=j){
            if(arr[j]>1){
                cnt++;
                ans+=arr[j];
                int free=(arr[j]/2)-1;
                //if(arr[j]%2) free++;
                arr[j]=0;
                while(i<=j&&free!=0&&arr[i]<=1){
                    if(arr[i]>=free){
                        ans+=free;
                        arr[i]-=free;
                        free=0;
                    }
                    else{
                        free-=arr[i];
                        ans+=arr[i];
                        arr[i]=0;
                        i++;
                    }
                }
            }

            j--;
        }
        if(cnt==1){
            int free=1;
            while(i<n&&free!=0){
                    if(arr[i]>=free){
                        ans+=free;
                        arr[i]-=free;
                        free=0;
                    }
                    else{
                        free-=arr[i];
                        ans+=arr[i];
                        arr[i]=0;
                        i++;
                    }
                }
        }
        cout<<ans<<endl;
    }
}