#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n,h,l,cnt1=0,cnt2=0,ans=0;
        cin>>n>>h>>l;
        vector<int> arr(n);
        if(l>h) swap(l,h);
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]<=h&&arr[i]>l) cnt1++;
            else if(arr[i]<=l) cnt2++;
        }
        if(cnt1<cnt2){
            ans=(cnt1+cnt2)/2;
        }
        else ans=cnt2;
        cout<<ans<<endl;
    }
}