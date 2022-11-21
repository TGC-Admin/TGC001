#include <bits/stdc++.h>

using namespace std;

using Point = pair<int,int>;
constexpr Point DXY[] = { { 0, 1 }, { 1, 0 }, { -1, 0 }, { 0, -1 } };

signed main() {
    int h, w; cin >> h >> w;
    vector<string> G(h); for(auto &g : G) cin >> g;

    auto id = [&w](int i, int j) { return i*w + j; };

    queue<Point> que;
    vector<int> visited(h*w, false);

    int cnt = 0;
    for(int si=0; si<h; si++) for(int sj=0; sj<w; sj++) {
        if(G[si][sj] == '#') continue;

        cnt += !visited[id(si,sj)];

        que.emplace(si, sj), visited[id(si,sj)] = 0;
        while(!que.empty()) {
            auto [i, j] = que.front(); que.pop();
            for(int d=0; d<4; ++d) {
                auto [ni, nj] = DXY[d]; ni += i, nj += j;
                if(ni < 0 or nj < 0 or ni >= h or nj >= w) continue;
                if(visited[id(ni,nj)] or G[ni][nj] == '#') continue;
                visited[id(ni,nj)] = true;
                que.emplace(ni, nj);
            }
        }
    }

    cout << max(0, cnt - 1) << endl;

    return 0;
}
