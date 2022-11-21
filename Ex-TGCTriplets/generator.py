from random import choice, randint
from sys import stderr

ATGCU = "ATGCU"
GC = "GC"
ATU = "ATU"

T, type, L, R = map(int, input().split())

if L == -1:
    R = min(2*10**5, 10**6 // T)
    L = R // 3

print(T)

for _ in [0] * T:
    N = randint(L, R)
    assert(N > 0)

    if type == -1: _type = randint(0, 5)
    else: _type = type

    if _type == 0:
        S = [choice(ATGCU) for _ in [0] * N]

    if _type == 1:
        char = choice(ATGCU)
        S = [char] * N

    if _type == 2:
        S = [choice(GC) for _ in [0] * N]

    if _type == 3:
        S = [choice(ATU) for _ in [0] * N]

    if _type == 4:
        if N <= 1:
            S = [choice(ATGCU) for _ in [0] * N]
        else:
            front = randint(1, N-1)
            S = [choice(GC) for _ in [0] * front]
            S.extend([choice(ATGCU) for _ in [0] * (N - front)])
        # print(S)

    if _type == 5:
        if N <= 2:
            S = [choice(ATGCU) for _ in [0] * N]
        else:
            S = [choice(GC) for _ in [0] * (N - 2)]
            S.append(choice(ATU))
            S.append(choice(ATU))

    assert(len(S) == N)

    print(N)
    print("".join(S))
