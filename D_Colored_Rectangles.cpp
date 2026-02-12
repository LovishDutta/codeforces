#include<bits/stdc++.h>
using namespace std;
#define int long long
int r,g,b;
int dp[201][201][201];
int recur(int i1,int i2,int i3,vector<int>& red,vector<int>& green,vector<int>& blue){
    int cnt=0;
    if(i1>=r) cnt++;
    if(i2>=g) cnt++;
    if(i3>=b) cnt++;
    if(cnt>=2) return 0;
    if(dp[i1][i2][i3]!=-1) return dp[i1][i2][i3];
    vector<int> ans;
    ans.push_back(0);
    if(i1<r&&i2<g){
        ans.push_back(red[i1]*green[i2]+recur(i1+1,i2+1,i3,red,green,blue));
        }
    if(i2<g&&i3<b){
        ans.push_back(blue[i3]*green[i2]+recur(i1,i2+1,i3+1,red,green,blue));
        }
    if(i1<r&&i3<b){
        ans.push_back(red[i1]*blue[i3]+recur(i1+1,i2,i3+1,red,green,blue));
        }
    return dp[i1][i2][i3]=*max_element(ans.begin(), ans.end());

}
signed main(){
        cin>>r>>g>>b;
        vector<int> red(r); 
        vector<int> green(g); 
        vector<int> blue(b); 
        for(int i=0;i<r;i++) cin>>red[i];
        for(int i=0;i<g;i++) cin>>green[i];
        for(int i=0;i<b;i++) cin>>blue[i];
        for(int i=0;i<201;i++){
            for(int j=0;j<201;j++){
            for(int k=0;k<201;k++){
            dp[i][j][k]=-1;
        }
        }
        }
         sort(red.rbegin(), red.rend());
    sort(green.rbegin(), green.rend());
    sort(blue.rbegin(), blue.rend());
        cout<<recur(0,0,0,red,green,blue);
}