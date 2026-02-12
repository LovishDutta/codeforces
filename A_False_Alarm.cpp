#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n,x;
        cin>>n;
        cin>>x;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        int start=0,end=0;
        for(int i=0;i<n;i++){
            if(arr[i]==1){
                start=i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(arr[i]==1){
                end=i;
                break;
            }
        }
        if(end-start>=x) cout<<"NO";
        else cout<<"YES";
        cout<<endl;

    }
}