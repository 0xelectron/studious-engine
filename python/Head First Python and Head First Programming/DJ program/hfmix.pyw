from tkinter import *
from sound_pannel import *
import pygame.mixer
import os


app=Tk()
app.title("Head First Mix")

mixer = pygame.mixer
mixer.init()

dirlist = os.listdir(".")
for fname in dirlist:
    if fname.endswith(".wav"):
        panel=soundpanel(app,mixer,fname)
        panel.pack()

def shutdown():
     mixer.stop()
     app.destroy()

app.protocol("WM_DELETE_WINDOW",shutdown)

app.mainloop()
