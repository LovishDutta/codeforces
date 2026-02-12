#include<bits/stdc++.h>
using namespace std;
#define int long long

long long pref[17] = {
    0LL,
    9LL,
    99LL,
    999LL,
    9999LL,
    99999LL,
    999999LL,
    9999999LL,
    99999999LL,
    999999999LL,
    9999999999LL,
    99999999999LL,
    999999999999LL,
    9999999999999LL,
    99999999999999LL,
    999999999999999LL,
    9999999999999999LL
};
 
long long prefix[17] = {
    0LL,
    9LL,
    189LL,
    2889LL,
    38889LL,
    488889LL,
    5888889LL,
    68888889LL,
    788888889LL,
    8888888889LL,
    98888888889LL,
    1088888888889LL,
    11888888888889LL,
    128888888888889LL,
    1388888888888889LL,
    14888888888888889LL,
    158888888888888889LL
};
 
 
 
int dp2[17][2][17*9];
int sumrecur(int ind,string& s,bool tight,int sum){
    if(ind==s.size()) return sum;
    if(dp2[ind][tight][sum]!=-1) return dp2[ind][tight][sum];
 
    int limit=tight?(s[ind]-'0'):9;
    int ans=0;
    for(int i=0;i<=limit;i++){
        int newsum=sum+i;
        ans+=sumrecur(ind+1,s,tight&&(i==s[ind]-'0'),newsum);
    }
    return dp2[ind][tight][sum]=ans;
}
signed main(){
    int c;
    cin>>c;    
    for(int z=0;z<c;z++){
        int k;
        cin>>k;
        int low=1;
        int high=k;
        int digdiff=0;
        while(low<=high){
            int mid=(low+high)/2;
            int b=(int)log10(mid);
            int dig=prefix[b]+(mid-pref[b])*(b+1);
            if(dig>=k) high=mid-1;
            else low=mid+1;
        }
        int b=(int)log10(low);
        int dig=prefix[b]+(low-pref[b])*(b+1);
        digdiff=dig-k;
        string s2=to_string(low);
        memset(dp2,-1,sizeof(dp2));
        int sum=sumrecur(0,s2,1,0);
       // cout<<digdiff<<endl;
        while(digdiff>0){
            sum-=low%10;
            low/=10;
            digdiff--;
        }
        cout<<sum<<endl;
    }
}