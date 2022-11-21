#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MAX_K = 2000000;

signed main() {
    vector<int> dp(MAX_K+1, INT32_MAX / 2 - 1), div_sums(MAX_K+1, 0);
    dp[1] = 0;

    for(int i=1; i<MAX_K; ++i) {
        for(int j=i; j<=MAX_K; j+=i) div_sums[j] += i;
        dp[i+1] = min(dp[i+1], dp[i] + 1);
        if(div_sums[i] <= MAX_K) dp[div_sums[i]] = min(dp[div_sums[i]], dp[i] + 1);
    }

    int t; cin >> t;
    for(int i=0; i<t; ++i) {
        int k; cin >> k;
        cout << dp[k] << endl;
    }

    return 0;
}
