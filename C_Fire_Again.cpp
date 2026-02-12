#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;

    int k;
    cin >> k;

    vector<pair<int, int>> vec;
    vector<vector<int>> adj(n + 1, vector<int>(m + 1, 1));
    queue<pair<int, int>> q;

    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        vec.push_back({x, y});
        adj[x][y] = 0;
    }

    int drow[] = {1, 0, 0, -1};
    int dcol[] = {0, 1, -1, 0};

    for (auto it : vec)
        q.push(it);

    int lastx = vec[0].first;
    int lasty = vec[0].second;

    while (!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        lastx = i;
        lasty = j;

        for (int z = 0; z < 4; z++) {
            int r = i + drow[z];
            int c = j + dcol[z];
            if (r > 0 && c > 0 && r <= n && c <= m && adj[r][c]) {
                q.push({r, c});
                adj[r][c] = 0;
            }
        }
    }

    cout << lastx << " " << lasty << endl;

    return 0;
}
