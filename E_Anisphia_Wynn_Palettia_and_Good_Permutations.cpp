#include <bits/stdc++.h>
using namespace std;

// Sieve for smallest prime factor (spf)
vector<int> build_spf(int n) {
    vector<int> spf(n+1);
    for (int i = 2; i <= n; ++i) spf[i] = 0;
    for (int i = 2; i <= n; ++i) {
        if (!spf[i]) {
            spf[i] = i;
            if ((long long)i * i <= n) {
                for (int j = i*i; j <= n; j += i)
                    if (!spf[j]) spf[j] = i;
            }
        }
    }
    return spf;
}

vector<int> sieve_primes(int n) {
    vector<bool> isPrime(n+1, true);
    isPrime[0]=isPrime[1]=false;
    for (int p=2; (long long)p*p<=n; ++p) if (isPrime[p])
        for (int j=p*p;j<=n;j+=p) isPrime[j]=false;
    vector<int> primes;
    for (int i=2;i<=n;i++) if (isPrime[i]) primes.push_back(i);
    return primes;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n; cin >> n;
        if (n <= 0) { cout << "\n"; continue; }
        if (n == 1) { cout << "1\n"; continue; }

        vector<int> spf = build_spf(n);
        vector<int> primes = sieve_primes(n);

        // map prime value -> its index in primes[]
        unordered_map<int,int> prime_index;
        prime_index.reserve(primes.size()*2);
        for (int i = 0; i < (int)primes.size(); ++i) prime_index[primes[i]] = i;

        // buckets per prime-index: map from vector<int> (list of smaller prime indices present) -> vector of numbers
        int P = primes.size();
        vector< map<vector<int>, vector<int>> > buckets(P);

        // put 1 aside (first element)
        vector<int> answer;
        answer.reserve(n);
        answer.push_back(1);

        // factor each x and distribute
        for (int x = 2; x <= n; ++x) {
            int t = x;
            vector<int> pf; // distinct prime factors in ascending order
            while (t > 1) {
                int p = spf[t];
                if (pf.empty() || pf.back() != p) pf.push_back(p);
                t /= p;
            }
            // largest prime factor
            int pmax = pf.back();
            int idx = prime_index[pmax];

            // build list of indices of smaller primes present (indices in primes[])
            vector<int> smaller_idxs;
            smaller_idxs.reserve(pf.size());
            for (int k = 0; k + 1 < (int)pf.size(); ++k) {
                smaller_idxs.push_back(prime_index[pf[k]]);
            }
            buckets[idx][smaller_idxs].push_back(x);
        }

        // For each prime index i from 0..P-1 produce groups in desired order
        for (int i = 0; i < P && (int)answer.size() < n; ++i) {
            // collect key-value pairs (key = vector<int> of smaller prime indices, val = vector<int> numbers)
            vector<pair<vector<int>, vector<int>>> groups;
            groups.reserve(buckets[i].size());
            for (auto &kv : buckets[i]) {
                auto vec = kv.first;
                auto &vals = kv.second;
                sort(vals.begin(), vals.end());
                groups.emplace_back(vec, vals);
            }

            // custom sort keys: compare presence of smaller primes from smallest prime (index 0) upward.
            // A key A should come before B if at the first smaller-prime index j where they differ,
            // A has that prime present and B does not.
            auto cmp_keys = [&](const pair<vector<int>, vector<int>>& A,
                                const pair<vector<int>, vector<int>>& B) -> bool {
                // create presence check by iterating j from 0..i-1
                // since A.first and B.first are small vectors (few primes), we do binary_search on them
                for (int j = 0; j < i; ++j) {
                    bool a_has = binary_search(A.first.begin(), A.first.end(), j);
                    bool b_has = binary_search(B.first.begin(), B.first.end(), j);
                    if (a_has != b_has) return a_has; // a_has==true -> A before B
                }
                return false; // equal keys
            };

            sort(groups.begin(), groups.end(), cmp_keys);

            // append in this order
            for (auto &kv : groups) {
                for (int v : kv.second) {
                    if ((int)answer.size() < n) answer.push_back(v);
                    else break;
                }
                if ((int)answer.size() >= n) break;
            }
        }

        // If something weird happened and we have fewer than n elements (shouldn't), fill with remaining numbers ascending
        if ((int)answer.size() < n) {
            vector<char> used(n+1, 0);
            for (int v : answer) if (v>=1 && v<=n) used[v]=1;
            for (int x=1;x<=n && (int)answer.size()<n; ++x) if (!used[x]) answer.push_back(x);
        }

        // print first n numbers
        for (int i = 0; i < n; ++i) {
            if (i) cout << ' ';
            cout << answer[i];
        }
        cout << '\n';
    }
    return 0;
}
