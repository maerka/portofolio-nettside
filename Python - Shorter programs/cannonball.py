import math
import random as r

def acclX():
    return 0

def acclY():
    return -10
    #return -9.81

def velX(initVelocityX, time): #returns velocityX after given time
    return initVelocityX + acclX() * time #last partwill always be 0

def velY(initVelocityY, time): #returns velocityY after given time
    return initVelocityY + acclY() * time
    
def posX(initPositionX, initVelocityX, time): #returns positionX after given time and initial velocityX
    #return initPositionX + initVelocityX*time
    return initPositionX + initVelocityX*time + acclX()*time**2 / 2
    
def posY(initPositionY, initVelocityY, time): #returns positionY after given time and initial velocityY
    return initPositionY + initVelocityY*time + acclY()*time**2 / 2

def printTime(time): #Writes time in a clean way
    sec = time
    hours = math.floor(sec/3600)
    sec -= 3600*hours
    minutes = math.floor(sec/60)
    sec -= 60*minutes
    return f'{hours} hours, {minutes} minute, {sec} seconds'
    
def flightTime(initVelocityY):
    #return the time from y= 0 to the top (ex. y=5) and back to y=0
    return -2*initVelocityY/acclY()


def flightTimeAdvanced(posYstart, posYend, initVelocityY):
    #uses abs-formula to solve equation y = y0 + vt + (a/2)t**2
    a=acclY()/2
    b=initVelocityY
    c=posYstart-posYend
    #How to test (set acclY() to 10)
        #2 solutions: flightTimeAdvanced(2, 6, 10)
        #1 solutions: flightTimeAdvanced(2, 7, 10)
        #0 solution:  flightTimeAdvanced(2, 8, 10)
    try: 
        time = abcFormula(a,b,c)
    except:
        raise ValueError('More power is needed')
    else:
        return time

def abcFormula(a,b,c):
    #With use of exceptions
        # try:
        #     x1 = (-b + math.sqrt(b**2 - 4*a*c) ) / (2*a)
        #     x2 = (-b - math.sqrt(b**2 - 4*a*c) ) / (2*a)
        # except:
        #     raise ValueError('Bad math in abcFormula(): b**2 is smaller than 4*a*c')
        # return x1,x2
        
    # Without use of exceptions
    d = b**2 - 4*a*c
    if d > 0: #to ratinal solutions
        x1 = (-b + math.sqrt(b**2 - 4*a*c) ) / (2*a)
        x2 = (-b - math.sqrt(b**2 - 4*a*c) ) / (2*a)
        #x2 is greater than x1
        return x2,x1
    elif d ==0: #1 rational solution
        x1 = (-b + math.sqrt(b**2 - 4*a*c) ) / (2*a)    
        return x1, float('NaN')
    else: #2 irrational solutions because root becomes negative
        return float('NaN'), float('NaN')
    

    
    

def getUserInput():
    degress = float(input('How many degrees?'))
    absVelocity = float(input('How much power?'))
    endPosY = float(input('At what altitude shall it explode?'))
    return degress, absVelocity, endPosY
#def getUserInput(theta, absVelocity):
    # the variables were given pointers in C++
    
def aimCannon(initPosY):
    t = 1
    while t:
        degrees = float(input('How many degrees?'))
        absVelocity = float(input('How much power?'))
        endPosY = float(input('At what altitude shall it explode?'))
        
        a=acclY()/2
        b=getVelocityY(degrees, absVelocity)
        c=initPosY-endPosY
        if b**2 -4*a*c >=0:
            t = 0
        else:
            print('You need more power or another angle to reach that far.')         
    return degrees, absVelocity, endPosY

    
def degToRad(deg):
    return (deg/360*2*math.pi)
    
def getVelocityX(theta, absVelocity): #theta in degrees. Convert to radians
    return absVelocity * math.cos(degToRad(theta)) 

def getVelocityY(theta, absVelocity): #theta in degrees. Convert to radians
    return absVelocity * math.sin(degToRad(theta))
        
#def getVelocityVector(theta, absVelocity, velocityX, velocityY):
    # the 2 last variables were given pointers in C++


def getVelocityVector(theta, absVelocity):    
    velocityX = getVelocityX(theta,absVelocity)
    velocityY = getVelocityY(theta,absVelocity)
    return velocityX, velocityY

def getDistanceTraveled(initVelocityX, initPosX, initPosY, endPosY,initVelocityY):
    #returns only distance traveled for time 1, which is the largest. Hence, there can be a hit earlier. This exception is not handled. To do so posX() must be altered to take 2 arguments and return 2 arguments. posX() can handle nan.
    time1,time2 = flightTimeAdvanced(initPosY, endPosY, initVelocityY)
        #2 solutions: (time1, time2) where time 1 is greatest
        #1 solutions: (time1, nan)
        #0 solution:  (nan, nan)

    return posX(initPosX, initVelocityX, time1)
    
def targetPractice(tarPosX, tarPosY, endPosX, endPosY):
    distanceX = endPosX - tarPosX
    distanceY = endPosY - tarPosY
    return distanceX,distanceY



def targetEvaluation(distanceX,distanceY):
    #calculate the radius from target to end position
    radius = math.sqrt(distanceX**2 + distanceY**2)
    # hit or not hit
    if radius <=0.5:
        print('A fine hit!')
        return True
    else: 
        print('You missed!')
        
        #feedback x-direction
        if distanceX > 0:
            print('You shot',abs(round(distanceX,1)),'too far.')
        else: 
            print('You shot',abs(round(distanceX,1)),'too short.')
        
        #feedback y-direction
        if distanceY > 0:
            print('You shot',abs(round(distanceY,1)),'too high.')
        else: 
            print('You shot',abs(round(distanceY,1)),'too low.')
        return False

def playGame():
    # INITIAL CONDITIONS
    #target position
    tarPosX = r.randint(5,100)
    tarPosY = r.randint(0,10)
    print(f'Target position: ({tarPosX}, {tarPosY})')
    
    #cannon position
    initPosX = 0
    initPosY = 2
    numOfCannons = 2
    print(f'Cannon position: ({initPosX}, {initPosY})')
  
    
    hit = 0
    while hit==0:
        #getting inputs
        theta,power, endPosY = aimCannon(initPosY)
        
        # CALCULATE TRAJECTORY
        #calulating velocities
        initVelocityX, initVelocityY = getVelocityVector(theta, power)
#        time = flightTimeAdvanced(initPosY, endPosY, initVelocityY)
        endPosX = getDistanceTraveled(initVelocityX, initPosX, initPosY, endPosY,initVelocityY)
        distanceX,distanceY = targetPractice(tarPosX, tarPosY, endPosX, endPosY)

        # RESULTS
        hit=targetEvaluation(distanceX, distanceY)
        numOfCannons -= 1
        if numOfCannons ==0:
            print('You are out of ammunition. You have lost.')
            hit =1
            return 0







