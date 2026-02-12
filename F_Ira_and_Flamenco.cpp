#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
 
struct mint{
    int x;
 
    mint (){ x = 0;}
    mint (int32_t xx){ x = xx % mod; if (x < 0) x += mod;}
    mint (long long xx){ x = xx % mod; if (x < 0) x += mod;}
 
    int val(){
        return x;
    }
    mint &operator++(){
        x++;
        if (x == mod) x = 0;
        return *this;
    }
    mint &operator--(){
        if (x == 0) x = mod;
        x--;
        return *this;
    }
    mint operator++(int32_t){
        mint result = *this;
        ++*this;
        return result;
    }
    
    mint operator--(int32_t){
        mint result = *this;
        --*this;
        return result;
    }
    mint& operator+=(const mint &b){
        x += b.x;
        if (x >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint &b){
        x -= b.x;
        if (x < 0) x += mod;
        return *this;
    }
    mint& operator*=(const mint &b){
        long long z = x;
        z *= b.x;
        z %= mod;
        x = (int)z;
        return *this;
    }
    mint operator+() const {
        return *this;
    }
    mint operator-() const {
        return mint() - *this;
    }
    mint operator/=(const mint &b){
        return *this = *this * b.inv();
    }
    mint power(long long n) const {
        mint ok = *this, r = 1;
        while (n){
            if (n & 1){
                r *= ok;
            }
            ok *= ok;
            n >>= 1;
        }
        return r;
    }
    mint inv() const {
        return power(mod - 2);
    }
    friend mint operator+(const mint& a, const mint& b){ return mint(a) += b;}
    friend mint operator-(const mint& a, const mint& b){ return mint(a) -= b;}
    friend mint operator*(const mint& a, const mint& b){ return mint(a) *= b;}
    friend mint operator/(const mint& a, const mint& b){ return mint(a) /= b;}
    friend bool operator==(const mint& a, const mint& b){ return a.x == b.x;}
    friend bool operator!=(const mint& a, const mint& b){ return a.x != b.x;}
    mint power(mint a, long long n){
        return a.power(n);
    }
    friend ostream &operator<<(ostream &os, const mint &m) {
        os << m.x;
        return os;
    }
    explicit operator bool() const {
        return x != 0;
    }
};
signed main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n,m;
        cin>>n>>m;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        map<int,int> mpp;
        sort(arr.begin(),arr.end());
        int j=0,prev=0;
        mint ans=0,final=0;
            while(j<n&&arr[j]-arr[0]<m){
                mpp[arr[j]]++;
                j++;
            }
            while(j<n&&mpp.size()!=m){
                int ele=arr[prev];
                mpp.erase(ele);
                while(prev<n&&arr[prev]==ele) prev++;
                while(j<n&&arr[j]-arr[prev]<m){
                mpp[arr[j]]++;
                j++;
            }
            }
            if(mpp.size()==m){
                ans=1;
                for(auto& it:mpp) ans=(ans*it.second);
                final+=ans;
                for(int i=j;i<n;i++){
                    ans/=mpp[arr[prev]];
                    int ele=arr[prev],k=i;
                    mpp.erase(ele);
                    while(prev<n&&arr[prev]==ele) prev++;
                    while(k<n&&arr[k]-arr[prev]<m){
                        mpp[arr[k]]++;
                        k++;
                    }
                    if(mpp.size()==m){
                        ans*=mpp[arr[k-1]];
                        final+=ans;
                    }
                    i=k-1;
                }
            }
            cout<<final<<endl;
    }
}