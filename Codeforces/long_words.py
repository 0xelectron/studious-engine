n = int(raw_input())
words = []
while(n>0):
    words.append(raw_input())
    n -= 1
for word in words:
    if len(word) <= 10:
        print word
    else:
        s_word = ""
        s_word += word[0]
        s_word += str(len(word)-2) 
        s_word += word[-1]
        print s_word
