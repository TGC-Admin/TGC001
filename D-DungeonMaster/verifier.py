h, w = map(int, input().split())

if not 1 <= h <= 2500: print("NG: H"); exit(1)
if not 1 <= w <= 2500: print("NG: W"); exit(1)

G = [input() for _ in [0] * h]

for g in G:
    if len(g) != w: print("NG: G width"); exit(1)
    for p in g:
        if p not in ".#": print("NG: G content"); exit(1)

print("OK")
