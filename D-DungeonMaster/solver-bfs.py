from collections import deque
from itertools import product
from sys import stdin

input = stdin.readline
DXY = ((0, 1), (1, 0), (0, -1), (-1, 0))

h, w = map(int, input().split())

G = [input() for _ in [0] * h]

que = deque()
visited = [False] * (h * w)
cnt = 0

def id(i, j):
    return i*w + j

for si, sj in product(range(0, h), range(0, w)):
    if G[si][sj] == '#': continue

    cnt += not visited[id(si,sj)]
    que.append((si, sj))

    while len(que) > 0:
        i, j = que.popleft()
        for di, dj in DXY:
            ni, nj = i + di, j + dj
            if not 0 <= ni < h or not 0 <= nj < w: continue
            if visited[id(ni,nj)] or G[ni][nj] == '#': continue
            visited[id(ni,nj)] = True
            que.append((ni, nj))

print(max(0, cnt - 1))
