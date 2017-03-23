m, n = map(int, raw_input().split())
if m%2 == 0:
    print n*(m/2)
else:
    ans = n*(m/2) + (n/2)
    print ans
    
