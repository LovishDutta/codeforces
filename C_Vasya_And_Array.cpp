#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m,a,b,c,prev=1e9,flag=1;
    cin>>n>>m;
    vector<vector<int>> ones,zeros,arr;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        if(a==1) ones.push_back({b,c});
        else zeros.push_back({b,c});
    }
    sort(ones.begin(),ones.end());
    for(int i=0;i<ones.size();i++){
        int st=ones[i][0],end=ones[i][1],j=i;
        while(j<ones.size()&&ones[j][0]<=end){
            end=max(end,ones[j][1]);
            j++;
        }
        i=j-1;
        arr.push_back({st,end});
    }
    vector<int> ans(n+1,-1);
    for(int i=arr.size()-1;i>=0;i--){
        for(int j=arr[i][0];j<=arr[i][1];j++){
            ans[j]=(arr.size()-i)*(1e4);
        }
    }
    for(int i=1;i<=n;i++){
        if(ans[i]==-1) ans[i]=prev-1;
        else prev=ans[i];
        prev--;
    }
    for(int i=0;i<zeros.size();i++){
        bool f=true;
        for(int j=zeros[i][0];j<=zeros[i][1]-1;j++){
            if(ans[j]>ans[j+1]){
                f=false;
                break;
            }
        }
        if(f){
            flag=0;
            break;
        }
    }
    if(!flag) cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    }
}