T = int(input())

if not 1 <= T <= 10**4: print("NG: T"); exit(1)

sum_N = 0

for _ in [0] * T:
    N = int(input())
    S = input()

    if not 1 <= N <= 2*10**5: print("NG: N"); exit(1)

    if not N == len(S): print("NG: |S| != N"); exit(1)

    if not S.count('A') + S.count('T') + S.count('G') + S.count('C') + S.count('U') == N:
        print("S: content")

    sum_N += N

if not sum_N <= 10**6: print("NG: sum N")

print("OK")
