#include<bits/stdc++.h>
using namespace std;
#define int long long
struct SegmentTree {
    int n;
    vector<int> tree;

    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(1, 0, n - 1, arr);
    }

    void build(int node, int start, int end, vector<int>& arr) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = (start + end) / 2;
        build(2 * node, start, mid, arr);
        build(2 * node + 1, mid + 1, end, arr);
        tree[node] = __gcd(tree[2 * node], tree[2 * node + 1]);
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        int left = query(2 * node, start, mid, l, r);
        int right = query(2 * node + 1, mid + 1, end, l, r);
        return __gcd(left, right);
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid) update(2 * node, start, mid, idx, val);
        else update(2 * node + 1, mid + 1, end, idx, val);
        tree[node] = __gcd(tree[2 * node], tree[2 * node + 1]);
    }

    int query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }

    void update(int idx, int val) {
        update(1, 0, n - 1, idx, val);
    }
};
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,ans=0;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    SegmentTree st(arr);
    ans+=st.query(0,n-1);
    for(int i=1;i<n-1;i++){
        ans+=min(st.query(0,i),st.query(i,n-1));
    }
    cout<<ans<<endl;
}