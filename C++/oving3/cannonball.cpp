#include "cannonball.h"
#include "utilities.h"

#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

double acclY(){
    return -9.81;
}
double velY(double initVelocityY, double time){
    return initVelocityY + acclY() * time;
}

double posX(double initPosition, double initVelocity, double time){
    double position = initPosition + initVelocity*time;
    return position;
    // alternativt: return initPosition + initVelocity*time;
}
double posY(double initPosition, double initVelocity, double time){
    double position = initPosition + initVelocity*time + 0.5 *pow(time,2.0) * acclY();
    return position;
    // alternativt: return initPosition + initVelocity*time + 0.5 *pow(time,2.0) * acclY();
}

void printTime(double time){
    int hours = static_cast<int>(time)/3600;
    int minutes = (static_cast<int>(time) - 3600*hours)/60;
    double seconds = time - hours*3600 - minutes * 60;
    cout << hours << " hours, " << minutes << " minutes and " << seconds << " seconds" << endl;
}

double flightTime(double initVelocityY){
    return -initVelocityY/acclY()*2.0;
}

void getUserInput(double* theta, double* absVelocity){
    cout << "Please enter a angle for the cannon angle: ";

    cin >> (*theta);
    while(*theta < 0.1){
    cout << "The angle you chose was too small, please select a larger one." << endl;
    cin >> (*theta);
    }

    cout << "Please enter a velocity for the cannon projectile: ";
    cin >> (*absVelocity);
    while(*absVelocity < 0.1){
    cout << "The velocity you chose is to small, try again." << endl;
    cin >> (*absVelocity);
    }

}

double degToRad(double deg) {
    return deg/180*3.14159265;
}

double getVelocityX(double theta, double absVelocity){
    return cos(degToRad(theta))*absVelocity;
}
double getVelocityY(double theta, double absVelocity){
    return sin(degToRad(theta))*absVelocity;
}

void getVelocityVector(double theta, double absVelocity, double *velocityX, double *velocityY){
    *velocityX = getVelocityX(theta, absVelocity);
    *velocityY = getVelocityY(theta, absVelocity);
}

double getDistanceTraveled(double velocityX, double velocityY){
    double fTime = flightTime(velocityY);
    double distanceTraveled = posX(0,velocityX,fTime);
    return distanceTraveled;
    // alternativt: return posX(0, velocityY, flightTime(velocityY))
}

double targetPractice(double distanceToTarget, double velocityX, double velocityY){
    double error = distanceToTarget - getDistanceTraveled (velocityX, velocityY);
    return abs(error);
}

void playTargetPractice(){
    cout << "*******Playing target practice!******" << endl;
    cout << "The goal of this game is to hit the target, you will be presented " << endl
         << "with a target at some random distance (between 100 and 1000m) " << endl
         << "from you. In order to hit a target you must specify an angle and " << endl
         << "a initial velocity for the cannonball." << endl << endl;
    double distanceToTarget = randomWithLimits(100, 1000);
    double maxError = 5.0;
    bool win = false;

    cout << "Target is placed at " << distanceToTarget <<  "m range" << endl;
    cout << "Happy hunting!" << endl << endl;
    cout.precision(2);
    cout.setf(ios::fixed);
    for (int chance = 0; chance < 10; chance++){

        cout << "Round " << chance+1 << ":" << endl << endl;
        double angle, absVelocity, velocityX, velocityY;
        getUserInput(&angle, &absVelocity);
        getVelocityVector(angle, absVelocity, &velocityX, &velocityY);

        double error = targetPractice(distanceToTarget, velocityX, velocityY);
        double distanceTraveled = getDistanceTraveled(velocityX,velocityY);

        cout << endl;
        cout << "Your shot went: " << distanceTraveled << "m" << endl;
        cout << "Distance from target: " << error << "m" <<  endl;

        if (error < maxError){
            win = true;
            break;
        }

        if (distanceTraveled > distanceToTarget){
            cout << "You overshot the target! A little less force next time maybe?" << endl << endl;
        }
        else{
            cout << "You didnt reach the target. Some more force next time?" << endl << endl;
        }
    }
    if (win){
        cout << "Congratulations you won!" << endl;
    }
    else{
        cout << "Sorry, you lost." << endl;
    }
}

