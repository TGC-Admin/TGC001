K_MAX = 2*10**6
S = [0] * (K_MAX+1)
DP = [1<<32] * (K_MAX+1)
DP[1] = 0
for i in range(1, K_MAX):
    for j in range(i, K_MAX+1, i):
        S[j] += i
    DP[i+1] = min(DP[i+1], DP[i] + 1)
    if S[i] <= K_MAX:
        DP[S[i]] = min(DP[S[i]], DP[i] + 1)

t = int(input())
for _ in [0] * t:
    k = int(input())
    print(DP[k])
