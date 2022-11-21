from math import ceil, sqrt

K_MAX = 7*10**4

DP = [1<<32] * (K_MAX+1)
DP[1] = 0

def sum_of_divisors(x):
    return sum(i + (x//i if i*i<x else 0) if x%i == 0 else 0 for i in range(1, int(x**0.5)+1))

for i in range(1, K_MAX):
    DP[i+1] = min(DP[i+1], DP[i] + 1)
    div_sum = sum_of_divisors(i)
    if div_sum <= K_MAX: DP[div_sum] = min(DP[div_sum], DP[i] + 1)

t = int(input())
for _ in [0] * t:
    k = int(input())
    print(DP[k])
