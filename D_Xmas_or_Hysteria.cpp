#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n,m;
        cin>>n>>m;
        vector<int> arr(n);
        priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> pq;
        vector<pair<int,int>> ans;
        vector<pair<int, int>> vec;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            pq.push({arr[i],i+1});
        }
        if(m>n/2) cout<<-1<<endl;
        else{
            bool flag=true;
            while(!pq.empty()){
                auto it=pq.top();
                pq.pop();
                vec.push_back(it);
            }
            if(m==0){
                int h=vec[n-1].first;
                int k=0;
                while(k<n-2&&h>vec[n-2].first){
                    h-=vec[k].first;
                    ans.push_back({vec[k].second,vec[n-1].second});
                    k++;
                }
                while(k<n-2){
                    ans.push_back({vec[k].second,vec[k+1].second});
                    k++;
                }
                if(h<=vec[n-2].first) ans.push_back({vec[n-2].second,vec[n-1].second});
                else{
                    flag=false;
                    cout<<-1<<endl;
                }
            }
            else{
            for(int i=0;i<n-2*m;i++){
                ans.push_back({vec[i].second,vec[i+1].second});
            }
            for(int i=0;i<m;i++){
                ans.push_back({vec[n-i-1].second,vec[i+n-2*m].second});
            }
        }
        if(flag){
            cout<<ans.size()<<endl;
            for(int i=0;i<ans.size();i++){
                cout<<ans[i].first<<" "<<ans[i].second<<endl;
            }
        }
        }
    }
}