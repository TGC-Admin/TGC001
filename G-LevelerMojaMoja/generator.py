from random import randint

MAX_N = 2500
MAX_A = 10**9
MAX_K = 10**9

n, q = map(int, input().split())

if n == 0: n = randint(0, MAX_N)
if n < 0: n = randint(-n//2, n)

l, r = map(int, input().split())

if r < l: l, r = -MAX_A, MAX_A

A = [[randint(l, r) for _ in [0] * n] for _ in [0] * n]

print(n, q)
for a in A: print(*a)

K = []

for _ in [0] * q:
    k = randint(0, 2)
    if k == 0: k = randint(0, min(MAX_K, n*n + sum(sum(abs(v) for v in a)  for a in A)))
    if k == 1: k = randint(0, MAX_K)
    if k == 2:
        k = MAX_K + 10
        while k > MAX_K:
            p = randint(min(min(a) for a in A), max(max(a) for a in A))
            cnt = sum(sum(v < p for v in a) for a in A)
            rem = sum(sum(p-v if v < p else 0 for v in a) for a in A)
            if A[0][0] <= p: cnt -= 1
            k = rem + cnt - randint(0, 1)
    K.append(k)

assert(len(K) == q)
print(*K, sep="\n")
