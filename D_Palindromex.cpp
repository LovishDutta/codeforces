#include<bits/stdc++.h>
using namespace std;
#define int long long
bool check(vector<int>& arr,int mex){
    int n=arr.size(),i=0,j=0;
    for(int k=0;k<n;k++){
        if(arr[k]<mex){
             i=k;
             break;
        }
    }
    for(int k=n-1;k>=0;k--){
         if(arr[k]<mex){
            j=k;
            break;
         }
    }
    while(i<j){
        if(arr[i]!=arr[j]) return false;
        i++;
        j--;
    }
    return true;
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,ans=1;
        cin>>n;
        vector<int> arr(2*n);
        for(int i=0;i<2*n;i++) cin>>arr[i];
        // int low=0,high=n;
        // while(low<=high){
        //     int mid=(low+high)/2;
        //     if(check(arr,mid)) low=mid+1;
        //     else high=mid-1;
        // }
        // cout<<high<<endl;
        set<int> st1,st2,st3;
        for(int i=0;i<=n;i++){
            st1.insert(i);
            st2.insert(i);
            st3.insert(i);
        }
        int i=0,j=2*n-1,flag=1;
        while(i<2*n&&arr[i]!=0) i++;
        while(j>=0&&arr[j]!=0) j--;
        int x=i,y=j;
        while(x<=y){
            if(arr[x]!=arr[y]){
                flag=false;
                break;
            }
            st1.erase(arr[x]);
            x++;
            y--;
        }
        if(flag){
            x=i-1,y=j+1;
            while(x>=0&&y<=2*n-1){
                if(arr[x]!=arr[y]){
                    flag=false;
                    break;
                }
                st1.erase(arr[x]);
                x--;
                y++;
            }
            ans=max(ans,*(st1.begin()));
        }
        int a=i,b=i,c=j,d=j;
        while(a>=0&&b<=2*n-1){
                if(arr[a]!=arr[b]){
                    break;
                }
                st2.erase(arr[a]);
                a--;
                b++;
            }
        ans=max(ans,*(st2.begin()));
        while(c>=0&&d<=2*n-1){
                if(arr[c]!=arr[d]){
                    break;
                }
                st3.erase(arr[c]);
                c--;
                d++;
            }
        ans=max(ans,*(st3.begin()));
        cout<<ans<<endl;
    }
}