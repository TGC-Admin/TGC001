
from collections import Counter
from subprocess import run


N, M, K = map(int, input().split())

if not 1 <= N <= 2*10**5: print("NG: N"); exit(1)
if not 1 <= M <= 2*10**5: print("NG: M"); exit(1)
if not 1 <= K <= 10**18: print("NG: K"); exit(1)

S = input()
if not len(S) == M: print("NG: |S|"); exit(1)

W = [input() for _ in [0] * N]

if not len(W) == len(set(W)): print("NG: W content (Not Unique)"); exit(1)

W0_count = Counter(map(lambda e: e[0], W))
for w in W:
    if not 1 <= len(w) <= 100: print("NG: |W_i|"); exit(1)

K_conds_max = 1
for c in S:
    K_conds_max = min(K_conds_max * W0_count[c], 10**18)

if not K <= K_conds_max: print("NG: K (Over conceivable maximum)"); exit(1)

print("OK")
