#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n;
        cin>>n;
        vector<int> a(n);
        vector<int> b(n);
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++){ 
            cin>>a[i];
        }
        for(int i=0;i<n;i++){ 
            cin>>b[i];
        }
        int ind=0;
        bool found=false;
        if(a[n-1]==b[n-1]){ 
        ind=n-1;
        found=true;
    }
        else if(a[n-2]==b[n-2]||a[n-2]==a[n-1]||b[n-2]==b[n-1]){
            ind=n-2;
            found=true;
        }
        else{
            mpp[a[n-1]]++;
            mpp[a[n-2]]++;
            mpp[b[n-1]]++;
            mpp[b[n-2]]++;
            for(int i=n-3;i>=0;i--){
                mpp[a[i]]++;
                mpp[b[i]]++;
                if(mpp[a[i]]>1&&!(mpp[a[i]]==2&&a[i]==b[i+1])){
                    ind=i;
                    found=true;
                    break;
                }
                if(mpp[b[i]]>1&&!(mpp[b[i]]==2&&b[i]==a[i+1])){
                    ind=i;
                    found=true;
                    break;
                }
                
            }
        }
        if(found) ind+=1;
        cout<<ind<<endl;
    }
}