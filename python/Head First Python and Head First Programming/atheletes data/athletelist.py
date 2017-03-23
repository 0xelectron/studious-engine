

class Athletelist(list):

    '''method to store name,dob,times in the data obj'''
    def __init__(self,a_name,a_dob=None,a_times=[]):
        list.__init__([])
        self.name = a_name
        self.dob = a_dob
        self.extend(a_times)
    '''Functuion to make time format in 'min.secs' format and remove '-' and ':' splitters from the time format'''

    def sanitize(time_string):

        if '-' in time_string:
            splitter = '-'
        elif ':' in time_string:
            splitter = ':'
        else :
            return time_string
        (mins,secs) = time_string.split(splitter)
        return(mins + '.' + secs)
    '''method to return top 3 scores(times) of the athlete'''
    
    def top3(self):
        return(sorted(set([sanitize(t) for t in self]))[0:3])
