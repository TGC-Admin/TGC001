/*
 * @uni_kakurenbo
 * https://github.com/uni-kakurenbo/competitive-programming-workspace
 *
 * CC0 1.0  http://creativecommons.org/publicdomain/zero/1.0/deed.ja
 */
/* #language C++ GCC */
/* #region tmplate */
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_JUDGE
    #include<debug>
    #define debug(...) Debug::debug(Debug::split(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
    #define DEBUG(...) do { Debug::DEBUG(nullptr, "\033[3;35m#" + to_string(__LINE__) + "\033[m  "); Debug::DEBUG(__VA_ARGS__); Debug::DEBUG(nullptr, "\033[m\n"); } while(0);
#else
    #define debug(...) { ; }
    #define DEBUG(...) { ; }
#endif

#define INF32 2147483647
#define INF64 9223372036854775807LL

#define until(...) while(!(__VA_ARGS__))

#define REP(i,n) for(int i=0, i##_length=int(n); i<i##_length; ++i)
#define REPD(i,n) for(int i=(n)-1; i>=0; --i)
#define LOOP(n) REP(_$, (n))
#define FOR(i,l,r) for(ll i=(l), i##_last=ll(r); i<=i##_last; ++i)
#define FORD(i,l,r) for(ll i=(l), i##_last=ll(r); i>=i##_last; --i)

#define ITRP(x,v) for(auto x : (v))
#define ITRR(x,v) for(auto &x : (v))
#define ITR(x,v) for(const auto &x : (v))
#define ITRMP(x,y,v) for(auto [x, y] : (v))
#define ITRMR(x,y,v) for(auto &[x, y] : (v))
#define ITRM(x,y,v) for(const auto [x, y] : (v))

#define ALL(x) begin((x)),end((x))
#define RALL(x) rbegin((x)),rend((x))

#define $F first
#define $S second

using ll = long long;
using ull = unsigned long long;
using ld = long double;

constexpr char ln = '\n';
constexpr char spc = ' ';

template<class T1, class T2> inline auto mod(T1 x, T2 r) { return (x%r+r)%r; }

template<class T> inline bool chmax(T &a, T b) { return (a<b ? a=b, true : false); }
template<class T> inline bool chmin(T &a, T b) { return (a>b ? a=b, true : false); }

template<class T> auto operator<<(ostream &out, const T &val) -> decltype(val.val(), out)& {
    return out << val.val();
}
/* #endregion */

template<class I, class T = typename iterator_traits<I>::value_type, class C = vector<T>>
struct PrefixSum : C {
    PrefixSum() {}
    PrefixSum(I first, I last, T head = T()) {
        this->assign(distance(first,last)+1, head);
        for(auto i=1, itr=first; itr!=last; i++) {
            (*this)[i] = (*this)[i-1] + *itr++;
        }
    }
    inline T operator()(int left, int right) const {
        return (*this)[right] - (*this)[left];
    }
};

struct Solver {
    static constexpr int MAX = INF32;

    vector<int> a; int a0;
    PrefixSum<vector<int>::iterator,ll> pre_sum;

    Solver() {}

    void read(const int n) {
        a.resize(n*n);

        for(auto &v : a) cin >> v;

        a0 = a[0];
        sort(ALL(a));

        pre_sum = { ALL(a) };
    }

    ll needs(const ll p) const {
        auto itr = lower_bound(ALL(a), p);
        ll rem = transform_reduce(a.begin(), itr, 0LL, plus<ll>{}, [&](ll e) { return p-e; });
        int cnt = distance(a.begin(), itr);
        return rem + cnt - (a0 <= p);
    }

    int solve(int k) const {
        int a_min = *a.begin(), a_max = *a.rbegin();
        ll ok = a_min, ng = a_max + 1;
        while (ng - ok > 1) {
            ll mid = (ok+ng) / 2;
            (this->needs(mid) <= k ? ok : ng) = mid;
        }
        // assert(a_max >= ok);
        return a_max - ok;
    }
};

signed main() {
    int n, q; cin >> n >> q;

    Solver solver;
    solver.read(n);

    LOOP(q) {
        int k; cin >> k;
        cout << solver.solve(k) << ln;
    }

    return 0;
}
