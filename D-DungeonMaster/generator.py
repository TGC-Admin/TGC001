from random import randint

MAX_H = MAX_W = 1000

h, w, t = map(int, input().split())

if h == -1: h = randint(1, MAX_H)
if w == -1: w = randint(1, MAX_W)
if h == -2: h = MAX_H
if w == -2: w = MAX_W

if t == -1: t = h * w * randint(3, 17) // 10

G = [["#"] * w for _ in [0] * h]

for _ in [0] * t:
    i, j = randint(0, h-1), randint(0, w-1)
    G[i][j] = "."

print(h, w)
for g in G: print(*g, sep="")
