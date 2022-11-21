T = [*input().split()]

if not sum(len(t) for t in T) <= 10**6: print("NG (Too long)"); exit(1)
print("OK")
