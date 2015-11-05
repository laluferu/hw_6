from matplotlib import * 
from numpy import *

#Iportar archivo
tray = genfromtxt("trayectoria_E_alpha.dat",delimiter=",")

#Especificar x,y,z
x= tray[:,0]
y= tray[:,1]
z= tray[:,2]

#Caracteristicas de las graficas
x, y = meshgrid(x, y)
 
fig1 = figure(figsize=(14,7))
ax = fig1.add_subplot(1, 2, 2, projection='3d')
ax.plot_surface(x, y, z, rstride=1, cstride=1, cmap='hot')
title('Grafica en xyz. Trayectoria',fontsize=20)
xlabel('x',fontsize=20)
ylabel('y',fontsize=20)
ax2 = fig1.add_subplot(1, 2, 1)
p = ax2.plot(x, y)
title('Grafica en el plano xy. Trayectoria',fontsize=20)
xlabel('x',fontsize=20)
ylabel('y',fontsize=20)
show()

#Guardar como pdf
savefig("grafica.pdf")
