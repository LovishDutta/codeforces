#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n;
        cin>>n;
        vector<int> arr;
        vector<int> ans;
        for(int i=2;i<=n-1;i++) arr.push_back(i);
        ans.push_back(1);
        ans.push_back(n);
        for(int i=n-2;i>=1;i--){
            int p=ans[ans.size()-1];
            for(int k=0;k<arr.size();k++){
                if(arr[k]!=-1&&abs(arr[k]-p)%i==0){
                    ans.push_back(arr[k]);
                    arr[k]=-1;
                    break;
                }
            }
        }
        for(int i=n-1;i>=0;i--) cout<<ans[i]<<" ";
        cout<<endl;
    }
}