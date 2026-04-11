#include<bits/stdc++.h>
using namespace std;
#define int long long
static bool comp(pair<int,int>& p,pair<int,int>& q){
    if(p.second-p.first==q.second-q.first) return p.first>q.first;
    return p.second-p.first>q.second-q.first;
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,k,flag=1,oper=0;
        string s,t;
        cin>>n>>k>>s>>t;
        vector<pair<int,int>> arr;
        int last=n;
        char ch='!';
        for(int i=n-1;i>=0;i--){
            int j=i;
            if(last<j&&t[i]==ch) continue;
            if(last<j){
                j=last;
                while(j>=0&&s[j]!=t[i]) j--;
            }
            else{
                while(j>=0&&s[j]!=t[i]) j--;
            }
            //cout<<t[i]<<" "<<j<<endl;
            if(i!=j){
                if(i-j>k||j==-1){
                    flag=0;
                    break;
                }
                oper=max(oper,i-j);
                arr.push_back({j,i});
                //cout<<j<<" "<<i<<endl;
                //i=j+1;
                if(j<last){
                    last=j;
                    ch=t[i];
                }
            }
        }
        if(!flag){
            cout<<-1<<endl;
            continue;
        }
        //cout<<oper<<endl;
        sort(arr.begin(),arr.end(),comp);
        vector<string> ans;
        for(int j=oper;j>=1;j--){
            string s2;
            if(ans.size()>0){
                 s=ans[ans.size()-1];
                 s2=s;
            }
            else{
                s2=s;
            }
            for(int i=0;i<arr.size();i++){
                if(arr[i].second-arr[i].first<j) break;
                if(arr[i].second-arr[i].first==0) continue;
                //cout<<arr[i].second<<arr[i].first<<endl;
                s2[arr[i].first+1]=s[arr[i].first];
                arr[i].first++;
            }
            ans.push_back(s2);
            //cout<<s2<<endl;
        }
        //cout<<"hi";
        if(ans.size()>0&&ans[ans.size()-1]!=t){
            cout<<-1<<endl;
            continue;
        }
        cout<<oper<<endl;
        for(int i=0;i<oper;i++) cout<<ans[i]<<endl;
    }
}