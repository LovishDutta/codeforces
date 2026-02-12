#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n;
        cin>>n;
        int cnt=1;
        vector<vector<int>> v;
        for(int i=0;i<n;i++){
            vector<int> temp(n);
            for(int j=0;j<n;j++){
                temp[j]=cnt++;
            }
            v.push_back(temp);
        }
        int ans=0;
        for(int i=0;i<n;i++){       
            for(int j=0;j<n;j++){
                int sum=v[i][j];
                if(i>0) sum+=v[i-1][j];
                if(i<n-1) sum+=v[i+1][j];
                if(j>0) sum+=v[i][j-1];
                if(j<n-1) sum+=v[i][j+1];
                ans=max(ans,sum);
            }
            
        }
        cout<<ans<<endl;
    }
}