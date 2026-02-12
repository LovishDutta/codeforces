#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int z = 0; z < t; z++)
    {
        int n, m, q;
        cin >> n >> m;
        vector<vector<int>> seg(m, vector<int>(2));
        for (int i = 0; i < m; i++)
        {
            cin >> seg[i][0] >> seg[i][1];
            seg[i][0]--;
            seg[i][1]--;
        }
        cin >> q;
        vector<int> ind(q);
        vector<int> pref(n);
        for (int i = 0; i < q; i++)
        {
            cin >> ind[i];
            ind[i]--;
        }
        int low = 0, high = q - 1;
        while (low <= high)
        {
            vector<int> pref(n);
            int mid = (low + high) / 2, cnt = 0;
            for (int i = 0; i <= mid; i++)
            {
                pref[ind[i]] = 1;
            }
            for (int i = 1; i < n; i++)
            {
                pref[i] += pref[i - 1];
            }
            for (int i = 0; i < m; i++)
            {
                int prev = seg[i][0] > 0 ? pref[seg[i][0] - 1] : 0;
                if (pref[seg[i][1]] - prev > (seg[i][1] - seg[i][0] + 1) / 2)
                    cnt++;
            }
            if (cnt < 1)
                low = mid + 1;
            else
                high = mid - 1;
        }
        cout << ((low) == q ? -1 : (low + 1)) << endl;
    }
}