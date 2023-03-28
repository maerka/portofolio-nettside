# https://en.wikipedia.org/wiki/Elastic_collision

import numpy as np
from matplotlib.patches import Circle
import matplotlib.pyplot as plt
from matplotlib import animation
import vectorFunctions as vf

"""----------- Class Particle ---------------------"""
class Particle():
    def __init__(self, id, mass, vx,vy, x,y, radius, styles = None):
        self.id = id
        self.mass = mass
        self.vel = np.array((vx,vy), dtype=float)
        self.pos = np.array((x,y),dtype=float)

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

    @property
    def vx(self):
        return self.vel[0]
    @vx.setter
    def vx(self, value):
        self.vel[0] = value
    @property
    def vy(self):
        return self.vel[1]
    @vy.setter
    def vy(self, value):
        self.vel[1] = value



    def draw(self,ax):
        circle = Circle(xy=self.pos, radius=self.radius, **self.styles)
        ax.add_patch(circle)
        return circle
    
    def updatePosition(self,dt):
        self.x += self.vx*dt
        self.y += self.vy*dt

        # Check for walls and make it bounce back
        if self.x<self.radius:
            self.x = self.radius
            self.vx *= -1
        elif windowX-self.x<self.radius:
            self.x = windowX-self.radius
            self.vx *= -1
        if self.y<self.radius:
            self.y = self.radius
            self.vy *= -1
        elif windowY-self.y<self.radius:
            self.y = windowY-self.radius
            self.vy *= -1

"""----------- Vector Mathematics ---------------------"""
def determinant(a,b): #Determinant of 2 n-dim vectors
    sum = 0
    for i in range(len(a)): sum+= a[i]*b[i]
    return sum
def vectorLength(a): #Length of 1 n-dim vectors
    sum=0
    for i in a:
        sum+=i**2
    return np.sqrt(sum)

def angleBetweenVectors(a,b): #Angle between 2 n-dim vectors. Returns theta = [radiants, degrees]
    theta = np.arccos(determinant(a,b)/(vectorLength(a)*vectorLength(b)))
    return [theta, theta*360/(np.pi*2)]

def findOrigo(b1,b2):
    ox = (b1.x-b2.x)/2 + b2.x
    oy = (b1.y-b2.y)/2 + b2.y
    return np.array((ox,oy))


"""----------- Collision functions ---------------------"""

def elasticCollisionX(pa, pb, updateVelocitites = False):
    """Takes in two particles and returns their velocities. Set updateVel to True to update particle velocitites"""
    ma=pa.mass
    mb=pb.mass
    v0a = pa.vx
    v0b = pb.vx
    v1a = (ma-mb)/(ma+mb)*v0a + (2*mb)/(ma+mb)*v0b
    v1b = (2*ma)/(ma+mb)*v0a + (mb-ma)/(ma+mb)*v0b

    #Update velocities in particles
    if updateVelocitites:
        pa.vx = v1a
        pb.vx = v1b
    return v1a, v1b

def elasticCollisionY(pa, pb, updateVelocitites = False):
    """Takes in two particles and returns their velocities. Set updateVel to True to update particle velocitites"""
    ma=pa.mass
    mb=pb.mass
    v0a = pa.vy
    v0b = pb.vy
    v1a = (ma-mb)/(ma+mb)*v0a + (2*mb)/(ma+mb)*v0b
    v1b = (2*ma)/(ma+mb)*v0a + (mb-ma)/(ma+mb)*v0b

    #Update velocities in particles
    if updateVelocitites:
        pa.vy = v1a
        pb.vy = v1b
    return v1a, v1b

def collision2D(pa,pb, updateVelocitites = False):
    distx=pa.x-pb.x
    disty=pa.y-pb.y
    
    


def checkOverlap(pa,pb):
    """Takes in two particles and check if they overlap"""
    distx = pa.x-pb.x
    disty = pa.y-pb.y
    dist = np.sqrt(distx**2 + disty**2)
    if dist < pa.radius + pb.radius: 
        return True
    else: return False
       
"""----------- Build Particles ---------------------"""
def buildNParticles(N, windowX,windowY,t,y=3):
    particles = []
    n = 0
    while n < N:
    # for n in range(N):
        x = np.random.randint(0,windowX*10)/10
        y = np.random.randint(0,windowY*10)/10
        m = np.random.randint(40,80)
        # m=50
        vx = np.random.randint(-30,30)/10
        vy = np.random.randint(-30,30)/10
        r = abs(m*t/windowX)
        r = abs(m**2*0.0012/windowX)
        # r=0.5
        # y = 3
        color = '#%06X' % np.random.randint(0,0xFFFFFF) #random colors
        style = {'color': color, 'fill': True, 'ec':'black'} #style of the particle
        #Must check if there is one there from before
        newParticle = Particle(n+1,m,vx,vy,x,y,r, style)
        # print('\nNewParticle x:',newParticle.x, round(r,2))
        # print(f'\nNewParticle: x={newParticle.x}, r={round(r,2)}, m={m}')

             

        if not particles:
            particles.append(newParticle)
            print(f'Added new particle: xy={round(x,1)},{round(y,1)}, r={round(r,2)}, m={m}, p={round(vx*m,1)}')
            n+=1
        for i, part in enumerate(particles):
            if checkOverlap(newParticle, part): 
                # print(f'Failed to add new particle {n} at {x}')
                break
            if len(particles)-i==1: 
                # particles.append(Particle(n+1,m,v0,x,y,r, style))
                particles.append(newParticle)
                print(f'Added new particle: xy={round(x,1)},{round(y,1)}, r={round(r,2)}, m={m}, p={round(vx*m,1)}')
                n+=1
    print(f'There are {len(particles)} in the list')
    return particles

def build3Particles():
    #object A
    ma = 10 #kg
    vxa,vya = 2,0 #m/s
    r = 1 
    xa, ya = 1,4
    particleA = Particle(1,ma,vxa,vya,xa,ya,r,{'color': 'b','ec':'black'})


    #object B
    mb = 40 #kg
    vxb,vyb = -2,0 #m/s
    r = 2
    xb, yb = 4,3
    particleB = Particle(2,mb,vxb,vyb,xb,yb,r, {'color': 'r','ec':'black'})


    #object C
    mc = 20 #kg
    vxc,vyc = -1,-1 #m/s
    r = 0.5
    xc, yc = 7,1
    particleC = Particle(3,mc,vxc,vyc,xc,yc,r, {'color': 'y','ec':'black'})
    # return [particleA, particleB, particleC]
    return [particleA, particleB]

def initNPlot():
    for part in allParticles:
        circles.append(part.draw(ax))
    time_text.set_text('t={:.2f}'.format(5)) #To use blit this part must be placed in initPlot as an object that can be animated 
    return circles    


"""----------- Animations ---------------------"""
def animateNParticlesExp(i):
    for part in allParticles:
        part.updatePosition(dt)
    combinations = allCombinations(allParticles)
    for pair in combinations:
        if checkOverlap(pair[0], pair[1]):
            vec = vf.vecCenterCenter(pair[0], pair[1])
            pair[0].vel, pair[1].vel = vf.projectVelocitiesObjects(pair[0], pair[1],vec)
            elasticCollisionX(pair[0], pair[1], True)
            elasticCollisionY(pair[0], pair[1], True)
    time_text.set_text('t={:.2f}'.format(i*dt)) #To use blit this part must be placed in initPlot as an object that can be animated 
    return circles

def animateNParticles(i):
    for part in allParticles:
        part.updatePosition(dt)
    combinations = allCombinations(allParticles)
    for pair in combinations:
        if checkOverlap(pair[0], pair[1]):
            elasticCollisionX(pair[0], pair[1], True)
            elasticCollisionY(pair[0], pair[1], True)
    time_text.set_text('t={:.2f}'.format(i*dt)) #To use blit this part must be placed in initPlot as an object that can be animated 
    return circles

def allCombinations(circleList):
    comb = []
    for i, c1 in enumerate(circleList):
        for c2 in circleList[i+1:]:
            comb.append((c1,c2))
    return comb



"""----------- MAIN ---------------------"""
"""Set window and figure"""



#Window
windowX = 15
windowY = windowX*2/5
fig, ax = plt.subplots(1,1,figsize=(10,4))
time_text = ax.text(0.65, 0.95,'', fontsize=15, transform=ax.transAxes, bbox=dict(facecolor='white', edgecolor='black'))
# ax.grid()
ax.set_xlim(0,windowX)
ax.set_ylim(0,windowY)
circles = []    #Storing the artisitcs? Alt the circles that will be animated. Required for using blit




"""Chosse which program to run"""
N=60    #Number of particles    
dt=0.010 #delta time --> speed of simulation. If too high, particles end up overlapping
t =0.001    #size of particles
y=windowY/2 #y-coordinate
allParticles = buildNParticles(N, windowX, windowY,t,y)
# allParticles = build3Particles()


anim = animation.FuncAnimation(fig,animateNParticles, init_func=initNPlot, frames=300, interval = 1, blit=True)


# anim.save('myAnimation2D.gif',writer=animation.PillowWriter(fps=20))
plt.show()
print('The End')



