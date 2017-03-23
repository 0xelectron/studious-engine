import string
word = raw_input()
w_len = 0

for char in word[1:]:
    if char == string.upper(char):
        w_len += 1
if word[0] == string.lower(word[0]) and w_len == (len(word)-1):
    print string.capitalize(word)
elif word[0] == string.upper(word[0]) and w_len == (len(word)-1):
    print string.lower(word)
else:
    print word
     
