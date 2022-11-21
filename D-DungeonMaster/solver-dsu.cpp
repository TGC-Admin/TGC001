#include <bits/stdc++.h>
#include <atcoder/dsu>

using namespace std;
using namespace atcoder;

signed main() {
    int h, w; cin >> h >> w;
    vector<string> G(h); for(auto &g : G) cin >> g;

    auto id = [&w](int i, int j) { return i*w + j; };

    dsu uf(w*h + 1);

    for(int i=0; i<h; i++) for(int j=0; j<w; j++) {
        if(G[i][j] == '#') {
            uf.merge(id(i,j), h*w);
            continue;
        }
        if(i+1 < h and G[i+1][j] == '.') uf.merge(id(i,j), id(i+1,j));
        if(j+1 < w and G[i][j+1] == '.') uf.merge(id(i,j), id(i,j+1));
    }

    cout << max(0, (int)uf.groups().size() - 2) << endl;

    return 0;
}
