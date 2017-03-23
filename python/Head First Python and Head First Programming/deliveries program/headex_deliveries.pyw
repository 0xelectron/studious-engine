def save_data():
    try:
        fileD = open("deliveries.txt",'a')
        fileD.write("Depot:\n")
        fileD.write("%s\n"%depot.get())
        fileD.write("Description:\n")
        fileD.write("%s\n"%description.get())
        fileD.write("Address:\n")
        fileD.write("%s"%address.get('1.0',END))
        depot.set(None)
        description.delete(0,END)
        address.delete('1.0',END)

    except Exception as ex:
        tkinter.messageboxx.showerror("Error!","Can't write to the file %s" % ex)
    
def read_depots(file):
    depots=[]
    fileR = open(file)
    for line in fileR:
        depots.append(line.rstrip())
    return depots
    

from tkinter import*

import tkinter.messagebox


app=Tk()
app.title('Head-Ex Deliveries')
Label(app,text = 'Depot: ').pack()
depot=StringVar()
options = read_depots("depots.txt")
OptionMenu(app,depot,*options).pack()
Label(app,text='Description: ').pack()
description = Entry(app)
description.pack()
Label(app,text = 'Address: ').pack()
address = Text(app)
address.pack()
Button(app,text='Save',command= save_data).pack()
app.mainloop()
