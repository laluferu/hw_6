
#! /usr/bin/python
# coding: utf-8
from matplotlib import animation
from mpl_toolkits.mplot3d import Axes3D
import numpy as np # Importo el módulo de numpy.
import matplotlib.pyplot as plt #Importa módulo de gráficos.

#Iportar archivo
tray = genfromtxt("archivo.dat",delimiter=",")
x= tray[:,0]
y= tray[:,1]
u= tray[:,2]
v= tray[:,3]

#Generador de imagen gif  a partir de importar el modulo matplotlib como animation, alli se utiliza las funciones init() e instante(), para asi, generar el gif a partir de las dos funciones generadas que evaluan las condiciones ejercicio.

fig=plt.figure(figsize=(10,6), dpi=100)
ax = fig.gca(projection='3d')
X,Y = np.meshgrid(x,y)
w1 = ax.plot_wireframe(X,Y,u)
w2 = ax.plot_wireframe(X,Y,v)
tplot=plt.imshow(w1,cmap='gist_heat',vmin=0,vmax=1,interpolation='None')

def animate(i):
    
    if i == 0:
        init()
    else:
        instante()
    tplot.set_array(w1)

animacion = animation.FuncAnimation(fig, animate, repeticiones,interval=100, blit=False)
animacion.save('gif.gif',writer='imagemagick', fps = 6, dpi=50)
plt.show()
