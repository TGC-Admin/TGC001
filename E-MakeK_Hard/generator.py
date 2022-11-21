from random import randint

type = int(input())

if type == 0:
    l, r = map(int, input().split())
    print(r-l)
    for k in range(l, r):
        print(k)

if type == 1:
    t = int(input())
    print(t)
    for _ in [0] * t:
        k = randint(2, 7*10**4)
        print(k)
