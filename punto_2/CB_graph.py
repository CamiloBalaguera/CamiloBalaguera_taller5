"""
Matplotlib Animation Example

author: Jake Vanderplas
email: vanderplas@astro.washington.edu
website: http://jakevdp.github.com
license: BSD
"""

import numpy as np
from matplotlib import pyplot as plt
from matplotlib import animation

data = np.genfromtxt("datos.dat", delimiter = " ")
datos = data[1:]
nx = data[0][0] - 2 # Tamaño de la dimension espacial
nt = data[0][1] # Tamaño de la dimension temporal.

# First set up the figure, the axis, and the plot element we want to animate
fig = plt.figure()
ax = plt.axes(xlim=(0, 100), ylim=(-1, 1))
line, = ax.plot([], [], lw=2)
# initialization function: plot the background of each frame
def init():
    line.set_data([], [])
    return line,

# animation function.  This is called sequentially
def animate(i):
    x = np.linspace(0, 100, nx)
    line.set_data(x, datos[i])
    return line,

# call the animator.  blit=True means only re-draw the parts that have changed.
anim = animation.FuncAnimation(fig, animate, init_func=init,interval = 10, blit=True)

# save the animation as an mp4.  This requires ffmpeg or mencoder to be
# installed.  The extra_args ensure that the x264 codec is used, so that
# the video can be embedded in html5.  You may need to adjust this for
# your system: for more information, see
# http://matplotlib.sourceforge.net/api/animation_api.html
anim.save('cuerda.mp4', fps=60, extra_args=['-vcodec', 'libx264'])
plt.show()
