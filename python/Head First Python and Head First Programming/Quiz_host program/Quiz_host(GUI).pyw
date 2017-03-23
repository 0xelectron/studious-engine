from tkinter import*

app= Tk()
app.title("TVN Game Show")
app.geometry('400x100+200+100')

import pygame.mixer

sounds = pygame.mixer
sounds.init()

correct_s = sounds.Sound("correct.wav")
wrong_s = sounds.Sound("wrong.wav")

number_correct = 0
number_wrong = 0

t1 = IntVar()   #create a text variable for b1
t2 = IntVar()  #create a text variable for b2

def play_correct_sound():
    global number_correct
    number_correct = number_correct + 1
    correct_s.play()
    t1.set(number_correct)

def play_wrong_sound():
    global number_wrong
    number_wrong = number_wrong + 1
    wrong_s.play()
    t2.set(number_wrong)

b1 = Button(app,text = 'Correct!',width = 10, command = play_correct_sound)
b1.pack(side = 'left', padx=10,pady=10)

b2 = Button(app,text= 'Wrong!',width=10,command=play_wrong_sound)
b2.pack(side='right',padx=10,pady=10)

msg = Label(app,text = 'Click buttons when you are ready!!',height = 2)
msg.pack(side='top')

l1=Label(app,textvariable = t1,height = 3)
l1.pack(side = 'left')

l2=Label(app,textvariable = t2,height = 3)
l2.pack(side = 'right')

app.mainloop()



