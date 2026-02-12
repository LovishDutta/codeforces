#include<bits/stdc++.h>
using namespace std;
int main(){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        vector<int> a(n,0);
        vector<int> b(n,0);
        if(s[0]=='a') a[0]=1;
        else b[0]=1;
        for(int i=1;i<n;i++){
            a[i]=a[i-1]+(s[i]=='a');
            b[i]=b[i-1]+(s[i]=='b');
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            int low=i;
            int high=n-1;
            if(s[i]=='a'){
                while(low<=high){
                    int mid=(low+high)/2;
                    if(k+b[i]>=b[mid]) low=mid+1;
                    else high=mid-1;
                }
                ans=max(ans,high-i+1);
                low=i;
                high=n-1;
                while(low<=high){
                    int mid=(low+high)/2;
                    if(k-1+a[i]>=a[mid]) low=mid+1;
                    else high=mid-1;
                }
                ans=max(ans,high-i+1);
            }
            else{
                while(low<=high){
                    int mid=(low+high)/2;
                    if(k+a[i]>=a[mid]) low=mid+1;
                    else high=mid-1;
                }
                ans=max(ans,high-i+1);
                low=i;
                high=n-1;
                 while(low<=high){
                    int mid=(low+high)/2;
                    if(k-1+b[i]>=b[mid]) low=mid+1;
                    else high=mid-1;
                }
                 ans=max(ans,high-i+1);
            }
        }
        cout<<ans<<endl;
}