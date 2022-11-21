from random import randint

N_MAX = 2500
A_MAX = 10**9

n = int(input())
k = randint(0, 10**9 if randint(0,3) == 0 else n)

if n == 0: n = randint(0, N_MAX)
if n < 0: n = randint(-n//2, n)

l, r = map(int, input().split())

if r < l: l, r = -A_MAX, A_MAX

A = [[randint(l, r) for _ in [0] * n] for _ in [0] * n]

print(n, k)
for a in A: print(*a)
