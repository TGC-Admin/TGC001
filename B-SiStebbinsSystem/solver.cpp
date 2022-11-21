#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;

constexpr int mods[] =  { 0, 3, 6, 9, 12, 2, 5, 8, 11, 1, 4, 7, 10 };

signed main() {
    int n; cin >> n;
    cout << mods[(n-1)%13] << endl;
    return 0;
}
