from tkinter import*
def button_click1():
    print("You clicked button 1")
def button_click2():
    print("You clicked button2")
app = Tk()
app.title("TVN Quiz")
app.geometry('250x100+200+100')
b1 = Button(app,text='Correct!',width=10,command = button_click1)
b1.pack(side = 'left',padx=20,pady=20)
b2 = Button(app,text='Wrong!',width=10,command = button_click2)
b2.pack(side = 'right',padx=20,pady=20)

app.mainloop()
