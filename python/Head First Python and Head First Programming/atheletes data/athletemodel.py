import pickle
from athletelist import Athletelist

def get_coach_data(filename):
    try:
        with open(filename) as d:
            data = d.readline()
        templ = data.strip().split(',')
        return(Athletelist(templ.pop(0),templ.pop(0),templ))
    except IOError as err:
        print("File Error" + str(err))
        return(None)

def put_to_store(files_list):
    all_athletes={}
    for each_file in files_list:
        ath=get_coach_data(each_file)
        all_athletes[ath.name]= ath

    try:
        with open('athletes.pickle','wb') as athf:
            pickle.dump(all_athletes,athf)

    except IOError as err:
        print('File error(put and store): ' + err)
        
    return(all_athletes)
def get_from_store():
    all_athletes={}
    try:
        with open('athletes.pickle','rb') as athf:
            all_athletes = pickle.load(athf)

    except IOError as err:
        print('File error (get from store): ' + err)
        

    return(all_athletes)


    
        
