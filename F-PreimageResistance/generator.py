from collections import Counter
from functools import reduce
from random import choice, randint, shuffle
from sys import stderr

N, M = map(int, input().split())

if N == 0: N = randint(0, 10**4)
if M == 0: M = randint(0, 10**4)

if N < 0: N = randint(-N//2, -N)
if M < 0: M = randint(-M//2, -M)

L_max0 = min(4*10**6 // M, 100)
L_max1 = min(10**6 // M, 30)
L_min = max(min(randint(1, 5), L_max1 - 3), 1)

W_set = set()
while len(W_set) < N: W_set.add("".join(chr(randint(ord('a'), ord('z'))) for _ in [0] * randint(L_min, L_max0 if randint(0, 50) == 0 else L_max1)))
W = list(W_set)

W0_count = Counter(map(lambda e: e[0], W))
S_conds = list(W0_count.keys())

S = ""
for _ in [0] * M: S += choice(S_conds)

K_conds_max = reduce(lambda a, b: min(10**18, a*b), (W0_count[c] for c in S))
K = randint(1, K_conds_max)

# print(K_conds_max, file=stderr)

shuffle(W)

print(N, M, K)
print(S)
print(*W, sep="\n")
