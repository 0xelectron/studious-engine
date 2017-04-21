#!/bin/usr/env python3
import requests
from requests import ConnectionError
from bs4 import BeautifulSoup
from emailme import send_email
from datetime import (date, timedelta)


URL = 'http://www.gtu.ac.in/Circular.aspx'
PARSER = 'lxml'
KEYWORDS = ['be', '4', 'exam', 'form']
MONTH = {
        'JAN': 0,
        'FEB': 1,
        'MAR': 2,
        'APR': 3,
        'MAY': 4,
        'JUN': 5,
        'JUL': 6,
        'AUG': 7,
        'SEP': 8,
        'OCT': 9,
        'NOV': 10,
        'DEC': 11,
        }

d_pass = date.today() - timedelta(days=3)
msg = """ blip blop! just found out that forms for
semester 4 BE remedial have been available now. Please
fill up the form at college. For more information.
please checkout this link:
www.gtu.ac.in{}"""


try:
    html_doc = requests.get(URL).text
except ConnectionError:
    print("Something went worng!")

# fetch content
soup = BeautifulSoup(html_doc, PARSER)

# for a tags
for a in soup.find_all('a'):
    # strip whitespace
    t = a.text.strip().lower()

    # if all keywords in in the element
    if all([True if kw in t else False for kw in KEYWORDS]):
        # get the date of the published form
        _id = a.parent.parent['id'].replace('ContentHeading', 'UploadDate')
        d, m, y = soup.find("span", id=_id).text.split('-')
        m = m.upper()
        x = date(int(y), int(MONTH[m]), int(d))

        # if published date greater than 2 days
        if (x > d_pass):
            # send mail
            send_email(msg.format(a['href'][2:]))
