#include<bits/stdc++.h>
using namespace std;
#define int long long
void fact(int a2,int a1,set<int>& possible){
    vector<int> f;
    int z=a2-a1;
    f.push_back(1);
    if(z > 1) f.push_back(z);
    for(int i=2;i*i<=z;i++){
        if(z%i==0){
            f.push_back(i);
            if(z/i!=i) f.push_back(z/i);
        }
    }
    for(int i=0;i<f.size();i++){
        for(int j=i+1;j<f.size();j++){
            int fj=max(f[i],f[j]),fi=min(f[i],f[j]);
            if((fi+fj)%2==0){
                int s1=(fj-fi)/2,s2=(fj+fi)/2;
                if(s2*s2-a2==s1*s1-a1&&s2*s2-a2>=0) possible.insert(s2*s2-a2);
            }
        }
    }
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,ans=1;
        cin>>n;
        vector<int> arr(n);
        set<int> possible;
        for(int i=0;i<n;i++) cin>>arr[i];
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                fact(max(arr[i],arr[j]),min(arr[i],arr[j]),possible);
            }
        }
        for(auto &it:possible){
            int cnt=0;
            for(int i=0;i<n;i++){
                int k=sqrt(it+arr[i]);
                if(k*k==it+arr[i]) cnt++;
            }
            ans=max(ans,cnt);
        }
        cout<<ans<<endl;
    }
}