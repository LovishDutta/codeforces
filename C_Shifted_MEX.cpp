#include<bits/stdc++.h>
using namespace std;
int mex(vector<int>& a, int l, int r) {
    int len = r - l + 1;
    vector<bool> seen(len + 1, false);
    for (int i = l; i <= r; i++) {
        if (a[i] >= 0 && a[i] <= len)
            seen[a[i]] = true;
    }
    for (int i = 0; i <= len; i++) {
        if (!seen[i]) return i;
    }
    return len + 1;
}
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n,ans=1;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
             cin>>arr[i];
        }
        for(int i=0;i<n;i++){
            int ele=-1*arr[i];
            for(int j=0;j<n;j++){
                arr[j]+=ele;
                
            }
            ans=max(ans,mex(arr,0,n-1));
            for(int j=0;j<n;j++){
                arr[j]-=ele;
               
            }
        }
        ans=max(ans,mex(arr,0,n-1));
        cout<<ans<<endl;

    }
}