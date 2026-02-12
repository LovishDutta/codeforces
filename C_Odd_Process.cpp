#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n;
        cin>>n;
        vector<int> odd;
        vector<int> even;
        vector<int> ans;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            if(a%2==0) even.push_back(a);
            else odd.push_back(a);
        }
        
        int omax=0;
        if(odd.size()>0){
            sort(odd.begin(),odd.end());
            omax=odd[odd.size()-1];
            
        }
        if(even.size()>0){
            sort(even.begin(),even.end());
        }
        for(int i=1;i<even.size();i++){
            even[i]+=even[i-1];
        }
        for(int i=1;i<odd.size();i++){
            odd[i]+=odd[i-1];
        } 
        for(int i=1;i<=n;i++){
            int a=0;
            int rem=i;
            if(odd.size()>0){
                a=omax;
                rem--;   
            if(rem>0){
                int idx=even.size()-rem;
                if(idx>0&&even.size()!=0) a+=even[even.size()-1]-even[idx-1];
                else{  
                    if(even.size()!=0){
                        a+=even[even.size()-1];
                        rem-=(even.size());  
                    }     
                    if(rem>0&&rem%2!=0){
                        if(even.size()>0&&odd.size()-1>rem) a-=even[0];
                        else{
                            a=0;
                        }
                    }
                }
            }
        }
            ans.push_back((a%2==0)?0:a);

        }
        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl; 
    }
}