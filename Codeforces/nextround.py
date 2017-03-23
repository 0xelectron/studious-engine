n, k = map(int, raw_input().split())
s_marks = map(int, raw_input().split())
s_pass = 0
for i in range(n):
    if (s_marks[i] >= s_marks[k-1]) and (s_marks[i] > 0):
        s_pass += 1

print s_pass

