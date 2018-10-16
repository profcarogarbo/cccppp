
import numpy as np
import matplotlib.pyplot as plt

import matplotlib.pyplot as plt
import matplotlib.animation as animation
from matplotlib.widgets import Slider


fig, ax1 = plt.subplots()
ax1.grid()

fig.subplots_adjust(left=0.1, bottom=0.35)

colors = ["blue", "grey"]
labels = ["ball", "cesta"]
static = [ax1.plot([], [], '-', c = colors[i], label = labels[i])[0] for i in range(2)]
dynamic = [ax1.plot([], [], 'o', c = colors[i])[0] for i in range(2)]

ax1.legend(fontsize=12).get_frame().set_alpha(0.0) # legenda en la grafica
ax1.set_xlabel("$x$ (m)")
ax1.set_ylabel("$y$ (m)")

# subejes para los sliders
axb = plt.axes([0.25, 0.1, 0.65, 0.03]) 
axangle = plt.axes([0.25, 0.15, 0.65, 0.03])
axspeed = plt.axes([0.25, 0.20, 0.65, 0.03])

# sliders
sb = Slider(axb, '$b$', 0.0001, 10, valinit=5)
sangle = Slider(axangle, 'Angle', 1, 89.0, valinit=45)
sspeed = Slider(axspeed, 'Speed', 1, 10.0, valinit=5)

N = 100

def init(*vals):
    global xs, ys, b
    x=np.loadtxt("ejexpoints.txt")
    xs=[0.0,6.0] #[:,0]
    
    archivo =np.loadtxt("ejey3points.txt")
    ys=[0.0,10.0]
#    ys[1]=archivo[:,0]
    
    for i in range(2):
        static[i].set_data(xs[i], ys[i])
    
    return xs, ys

archivo=np.loadtxt("allpoints.txt")


sb.on_changed(init)
sangle.on_changed(init)
sspeed.on_changed(init)


def update(i):
    for j in range(2):
        dynamic[j].set_data(xs[j][i], archivo[j][i])
    return tuple(dynamic)

#ani = animation.FuncAnimation(fig, update, N, interval = N/5, init_func=init)
ani = animation.FuncAnimation(fig, archivo, N, interval = N/5, init_func=init)

#ani.save("ProjectileMotion.gif", writer = "imagemagick", fps = N/5)
plt.show()
