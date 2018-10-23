
import numpy as np
import matplotlib.pyplot as plt


intento=np.loadtxt("ejeyFailpoints.txt")
puntos=np.loadtxt("ejey3points.txt")


#pinta 4 bolas buenas y 10 malas iguales
plt.plot(puntos[:,0],puntos[:,1],'o')
plt.plot(puntos[:,0],puntos[:,1],'>')
plt.plot(puntos[:,0],puntos[:,1],'<')
plt.plot(puntos[:,0],puntos[:,1])
plt.plot(intento[:,0],intento[:,1],'b')
plt.hlines(3.6,5.2,5.7,colors='orange', linewidth=5) # la cesta
plt.hlines(3.4,5.3,5.6,colors='darkorange', linewidth=5) # la cesta
plt.hlines(3.2,5.4,5.5,colors='darkorange', linewidth=5) # la cesta
plt.vlines(0,0.0,2.5,linewidth=4)# MJ sche   

plt.axis("off")
plt.savefig("grafica.jpg")

plt.show()

