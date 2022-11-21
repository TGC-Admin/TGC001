from random import randint

h, w = map(int, input().split())

if h == -1: h = randint(0, 23)
if w == -1: w = randint(0, 69)

print(str(h).zfill(2), ":", str(w).zfill(2), sep="")
