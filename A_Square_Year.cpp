#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        // parse the 4-digit year into an integer Y
        int Y = (s[0]-'0')*1000 + (s[1]-'0')*100 + (s[2]-'0')*10 + (s[3]-'0');

        // integer sqrt
        int r = int(floor(sqrt(Y) + 1e-9));
        if (r*r != Y) {
            cout << -1 << "\n";
        } else {
            // (a + b) = r, pick a=0, b=r
            cout << 0 << " " << r << "\n";
        }
    }
    return 0;
}