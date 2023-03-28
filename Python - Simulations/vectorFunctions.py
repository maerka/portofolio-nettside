import numpy as np

def determinant(a,b):
    sum = 0
    for i in range(len(a)): sum+= a[i]*b[i]
    return sum
def vectorLength(a):
    sum=0
    for i in a:
        sum+=i**2
    return np.sqrt(sum)

def angleBetweenVectors(a,b):
    theta = np.arccos(determinant(a,b)/(vectorLength(a)*vectorLength(b)))
    return [theta, theta*360/(np.pi*2)]

def projection(a,b):
    #Projection of vector a onto vecor b
    dotProduct = determinant(a,b)
    bLen = vectorLength(b)
    projection = dotProduct/bLen
    return projection

def pointOnParaLine(line,t):  #Gives the coordinate for a point on a parameterized line(t) given t
    # print('point',point)
    # print('vec',vec)
    x = line[0][0] + line[1][0]*t
    y = line[0][1] + line[1][1]*t
    # x = point[0]+vec[0]*t
    # y = point[1]+vec[1]*t
    return np.array((x,y))

def vecCenterCenter(b1,b2):
    dx = b2.x-b1.x  #Delta x between centers
    dy = b2.y-b1.y  #Delta y between centers
    return np.array([dx,dy]) ##vector from center1 to center2


def newCoordinateSystem(b1,b2):
    point1 = np.array([b1.x,b1.y]) #Center of ball1
    point2 = np.array([b2.x,b2.y]) #Center of ball2
    dx = b2.x-b1.x  #Delta x between centers
    dy = b2.y-b1.y  #Delta y between centers
    vec = np.array([dx,dy]) ##vector from center1 to center2
    line1 = np.array((point1,vec)) #2D array with parameterized line: [[point_x, point_y], [vec_x,vec_y]] from center1 to center2
    line2 = np.array((point2,vec*-1)) #2D array with parameterized line: [[point_x, point_y], [vec_x,vec_y]] from center2 to center1


    t1_sq = np.sqrt(b1.r**2/(vec[0]**2 + vec[1]**2))    #intersectio between radius1 and param.line direction of ball2
    t2_sq = np.sqrt(b2.r**2/(vec[0]**2 + vec[1]**2))    #intersectio between radius2 and param.line direction of ball1

    paraPoint1 = pointOnParaLine(line1,t1_sq)   #Intersection point ball1
    paraPoint2 = pointOnParaLine(line2,t2_sq)   #Intersection point ball2

    print('point1:',point1,'paraPoint1:', paraPoint1)
    print('point2:',point2,'paraPoint2:', paraPoint2)

    ox = (paraPoint2[0]-paraPoint1[0])/2 + paraPoint1[0]   #x for new origo
    oy = (paraPoint2[1]-paraPoint1[1])/2 + paraPoint1[1]   #y for new origo
    

    #Returns new Origo(x,y) and vector of x-axis
    return np.array((ox,oy)),vec

def projectVelocitiesObjects(b1,b2,vector):
    vectorNormal = vector.copy()
    vectorNormal = np.flip(vectorNormal)
    vectorNormal[0] = -vectorNormal[0]
    
    # vx1 = projection(b1.vel[0], vector)
    # vy1 = projection(b1.vel[1], vectorNormal)
    # vx2 = projection(b2.vel[0], vector)
    # vy2 = projection(b2.vel[1], vectorNormal)
    vx1 = projection(b1.vel, vector)
    vy1 = projection(b1.vel, vectorNormal)
    vx2 = projection(b2.vel, vector)
    vy2 = projection(b2.vel, vectorNormal)
    return np.array((vx1,vy1)), np.array((vx2,vy2))

def projectVelocities2(b1,b2):
    origo, xaxis = newCoordinateSystem(b1,b2)
    vx = projection(b1.vel, np.array((3,-1)))
    vy = projection(b1.vel, np.array((3,-1))*-1)

class Ball():
    def __init__(self,x,y, vx,vy,r):
        self.pos = np.array((x,y))
        self.x=x
        self.y=y
        self.vel = np.array((vx,vy))
        self.vx=vx
        self.vy=vy
        self.r = r

