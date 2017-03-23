from random import randint
secret = randint(1,15)

guess = 0
while guess != secret:
        g = input("Guess a number between 1-15:")
        guess = int(g)
        if guess == secret:
                print("You Win.")
        else:
                if guess > secret:
                        print("Too High")
                else:   
                        print("Too Low")

print("Goodbye!")

