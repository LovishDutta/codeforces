#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n,l,r,s;
        cin>>n>>l>>r>>s;
        int x=r-l+1;
        if(((n*(n+1))/2)-((n-x)*(n-x+1))/2<s||(((x*(x+1))/2)>s)){
            cout<<-1<<endl;
        }
        else{
            map<int,int> mpp;
            map<int,int> mpp2;
            for(int i=1;i<=n;i++){
                mpp2[i]++;
            }
            for(int i=n;i>=1;i--){
                if(x==0) break;
                int maxlim=(i*(i+1))/2-((i-x)*(i-x+1))/2;
                int minlim=i+((x-1)*(x))/2;
                if(s>=minlim&&s<=maxlim){
                    mpp[i]++;
                    x--;
                    mpp2.erase(i);
                    s-=i;
                }
            }
            vector<int> ans(n,-1);
            auto it=mpp.begin();
            for(int i=l-1;i<r;i++){
                ans[i]=it->first;
                it++;
            }
            auto it2=mpp2.begin();
            for(int i=0;i<n;i++){
                if(ans[i]==-1){
                    ans[i]=it2->first;
                    it2++;
                }
            }
            for(int i=0;i<n;i++) cout<<ans[i]<<" ";
            cout<<endl;
        }
        }
}