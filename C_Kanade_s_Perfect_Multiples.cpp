#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n,k;
        cin>>n>>k;
        set<int> st;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            st.insert(a);
        }
        set<int> ans;
        set<int> removed;
        bool flag=true;
        while(st.size()!=0){
            int a=*(st.begin());
            ans.insert(a);
            for(int i=1;a*i<=k;i++){
                if(st.find(a*i)==st.end()&&removed.find(a*i)==removed.end()){
                   flag=false;
                   break;
                }
                else{
                    st.erase(a*i);
                    removed.insert(a*i);
                }
            }
            if(!flag) break;
        }
        if(!flag){
            cout<<-1<<endl;
        }
        else{
            cout<<ans.size()<<endl;
            for(auto& it:ans) cout<<it<<" ";
            cout<<endl;
        }
    }
}