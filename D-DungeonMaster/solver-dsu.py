from itertools import product

# Thanks to: https://note.nkmk.me/python-union-find/
class UnionFind():
    def __init__(self, n):
        self.n = n
        self.parents = [-1] * n

    def find(self, x):
        if self.parents[x] < 0:
            return x
        else:
            self.parents[x] = self.find(self.parents[x])
            return self.parents[x]

    def union(self, x, y):
        x = self.find(x)
        y = self.find(y)

        if x == y:
            return

        if self.parents[x] > self.parents[y]:
            x, y = y, x

        self.parents[x] += self.parents[y]
        self.parents[y] = x

    def roots(self):
        return [i for i, x in enumerate(self.parents) if x < 0]

    def group_count(self):
        return len(self.roots())

h, w = map(int, input().split())

G = [input() for _ in [0] * h]

uf = UnionFind(h*w+1)

def id(i, j):
    return i*w + j

for i, j in product(range(0, h), range(0, w)):
    if G[i][j] == '#': uf.union(id(i,j), h*w); continue
    if i+1 < h and G[i+1][j] == '.': uf.union(id(i,j), id(i+1,j))
    if j+1 < w and G[i][j+1] == '.': uf.union(id(i,j), id(i,j+1))

print(max(0, uf.group_count() - 2))
