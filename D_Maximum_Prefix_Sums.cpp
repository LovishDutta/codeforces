#include<bits/stdc++.h>
using namespace std;
#define int long long
bool funct(vector<int>& a,vector<int>& c){
    int n=a.size();
    vector<int> b(n,a[0]),d(n,a[0]);
    for(int i=1;i<n;i++) b[i]=a[i]+b[i-1];
    for(int i=1;i<n;i++) d[i]=max(b[i],d[i-1]);
    for(int i=0;i<n;i++) if(c[i]!=d[i]) return false;
    return true;
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,ele,flag=1;
        cin>>n;
        string s;
        cin>>s;
        vector<int>a(n,-1),c(n),check(n,0);
        for(int i=0;i<n;i++){
            cin>>ele;
            if(s[i]=='1') a[i]=ele;
        }
        for(int i=0;i<n;i++){
            cin>>c[i];
                if(i==0||c[i]>c[i-1]){
                    check[i]=true;
                }
                else if(c[i]<c[i-1]){
                    flag=0;
                }
        }
        if(!flag||(s[0]=='1'&&a[0]!=c[0])){
            cout<<"No"<<endl;
            continue;
        }
        vector<int> temp;
        int asum=0;
        a[0]=c[0];
        s[0]='1';
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                temp.push_back(i);
            }
            else asum+=a[i];
            if(check[i]){
                if(temp.size() > 0){
                    int divi = c[i] - asum;
                    if (temp.size() == 1) {
                        a[temp[0]] = divi;
                    } else {
                        int num= -1000000000000000LL;
                        a[temp[0]] = num;
                        a[temp.back()] = divi - num;
                        for(int k = 1; k < temp.size() - 1; k++) {
                            a[temp[k]] = 0;
                        }
                    }
                    temp.clear();
                }
                asum = c[i];
            }
        }
        while(temp.size()!=0){
            a[temp[temp.size()-1]]=-1000000000000000LL;
            temp.pop_back();
        }
        if(funct(a,c)){
            cout<<"Yes"<<endl;
            for(int i=0;i<a.size();i++) cout<<a[i]<<" ";
            cout<<endl;
        }
        else cout<<"No"<<endl;
    }
}