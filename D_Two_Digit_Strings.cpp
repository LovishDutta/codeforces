#include<bits/stdc++.h>
using namespace std;
#define int long long
int funct(string a,string b){
    int n=a.size(),m=b.size(),prev=0,ans=0,idx=0;
    for(int i=idx;i<n;i++){
        vector<int> arr(10,-1);
        vector<int> ind(10,-1);
        int cnt=1,sum=0;
        for(int j=i;j<n;j++){
            sum=(sum+(a[j]-'0'))%10;
            if(arr[sum]==-1){
                arr[sum]=cnt;
                ind[sum]=j;
            }
            cnt++;
        }
        int newsum=0,cnt2=1,mini=1e9,newprev=prev,flag=0;
        for(int j=prev;j<m;j++){
            newsum=(newsum+(b[j]-'0'))%10;
            if(arr[newsum]!=-1){
                if(cnt2+arr[newsum]<mini){
                    mini=cnt2+arr[newsum];
                    newprev=j+1;
                    i=ind[newsum];
                    flag=1;
                }
            }
            cnt2++;
        }
        if(!flag) continue;
        prev=newprev;
        ans++;
    }
    return ans;
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        string a,b;
        cin>>a>>b;
       
        int n=a.size(),m=b.size(),sum=0,sum2=0;
        for(int i=0;i<n;i++) sum=(sum+a[i]-'0')%10;
        for(int i=0;i<m;i++) sum2=(sum2+b[i]-'0')%10;
        if(sum!=sum2){
            cout<<-1<<endl;
            continue;
        }
        int ans=max(funct(a,b),funct(b,a));
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        ans=max(funct(a,b),ans);
        ans=max(ans,funct(b,a));
        cout<<ans<<endl;
    }
}