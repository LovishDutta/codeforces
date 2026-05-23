#include<bits/stdc++.h>
using namespace std;
#define int long long
void dfs(vector<vector<char>>& arr,vector<vector<int>>& vis,int i,int j,vector<int>& drow,vector<int>& dcol){
    vis[i][j]=1;
    int n=arr.size(),m=arr[0].size();
    for(int k=0;k<4;k++){
        int r=i+drow[k];
        int c=j+dcol[k];
        if(r>=0&&c>=0&&r<n&&c<m&&arr[r][c]!='#'&&vis[r][c]==0){
            dfs(arr,vis,r,c,drow,dcol);
        }
    }
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,m,flag=1;
        cin>>n>>m;
        vector<vector<char>> arr(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>arr[i][j];
            }
        }
        vector<int> drow={1,-1,0,0};
        vector<int> dcol={0,0,1,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]=='B'){
                    for(int k=0;k<4;k++){
                        int r=i+drow[k];
                        int c=j+dcol[k];
                        if(r>=0&&c>=0&&r<n&&c<m&&arr[r][c]=='G'){
                            flag=0;
                            break;
                        }
                        if(r>=0&&c>=0&&r<n&&c<m&&arr[r][c]=='.'){
                            arr[r][c]='#';
                        }
                    }
                }
                if(!flag) break;
            }
            if(!flag) break;
        }
        vector<vector<int>> vis(n,vector<int>(m,0));
        if(arr[n-1][m-1]!='#'){
            dfs(arr,vis,n-1,m-1,drow,dcol);
        }
        for(int i=0;i<n;i++){
            if(!flag) break;
            for(int j=0;j<m;j++){
                if((arr[i][j]=='G'&&vis[i][j]==0)){
                    flag=0;
                    break;
                }
            }
        }
        if(!flag) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
}