#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int sum_of_devisors(int x) {
    int res = 0;
    for (int i=1; i*i<=x; i++) {
        if (x%i == 0) {
            res += i;
            if(i*i < x) res += x/i;
        }
    }
    return res;
}

constexpr int K_MAX = 70000;

signed main() {

    vector<int> dp(K_MAX+1, INT32_MAX / 2 - 1);
    dp[1] = 0;

    for(int i=1; i<K_MAX; ++i) {
        int divs_sum = sum_of_devisors(i);

        dp[i+1] = min(dp[i+1], dp[i] + 1);
        if(divs_sum <= K_MAX) dp[divs_sum] = min(dp[divs_sum], dp[i] + 1);
    }

    int t; cin >> t;
    for(int i=0; i<t; ++i) {
        int k; cin >> k;
        cout << dp[k] << endl;
    }

    return 0;
}
