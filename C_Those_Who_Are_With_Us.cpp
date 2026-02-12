#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int r,c;
        cin>>r>>c;
        int row=0,col2=-1,row2=-1,col=0,maxi=INT_MIN;
        vector<vector<int>> arr(r,vector<int>(c,0));
        vector<vector<int>> arr2(r,vector<int>(c,0));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cin>>arr[i][j];
                arr2[i][j]=arr[i][j];
                if(arr[i][j]>maxi){
                    maxi=arr[i][j];
                    row=i;
                    col=j;
                }
                if(arr[i][j]==maxi&&i!=row&&j!=col){
                    col2=j;
                    row2=i;
                }
            }
        }
        if(row2!=-1&&col2!=-1){

            for(int i=0;i<r;i++){
                arr[i][col2]-=1;
            }
            for(int i=0;i<c;i++){
                if(i!=col2) arr[row][i]-=1;
            }
            int ans=INT_MIN;
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    if(arr[i][j]>ans){
                        ans=arr[i][j];
                    }
                }
            }
            for(int i=0;i<r;i++){
                arr2[i][col]-=1;
            }
            for(int i=0;i<c;i++){
                if(i!=col) arr2[row2][i]-=1;
            }
            int ans2=INT_MIN;
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    if(arr2[i][j]>ans2){
                        ans2=arr2[i][j];
                    }
                }
            }
            cout<<min(ans,ans2)<<endl;
        }
        else{
            int max2=INT_MIN,rr=-1,cc=-1;
            for(int i=0;i<r;i++){
                    if(arr[i][col]==maxi) continue;  
                    if(arr[i][col]>max2){
                        rr=i;
                        max2=arr[i][col];
                    }  
            }
            for(int i=0;i<c;i++){
                    if(arr[row][i]==maxi) continue;  
                    if(arr[row][i]>max2){
                        cc=i;
                        max2=arr[row][i];
                    }  
            }
            if(cc!=-1) col=cc;
            else if(rr!=-1) row=rr;
             for(int i=0;i<r;i++){
                arr2[i][col]-=1;
            }
            for(int i=0;i<c;i++){
                if(i!=col) arr2[row][i]-=1;
            }
            int ans3=INT_MIN;
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    if(arr2[i][j]>ans3){
                        ans3=arr2[i][j];
                    }
                }
            }
            cout<<ans3<<endl;
        }
    }
}