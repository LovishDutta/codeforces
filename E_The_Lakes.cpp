#include<bits/stdc++.h>
using namespace std;
#define int long long
int dfs(vector<vector<int>>& arr,vector<vector<int>>& vis,int i,int j){
    vis[i][j]=1;
    int ans=arr[i][j];
    int drow[]={1,-1,0,0};
    int dcol[]={0,0,1,-1};
    for(int k=0;k<4;k++){
        int r=i+drow[k];
        int c=j+dcol[k];
        if(r>=0&&c>=0&&r<arr.size()&&c<arr[0].size()&&!vis[r][c]&&arr[r][c]!=0){
            ans+=dfs(arr,vis,r,c);
        }
    }
    return ans;
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> arr(n,vector<int>(m));
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) cin>>arr[i][j];
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]&&arr[i][j]!=0){
                    ans=max(ans,dfs(arr,vis,i,j));
                }
            }
        }
        cout<<ans<<endl;
    }
}