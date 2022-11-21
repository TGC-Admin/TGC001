概要
---
計算量に注意しつつ，条件を適切に言い換えて実装できるかを問う問題です．

問題原案：tnodino

略解
---
重複する整数を持つ生徒を同一のクラスに振り分けることはできません．  
この問題答えは各整数を持つ生徒の人数の最大値に一致することが証明できます．  
連想配列など用いて各整数が $A$ に登場する回数を数えればよいです．

解説
---

#### $Ⅰ.$ 条件の言い換え
「ある $1$ つのクラスに，等しい整数を持った生徒が $2$ 人以上存在しない」という条件から「等しい整数を持った $2$ 人以上の生徒を同一のクラスに振り分けることはではできない」ということが分かります．  
こちらに沿って考えてみましょう．

#### $Ⅱ.$ 数式を用いた証明
整数 $k$ を持った生徒が $C_k$ 人いるとします．  
先述した条件により，各 $k \in A$ について，クラスの個数は少なくとも $C_k$ 個必要であることが生じます．  
つまり，必要なクラスの個数は $K$ は $\forall_{k \in A} K \geq C_k$，すなわち $K \geq \max \limits_{k \in A} C_k$ を満たします．  
これを満たす $K$ の最小値は $\max \limits_{k \in A} C_k$ です．

#### $Ⅲ.$ 登場回数のカウント
$A$ 要素の範囲が $10^9$ 程度であることを考えると，連想配列やそれに準ずるデータ構造を用いるのがよいでしょう．

C++ では `std::map` や `std::unordered_map`，Python では `dict` や `collections.defaultdict` などが使えます．  
詳細は各言語のリファレンスや「実装例」の項を参照してください．  

#### $Ⅳ.$ 発展
##### $1)$ 類題
- [ABC 071](https://atcoder.jp/contests/abc071) $\hspace{0.15em}$ **[C - Make a Rectangle](https://atcoder.jp/contests/abc071/tasks/arc081_a)**
- [ABC 137](https://atcoder.jp/contests/abc137) $\hspace{0.15em}$ **[C - Green Bin](https://atcoder.jp/contests/abc137/tasks/abc137_c)**
- [ABC 210](https://atcoder.jp/contests/abc210) $\hspace{0.15em}$ **[C - Colorful Candies](https://atcoder.jp/contests/abc210/tasks/abc210_c)**

実装例
---
```cpp:C++
#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n; cin >> n;
    map<int,int> cnt;
    for(int i=0; i<n; ++i) { int a; cin >> a; ++cnt[a]; }
    cout << max_element(cnt.begin(), cnt.end(), [](auto a, auto b) { return a.second < b.second; })->second << "\n";
    return 0;
}

```
```py:Python
from collections import defaultdict
n = input()
A = [*map(int,input().split())]
cnt = defaultdict(int)
for a in A: cnt[a] += 1
print(max(cnt.values()))

```