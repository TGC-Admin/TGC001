T = int(input())

if not 1 <= T <= 10**5: print("NG: T"); exit(1)

K = [int(input()) for _ in [0] * T]

for k in K:
    if not 2 <= k <= 2*10**6: print("NG: K"); exit(1)

print("OK")
