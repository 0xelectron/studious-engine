import urllib.request
import time
def get_price():
    page = urllib.request.urlopen("http://beans-r-us.appspot.com/prices.html")
    text = page.read().decode("utf8")
    where = text.find(">$")
    start_of_price= where + 2
    end_of_price=where + 6
    return(float(text[start_of_price:end_of_price]))
    
def send_to_twitter():
	msg = "I am a message that will be sent to Twitter"
	password_manager = urllib.request.HTTPPasswordMgr()
	password_manager.add_password("Twitter API",
	"http://twitter.com/statuses", "AAKASHPOMAL", "AAKASH9033")
	http_handler = urllib.request.HTTPBasicAuthHandler(password_manager)
	page_opener = urllib.request.build_opener(http_handler)
	urllib.request.install_opener(page_opener)
	params = urllib.parse.urlencode( {'status': msg} )
	resp = urllib.request.urlopen("http://twitter.com/statuses/update.json", params)
	resp.read()



require = input("Do you want price immediately(y/n)?")
if require == 'y':
    
    send_to_twitter()
else:
    price = 99.99
    while price > 4.74:
        
        time.sleep(900)
        send_to_twitter
    print("Buy!")
