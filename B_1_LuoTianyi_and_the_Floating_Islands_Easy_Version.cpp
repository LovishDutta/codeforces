#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7; // 998244353;
 
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

int dfs(int node,vector<vector<int>>& adj,vector<int>& vis,mint& ans){
    vis[node]=1;
    int sum=1,n=adj.size();
    mint ab=0;
    vector<mint> vec;
    for(auto& it:adj[node]){
        if(!vis[it]){
            int a=dfs(it,adj,vis,ans);
            sum+=a;
            vec.push_back(a);
        }
    }
    vec.push_back(n-sum);
    for(int i=0;i<vec.size();i++){
        ab+=vec[i]*(n-1-vec[i]);
    }
    ans+=ab/2;
    //cout<<sum<<" "<<node<<endl;
    return sum;
}
signed main(){
        int n,k,a,b;
        cin>>n>>k;
        vector<vector<int>> adj(n);
        vector<int> vis(n,0);
        for(int i=0;i<n-1;i++){
            cin>>a>>b;
            adj[a-1].push_back(b-1);
            adj[b-1].push_back(a-1);
        }
        if(k==1||k==3){
            cout<<1<<endl;
            return 0;
        }
        mint ans=0;
        dfs(0,adj,vis,ans);
        
        cout<<(2*ans/(n*(n-1)))+2<<endl;
    }