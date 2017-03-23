import time
def make_smoothie():
    juice = input("what juice would you like?")
    fruit = input("ok - And what about fruit")
    print("Thanks. Lets Go!")
    time.sleep(3)
    print("Crushing the ice...")
    time.sleep(3)
    print("Blending the " + fruit)
    time.sleep(3)
    print("Now adding in the " + juice + " juice")
    time.sleep(3)
    print("Finished! There's Your " + fruit + " and " + juice + " Smoothie!")

another = 'y'
while another == 'y':
    make_smoothie()
    another = input("How about another(y/n)?")
    
print("Thank You!")    
