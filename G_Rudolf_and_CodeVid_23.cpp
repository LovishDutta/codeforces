#include<bits/stdc++.h>
using namespace std;

signed main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n,m;
        cin>>n>>m;
        string s;
        cin>>s;
        vector<int> days(m);
        vector<int> cure(m);
        vector<int> side(m);
        for(int i=0;i<m;i++){
            string s1,s2;
            cin>>days[i]>>s1>>s2;
            cure[i]=stoi(s1, nullptr, 2);
            side[i]=stoi(s2,nullptr,2);
            side[i]= side[i] & (~cure[i]);
        }
        int health=0,pow=1;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='1') health+=pow;
            pow*=2;
        }
        int ans=-1;
        vector<int> dis(1025,1e8);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,health});
        while(!pq.empty()){
            int d=pq.top().first;
            int h=pq.top().second;
            pq.pop();
            if(h==0){
                ans=d;
                break;
            }
            for(int i=0;i<m;i++){
                int newh= h &(~cure[i]);
                newh= newh|side[i];
            if(dis[newh]>d+days[i]){
                dis[newh]=d+days[i];
            pq.push({d+days[i],newh});
        }
    }
        }
        cout<<ans<<endl;
    }
}