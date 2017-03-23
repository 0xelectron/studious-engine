from athletelist import Athletelist


'''function to open the file and read each line and make a list from it and return an data object of class athlete'''

def get_coach_data(filename):
    try:
        with open(filename) as f:
            data = f.readline()
        templ = data.strip().split(',')
        return(Athletelist(templ.pop(0),templ.pop(0),templ))
    except IOError as ex:
        print('File error' + str(ex))
        return(None)

james=get_coach_data('james.txt')
    
print(james.name + " 's fastes times are: " + str(james.top3()))

julie=get_coach_data('julie.txt')

print(julie.name + " 's fastes times are: " + str(julie.top3()))

mikey =get_coach_data('mikey.txt')

print(mikey.name + " 's fastes times are: " + str(mikey.top3()))

sarah =get_coach_data('sarah.txt')

print(sarah.name + " 's fastes times are: " + str(sarah.top3()))
