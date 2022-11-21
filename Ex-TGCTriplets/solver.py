from collections import defaultdict

MOD = 998244353
GC = "GC"
TAU = "TAU"

t = int(input())

for _ in [0] * t:
    n = int(input())
    S = input()

    if n == 1:
        print("52"[S[-1] in GC])
        continue

    if S[:-2].count("C") + S[:-2].count("G") == n - 2:
        print(pow(2, n-2, MOD) * int("52"[S[-1] in GC]) * int("52"[S[-2] in GC]) % MOD)
        continue

    S += "ATU"
    i = min(S.find("A"), S.find("T"), S.find("U"))
    assert(0 <= i < n)
    print(pow(2, i+1, MOD) * 5 % MOD)
