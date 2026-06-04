#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    vector<int> arr(26,0);
    for(int i=0;i<26;i++){
        cin>>arr[i];
    }
    string s;
    cin>>s;
    int n=s.size(),ans=0;
    vector<int> pref(n);
    for (int i = 0; i < n; i++) {
    int w = arr[s[i] - 'a'];
    pref[i] = w + (i ? pref[i-1] : 0);
    }
    vector<vector<int>> mpp(26);
    for(int i=0;i<n;i++){
        mpp[s[i]-'a'].push_back(i);
    }
    for(int i=0;i<26;i++){
        map<int,int> freq;
        int k=mpp[i].size();
        for(int j=k-1;j>0;j--){
            freq[pref[mpp[i][j]-1]]++;
        }
        for(int j=0;j<k-1;j++){
            if(j>0){
                freq[pref[mpp[i][j]-1]]--;
                if(freq[pref[mpp[i][j]-1]]==0) freq.erase(pref[mpp[i][j]-1]);
            }
            int val=pref[mpp[i][j]];
            auto it=freq.find(val);
            if(it!=freq.end()) ans+=it->second;
        }
    }
    cout<<ans<<endl;
}