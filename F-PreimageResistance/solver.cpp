#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll LIMIT = 1LL <<  60;

signed main() {
    ll n, m, k; cin >> n >> m >> k; --k;
    string s; cin >> s;

    vector<string> A(n); for(auto &v : A) cin >> v;
    sort(A.begin(), A.end());

    array<vector<string>,26> f;
    for(auto &v : A) f[v.front()-'a'].emplace_back(v);

    vector<ll> p(m+1, 1);
    for(int i=m-1; i>=0; --i) {
        ll cur = f[s[i]-'a'].size();
        if(LIMIT/p[i+1] < cur) p[i] = INT64_MAX;
        else p[i] = p[i+1] * cur;
    }

    for(int i=0; i<m; ++i) {
        ll x = k / p[i+1];
        k %= p[i+1],
        cout << f[s[i]-'a'][x] << " \n"[i == m-1];
    }

    return 0;
}
