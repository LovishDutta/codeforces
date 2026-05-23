#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[20][2]; 
int recur1(int idx, string& s, bool tight, vector<int>& check, vector<int>& power){
    if(idx == s.size()) return tight ? -4e18 : 0;
    if(dp[idx][tight] != -1) return dp[idx][tight];
    int n = s.size(), lim = tight ? s[idx] - '0' : 9;
    int ans = -4e18;
    for(int i = 0; i <= lim; i++){
        if((idx == 0 && i == 0 && n > 1) || check[i]){
            int res = recur1(idx + 1, s, tight & (i == lim), check, power);
            if(res != -4e18){
                ans = max(ans, i * power[n - idx - 1] + res);
            }
        }
    }
    return dp[idx][tight] = ans;
}
int recur2(int idx, string& s, bool tight, vector<int>& check, vector<int>& power){
    if(idx == s.size()) return tight ? 4e18 : 0;
    if(dp[idx][tight] != -1) return dp[idx][tight];
    int n = s.size(), lim = tight ? s[idx] - '0' : 0; 
    __int128 ans = 4e18; 
    for(int i = lim; i <= 9; i++){
        if((idx == 0 && i == 0) || check[i]){
            int res = recur2(idx + 1, s, tight & (i == lim), check, power);
            if(res != 4e18){
                __int128 current_val = (__int128)i * power[n - idx - 1] + res;
                if(current_val < ans) {
                    ans = current_val;
                }
            }
        }
    }
    if(ans > 4e18) ans = 4e18; 
    return dp[idx][tight] = (int)ans;
}
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;    
    while(tc--){
        int a, n, b, flag = 1;
        cin >> a >> n;
        vector<int> check(10, 0);
        vector<int> power(20, 1);  
        for(int i = 0; i < n; i++){
            cin >> b;
            check[b] = 1;
        }
        for(int i = 1; i <= 18; i++) power[i] = power[i - 1] * 10;    
        string s = to_string(a);
        for(int i = 0; i < s.size(); i++){
            if(!check[s[i] - '0']){
                flag = false;
                break;
            }
        }
        if(flag){
            cout << 0 << "\n";
            continue;
        }
        
        int diff1 = 4e18, diff2 = 4e18;
        
        memset(dp, -1, sizeof(dp));
        int val1 = recur1(0, s, 1, check, power);
        if (val1 != -4e18) diff1 = a - val1;    
        reverse(s.begin(), s.end());
        s.push_back('0');
        reverse(s.begin(), s.end());       
        memset(dp, -1, sizeof(dp));
        int val2 = recur2(0, s, 1, check, power);
        if (val2 != 4e18) diff2 = val2 - a;      
        cout << min(diff1, diff2) << "\n";
    }
}