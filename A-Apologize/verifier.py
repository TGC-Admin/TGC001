h, w = map(int, input().split(":"))

if not 0 <= h < 24: print("NG: H"); exit(1)
if not 0 <= w < 60: print("NG: W"); exit(1)

print("OK")
