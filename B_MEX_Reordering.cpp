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
        int n;
cin>>n;
vector<int> arr(n);
for(int i=0;i<n;i++) cin>>arr[i];
sort(arr.begin(),arr.end());
bool flag=true;
for(int i=0;i<n-1;i++){
    if(mex(arr,0,i)==mex(arr,i+1,n-1)){
        flag=false;
        break;
    }
}
if(flag) cout<<"YES"<<endl;
else cout<<"NO"<<endl;
    }
}