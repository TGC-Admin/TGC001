from collections import defaultdict

K_MAX = 10**18

n, m, k = map(int, input().split())
k -= 1
S = input()
W = [input() for _ in [0] * n]
W.sort()

F = defaultdict(list)
for w in W:
    F[w[0]].append(w)

p = [1] * (m+1)
for i in range(m-1, 0, -1):
    p[i] = min(K_MAX, p[i+1] * len(F[S[i]]))

for i in range(0, m):
    x = k // p[i+1]
    k %= p[i+1]
    print(F[S[i]][x], end = " ")
print()
