n = int(input())

cnt = 0

for i in range(1, n):
    for _ in range(i, n, i):
        cnt += 1

print(cnt)
