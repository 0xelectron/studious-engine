t_str = raw_input()
a_str = ""
for char in t_str:

    if not (char == 'a' or char == 'e' or char == 'i' or char == 'o' or char == 'u' or char == "y"
            or char == 'A' or char == 'E' or char == 'I' or char == 'O' or char == 'U' or char == "Y"):
        a_str +="."
        a_str +=char.lower()

print a_str
