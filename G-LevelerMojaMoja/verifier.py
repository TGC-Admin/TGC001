n, q = map(int, input().split())

if not 1 <= n <= 1000: print("NG: N"); exit(1)
if not 1 <= q <= 10**4: print("NG: Q"); exit(1)

A = [list(map(int, input().split())) for _ in [0] * n]

for a in A:
    for v in a:
        if not -10**9 <= v <= 10**9: print("NG: A_{i,j}"); exit(1)

for _ in [0] * q:
    k = int(input())
    if not 0 <= k <= 10**9: print("NG: K"); exit(1)

print("OK")
