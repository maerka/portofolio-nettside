import cannonball as cb
#import random as r

cb.playGame()


# # INITIAL CONDITIONS
# #target position
# #tarPosX = 10
# tarPosX = r.randint(5,100)
# #tarPosY = 10
# tarPosY = r.randint(0,10)

# #cannon position
# initPosX = 0
# initPosY = 2
# endPosY = 10

# #cannon shooting
# theta = 30
# power = 10
# numOfCannons = 2


#Target positioned at (10,10) is hit by degrees 70 and power 15 and altitude of 10 when initPos (0,2)

# # GAME MODE
# print(f'Target position: ({tarPosX}, {tarPosY})')
# hit = 0
# while hit==0:
#     #getting inputs
#     theta,power, endPosY = cb.getUserInput2(initPosY)
    
#     # CALCULATE TRAJECTORY
#     #calulating velocities
#     initVelocityX, initVelocityY = cb.getVelocityVector(theta, power)
#     time = cb.flightTimeAdvanced(initPosY, endPosY, initVelocityY)
#     endPosX = cb.getDistanceTraveled(initVelocityX, initPosX, initPosY, endPosY,initVelocityY)
#     distanceX,distanceY = cb.targetPractice(tarPosX, tarPosY, endPosX, endPosY)

#     # RESULTS
#     hit=cb.targetEvaluation(distanceX, distanceY)
#     numOfCannons -= 1
#     if numOfCannons ==0:
#         print('You are out of ammunition. You have lost.')
#         hit =1
    
    
    #print(f'Angle: {theta} degrees \nPower: {power}')  
    #print(f'End position: ({round(endPosX)}, {endPosY})')
    #print(f'Target position: ({tarPosX}, {tarPosY})')
    #print(f'Distance x: {round(distanceX)}')
    #print(f'Distance y: {distanceY}')
    
    

def testing(time):
    #oving 3 task 3b
    print('acclX: ',cb.acclX())
    print('acclY: ',cb.acclY())
    print('velX: ',cb.velX(50,time))
    print('velY: ',cb.velY(25,time))
    print('posX:', cb.posX(0, 50, time))
    print('posY:', cb.posY(0, 25, time))
    
#testing(5)