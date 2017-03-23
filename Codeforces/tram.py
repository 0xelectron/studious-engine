n = int(raw_input())
t_passenger = 0
ans = 0

while (n>0):
    a, b = map(int, raw_input().split())
    t_passenger -= a
    t_passenger += b
    if t_passenger > ans:
        ans = t_passenger
    n -= 1

print ans

