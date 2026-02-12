#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int x,k;
        cin>>k>>x;
        vector<int> av(k);
        cout<<"ji";
        for(int i=0;i<k;i++) av[i]=i+1;
        vector<int> ans;
        while(true){
            bool flag=false;
            for(int i=0;i<k;i++){
                if(ans.size()-x>=0&&ans[ans.size()-x]==av[i]) continue;
                ans.push_back(av[i]);
                flag=true;
                cout<<ans[ans.size()-1];
                break;
            }
            if(!flag) break;
        }
        cout<<ans.size()<<endl;
    }
}