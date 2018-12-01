import json
import pandas as pd
import numpy as np
from dateutil.parser import *

import csv

# with open("sleekr-data.json") as f:
#     data = json.loads(f.read())
#     with open("sleekr-data.csv", "w") as ff:
#         writer = csv.writer(ff)
#         for d in data:
#             for k in d.keys():
#                 writer.writerow([k, d[k]])



def main():
    # with open("/Users/akash/Downloads/dockup-aa0eb-SLEEKR-export.json") as f:
    #     raw_data = json.load(f)

    #     parsed_data = parse_data(raw_data)
    #     with open("test.json", "w") as ff:
    #         l = []
    #         for k in parsed_data.keys():
    #             l.append({str(k): parsed_data[k]})
    #         print(json.dumps(l))
    #         ff.write(json.dumps(l))

    # with open('sleekr-data.json') as f:
    #     raw_data = json.load(f)
     xs = []
    #     ys = []
    #     for d in raw_data:
    #         xs = parse(next(iter(d)))
    #         yy= d[x]


def parse_data(raw_data):
    data = dict()

    for d in raw_data:
        date = parse(raw_data[d]['timeStamp']).date()
        if date in data:
            data[date] += raw_data[d]['count']
        else:
            data[date] = raw_data[d]['count']

    return data

if __name__ == "__main__":
    main()



