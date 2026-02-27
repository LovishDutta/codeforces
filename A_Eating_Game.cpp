#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
    int n,sum=0;
    cin>>n;
    vector<int> a(n);
    vector<int> arr(n);
    for(int i=0;i<n;i++){
         cin>>a[i];
         sum+=a[i];
    }
    set<int> st;
    for(int i=0;i<n;i++){
        for(int k=0;k<n;k++) arr[k]=a[k];
        int cnt=0,j=i;
        while(sum>cnt){
           if(arr[j]>0){
             cnt++;
             arr[j]--;
           }
            j=(j+1)%n;
        }
        //int idx=j-1<0?n-1:j-1;
        st.insert(j);
    }
    cout<<st.size()<<endl;
    }
}