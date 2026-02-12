#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);    
}
int main(){
    int t;
    cin>>t;    
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        int arr[n];
        vector<int> ans;
        for(int i=0;i<n;i++){
            cin>>arr[i];
           if(arr[i]!=i+1) ans.push_back(abs(i+1-arr[i]));
        }
        if(ans.size()==0) cout<<1<<endl;
        else{
            int a=ans[0];
            for(int i=1;i<ans.size();i++){
              //  cout<<endl<<"ele="<<ans[i]<<endl;
                a=gcd(ans[i],a);
            }
            cout<<a<<endl;
        }
        
    }
}