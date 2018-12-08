#!/usr/bin/env python

import subprocess
import sys
from tkinter import *


tab = sys.argv
vitesse = 0
fenetre = ""

def     ft_init():
    del tab[0]
    p = subprocess.Popen(["./push_swap", " ".join(tab)], stdout = subprocess.PIPE)
    out = p.communicate()
    return (out[0].decode("utf8").split("\n"))

def     ft_play():
    print("salut")

def     ft_stop():
    print("bye")


def     ft_init_pile(canvas):
    x = 630
    canvas.create_line((500,800), (500,0), fill='white', width=2)
    for elt in tab:
        x -= 1
        taille = (500 - int(elt) - 2)
        color = hex(int("ffffff", 16) - taille * 1000)
        color = color.replace("0x", "")
        canvas.create_line((0, x), (taille,x), fill='#'+color, width=2)
    
def     affiche():
    print(vitesse.get().isdecimal())
    if not vitesse.get().isdecimal() or int(vitesse.get()) > 10 or int(vitesse.get()) < 1:
        print("Entrez un Nombre entre 1 et 10")
    else:
        message = Label(fenetre, text="Notre fenêtre")
        message.pack()
        bouton = Button(fenetre, text='Play', command=ft_play)
        bouton.pack()
        bouton = Button(fenetre, text='Stop', command=ft_stop)
        bouton.pack()
        cadre = Canvas(fenetre, background="black", width=1000, height=800)
        cadre.pack()
        ft_init_pile(cadre)

        
def     ft_window(nb):
    global vitesse
    global fenetre
    fenetre = Tk()
    nb_instructions = Label(fenetre, text="<<<=Nombre d'instructions=>>>["+str(nb)+"]", width=100)
    nb_instructions.pack()
    vitesse = StringVar()
    vitesse.set("Choisi ta vitesse entre 1 et 10")
    vitesse = Entry(fenetre, textvariable=vitesse, width=30)
    vitesse.pack()
    bouton = Button(fenetre, text='Choisir', command=affiche)
    bouton.pack()

if __name__ == "__main__":
    instructions = ft_init()
    print(tab)
    print(instructions)
    ft_window(len(instructions) - 1)
    mainloop()
