# https://en.wikipedia.org/wiki/Elastic_collision

import numpy as np
from matplotlib.patches import Circle
import matplotlib.pyplot as plt
from matplotlib import animation


class Particle():
    def __init__(self, id, mass, v0, x,y, radius, styles = None):
        self.id = id
        self.mass = mass
        self.vel = v0
        self.pos = np.array((x,y),dtype=float)
        # self.pos = [x, y]
        self.radius = radius

        self.styles = styles
        if not self.styles:
            # Default circle styles
            self.styles = {'edgecolor': 'g', 'fill': True}

    @property
    def x(self):
        return self.pos[0]
    @x.setter
    def x(self, value):
        self.pos[0] = value
    @property
    def y(self):
        return self.pos[1]
    @y.setter
    def y(self, value):
        self.pos[1] = value

    def draw(self,ax):
        circle = Circle(xy=self.pos, radius=self.radius, **self.styles)
        ax.add_patch(circle)
        return circle
    
    def updatePosition(self,dt):
        self.x += self.vel*dt

        # Check for walls and make it bounce back
        if self.x<self.radius:
            self.x = self.radius
            self.vel *= -1
        elif windowX-self.x<self.radius:
            self.x = windowX-self.radius
            self.vel *= -1


def elasticCollision(pa, pb, updateVelocitites = False):
    """Takes in two particles and returns their velocities. Set updateVel to True to update particle velocitites"""
    ma=pa.mass
    mb=pb.mass
    v0a = pa.vel
    v0b = pb.vel
    v1a = (ma-mb)/(ma+mb)*v0a + (2*mb)/(ma+mb)*v0b
    v1b = (2*ma)/(ma+mb)*v0a + (mb-ma)/(ma+mb)*v0b

    # print('CRASH! va',round(v1a,1), 'vb',round(v1b,1))
    #Update velocities in particles
    if updateVelocitites:
        pa.vel = v1a
        pb.vel = v1b
    return v1a, v1b

def checkOverlap(pa,pb):
    """Takes in two particles and check if they overlap"""
    dist = abs(pa.x-pb.x)
    if dist < pa.radius + pb.radius: 
        return True
    else: return False
       
"""Simulating 3 particles"""
def build3Particles():
    #object A
    ma = 50 #kg
    v0a = 2 #m/s
    v1a = 0 #unknown
    r = abs(ma*v0a/100)
    # r = 0.5
    xa, ya = 2,3
    particleA = Particle(1,ma,v0a,xa,ya,r)


    #object B
    mb = 50 #kg
    v0b = -1 #m/s
    v1b = 0 #m/s
    r = abs(mb*v0b/100)
    # r = 0.5
    xb, yb = 7,3
    particleB = Particle(2,mb,v0b,xb,yb,r)


    #object C
    mc = 20 #kg
    v0c = 1 #m/s
    v1c = 0 #m/s
    r = abs(mc*v0c/100)
    # r = 0.5
    xc, yc = 5,3
    particleC = Particle(3,mc,v0c,xc,yc,r)

    return [particleA, particleB, particleC]

def init3Plot():
    plt.plot([0,windowX],[3,3], color='black')
    for part in allParticles:
        circles.append(part.draw(ax))
    time_text.set_text('t={:.2f}'.format(5)) #To use blit this part must be placed in initPlot as an object that can be animated 
    return circles    

def animate3Particles(i):
    dt = 0.05
    particleA =allParticles[0]
    particleB =allParticles[1]
    particleC =allParticles[2]

    particleA.updatePosition(dt)
    particleB.updatePosition(dt)
    particleC.updatePosition(dt)
    
    if checkOverlap(particleA, particleB):
        elasticCollision(particleA, particleB, True)
    if checkOverlap(particleA, particleC):
        elasticCollision(particleA, particleC, True)
    if checkOverlap(particleB, particleC):
        elasticCollision(particleB, particleC, True)
    time_text.set_text('t={:.2f}'.format(i*dt)) #To use blit this part must be placed in initPlot as an object that can be animated 
    return circles


"""Simulating N particles"""
def buildNParticles(N, windowX,t,y=3):
    particles = []
    n = 0
    while n < N:
    # for n in range(N):
        x = np.random.randint(0,windowX*10)/10
        m = np.random.randint(20,80)
        v0 = np.random.randint(-30,30)/10
        r = abs(m*t/windowX)
        # r=0.5
        # y = 3
        color = '#%06X' % np.random.randint(0,0xFFFFFF) #random colors
        style = {'color': color, 'fill': True, 'ec':'black'} #style of the particle
        #Must check if there is one there from before
        newParticle = Particle(n+1,m,v0,x,y,r, style)
        # print('\nNewParticle x:',newParticle.x, round(r,2))
        # print(f'\nNewParticle: x={newParticle.x}, r={round(r,2)}, m={m}')

             

        if not particles:
            particles.append(newParticle)
            print(f'Added new particle: x={newParticle.x}, r={round(r,2)}, m={m}, p={round(v0*m,1)}')
            n+=1
        for i, part in enumerate(particles):
            if checkOverlap(newParticle, part): 
                # print(f'Failed to add new particle {n} at {x}')
                break
            if len(particles)-i==1: 
                # particles.append(Particle(n+1,m,v0,x,y,r, style))
                particles.append(newParticle)
                print(f'Added new particle: x={newParticle.x}, r={round(r,2)}, m={m}, p={round(v0*m,1)}')
                n+=1
    print(f'There are {len(particles)} in the list')
    return particles

def initNPlot():
    plt.plot([0,windowX],[y,y], color='black')
    for part in allParticles2:
        circles.append(part.draw(ax))
    time_text.set_text('t= error: set blit to False') #To use blit this part must be placed in initPlot as an object that can be animated 
    return circles

def allCombinations(circleList):
    comb = []
    for i, c1 in enumerate(circleList):
        for c2 in circleList[i+1:]:
            comb.append((c1,c2))
    return comb

def animateNParticles(i):
    for part in allParticles2:
        part.updatePosition(dt)
    combinations = allCombinations(allParticles2)
    for pair in combinations:
        if checkOverlap(pair[0], pair[1]):
            elasticCollision(pair[0], pair[1], True)
    time_text.set_text('t={:.2f}'.format(i*dt)) #To use blit this part must be placed in initPlot as an object that can be animated 
    return circles


"""Set window and figure"""
#Window
windowX = 20
windowY = windowX*2/5
fig, ax = plt.subplots(1,1,figsize=(10,4))
time_text = ax.text(0.65, 0.95,'', fontsize=15, transform=ax.transAxes, bbox=dict(facecolor='white', edgecolor='black'))
ax.set_xlim(0,windowX)
ax.set_ylim(0,windowY)
circles = []    #Storing the artisitcs? Alt the circles that will be animated. Required for using blit


"""Chosse which program to run"""
NparticlesOr3Particles = 1  #1 for program 1 and 0 for program with 3 particles
if NparticlesOr3Particles:
    N=20    #Number of particles    
    dt=0.015 #delta time --> speed of simulation. If too high, particles end up overlapping
    t =0.15    #size of particles
    y=windowY/2 #y-coordinate
    allParticles2 = buildNParticles(N, windowX,t,y)
    anim = animation.FuncAnimation(fig,animateNParticles, init_func=initNPlot, frames=200, interval = 1, blit=False)
else:
    allParticles = build3Particles()
    anim = animation.FuncAnimation(fig,animate3Particles, init_func=init3Plot, interval = 50, blit=False)

writer0 = animation.PillowWriter(fps=10)
# anim.save('myAnimation3.gif',writer=writer0)
plt.show()
print('The End')



