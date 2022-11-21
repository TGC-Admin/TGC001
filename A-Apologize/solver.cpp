#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;

signed main() {
    char h0,h1,c; int w; cin >> h0 >> h1 >> c >> w;

    if(w == 0) cout << "have fun!";
    else if(w <= 5) cout << "sorry";
    else if(w <= 10) cout << "super sorry";
    else cout << "ultra sorry";
    cout << endl;

    return 0;
}
