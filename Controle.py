import keyboard  # using module keyboard
from tkinter import *
from functools import partial
import serial

arduino = serial.Serial('COM5', 9600)
print('Arduino conectado')

def bt_click_cima():
    arduino.write('8'.encode())

def bt_click_baixo():
    arduino.write('2'.encode())

def bt_click_esquerda():
    arduino.write('4'.encode())

def bt_click_direita():        
    arduino.write('6'.encode())

def bt_click_iniciar():
    arduino.write('i'.encode())

def bt_click_parar():
    arduino.write('p'.encode())

def bt_click_terminar():
    arduino.write('t'.encode())

def tecla(t):
    if t.keysym == 'Down':
        arduino.write('2'.encode())
    elif t.keysym == '2':
        arduino.write('2'.encode())
    elif t.keysym == 'Up':
        arduino.write('8'.encode())
    elif t.keysym == '8':
        arduino.write('8'.encode())
    elif t.keysym == 'Left':
        arduino.write('6'.encode())
    elif t.keysym == '6':
        arduino.write('6'.encode())
    elif t.keysym == 'Right':
        arduino.write('4'.encode())
    elif t.keysym == '4':
        arduino.write('4'.encode())
    elif t.keysym == 'i':
        arduino.write('i'.encode())
    elif t.keysym == 'p':
        arduino.write('p'.encode())
    elif t.keysym == 't':
        arduino.write('t'.encode())

def janela_control():

    janela = Tk()

    janela.title('Controle Analisador de Esporos')
    janela.iconbitmap('C:/Users/Roboxilique/Desktop/IC - Messias/iconutfpr.ico')
    janela.resizable(False, False)

    janela.configure(background='gray75')

    bt_cima = Button(janela, width=15, height=5, text='↑', font= ('calibri', 15, 'bold',), relief="ridge", command=partial(bt_click_cima))
    bt_cima.grid(column=1, row=0, sticky=NSEW)

    bt_baixo = Button(janela, width=15, height=5, text='↓', font= ('calibri', 15, 'bold',), relief="ridge", command=partial(bt_click_baixo))
    bt_baixo.grid(column=1, row=3, sticky=NSEW)

    bt_esquerda = Button(janela, width=15, height=5, text='←', font= ('calibri', 15, 'bold',), relief="ridge", command=partial(bt_click_esquerda))
    bt_esquerda.grid(column=0, row=1, sticky=NSEW)

    bt_direita = Button(janela, width=15, height=5, text='→', font= ('calibri', 15, 'bold',), relief="ridge", command=partial(bt_click_direita))
    bt_direita.grid(column=3, row=1, sticky=NSEW)

    bt_inicio = Button(janela, width=15, height=5, text='INICIAR', font= ('calibri', 15, 'bold',), relief="ridge", background='green', foreground = 'white', command=partial(bt_click_iniciar))
    bt_inicio.grid(column=3, row=0, sticky=NSEW)

    bt_parar = Button(janela, width=15, height=5, text='PARAR', font= ('calibri', 15, 'bold',), relief="ridge", background='red3', foreground = 'white', command=partial(bt_click_parar))
    bt_parar.grid(column=0, row=0, sticky=NSEW)

    bt_termino = Button(janela, width=15, height=5, text='TÉRMINO', font= ('calibri', 15, 'bold',), relief='ridge', command=partial(bt_click_terminar))
    bt_termino.grid(column=1, row=1, sticky=NSEW)

    janela.bind('<KeyPress>', tecla)

    janela.mainloop()

janela_control()



