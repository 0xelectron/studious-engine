import pygame.mixer

def wait_finish(channel):
    while channel.get_busy():
        pass

sounds = pygame.mixer
sounds.init()

correct_s = sounds.Sound("correct.wav")
wrong_s = sounds.Sound("wrong.wav")

number_asked = 0
number_correct = 0
number_wrong = 0

prompt="Press 1 for correct,2 for incorrect,0 to end: "
option  =  input(prompt)

while option != '0':
    if option == '1':
        number_asked = number_asked + 1
        number_correct = number_correct + 1
        wait_finish(correct_s.play())
    if option == '2':
        number_asked = number_asked + 1
        number_wrong = number_wrong + 1
        wait_finish(wrong_s.play())
    if option != '1' and  option!='2':
        print("please enter valid number!!")
    option = input(prompt)

print("You asked "+ str(number_asked) + " no. of  Questions.")
print(str(number_correct) + " were answered correctly.")
print(str(number_wrong) +" were answered incorrectly.")

    
    
