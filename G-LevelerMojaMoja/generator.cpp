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
        for(auto i=size_t(1), itr=first; itr!=last; i++) {
            (*this)[i] = (*this)[i-1] + *itr++;
        }
    }
    inline T operator()(size_t left, size_t right) const {
        return (*this)[right] - (*this)[left];
    }
};

random_device seed_generator;
mt19937 engine;

constexpr int MAX_A = 1000000000;
constexpr int MAX_K = 1000000000;

using Distr = uniform_int_distribution<int>;

signed main() {
    engine.seed(seed_generator());

    int n, q; cin >> n >> q;
    int l, r; cin >> l >> r;

    if(r < l) l = -MAX_A, r = MAX_A;
    Distr distr_A(l, r);

    vector<int> a(n*n);
    for(auto &v : a) v = distr_A(engine);

    cout << n << spc << q << ln;
    REP(i, n) REP(j, n) cout << a[i*n+j] << " \n"[j==n-1];

    auto b = a;
    sort(ALL(b));
    PrefixSum pre_sum(ALL(b));

    Distr distr_k_type(0, 3);

    Distr distr0(0, MAX_K);
    Distr distr1(0, n*n);
    Distr distr2(0, min((ll)MAX_K,
        n*n + reduce(
                ALL(a), 0LL,
                [](ll a, ll b) { return abs(a) + abs(b); }
            )
        ));
    Distr distr3(
        reduce(
            ALL(a), INF32,
            [](int a, int b) { return min(a, b); }
        ),
        reduce(
            ALL(a), -INF32,
            [](int a, int b) { return max(a, b); }
        )
    );
    Distr distr01(0, 1);

    REP(i, q) {
        top:
        ll k = -10;
        int k_type = distr_k_type(engine);
        if(k_type == 0) {
            k = distr0(engine);
        }
        if(k_type == 1) {
            k = distr1(engine);
        }
        if(k_type == 2) {
            k = distr2(engine);
        }
        if(k_type == 3) {
            k = MAX_K + 10;
            while(k > MAX_K) {
                int p = distr3(engine);
                auto itr = lower_bound(ALL(b), p);
                int cnt = distance(b.begin(), itr);
                ll rem = p * cnt - pre_sum(0, cnt);
                if(a[0] < p) --cnt;
                k = rem + cnt - distr01(engine);
            }
        }
        if(k < 0) goto top;
        cout << k << "\n";
    }

    return 0;
}
