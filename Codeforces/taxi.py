n = int(raw_input())
groups = map(int, raw_input().split())
ans = n
g1 = groups.count(1)
g2 = groups.count(2)
g3 = groups.count(3)

while g1!=0:
    if g3 > 0:
        g3 -= 1
        g1 -= 1
        ans -= 1
    elif g2 > 0:
        if g1 >= 2:
            g1 -= 2
            g2 -= 1
            ans -= 2
        else:
            g2 -= 1
            g1 -= 1
            ans -= 1
    else:
        if g1 >= 4:
            g1 -= 4
            ans -= 3 
        elif g1 >= 3:
            g1 -= 3
            ans -= 2 
        elif g1 >=2:
            g1 -= 2
            ans -= 1
        else:
            break
if g2 > 1:
    while g2 > 1:
        g2 -= 2 
        ans -=1
print ans
