#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "cannonball.h"

using namespace std;
int main(){
	srand(time(nullptr));

    double result, solution, deviation, maxError = 0.00001;
    double a, b;

    result = acclY();
    solution = -9.81;
    deviation = pow(result-solution,2.0);
    if (deviation > maxError){
        cout << "AcclY() is malfunctioning (returned: "
            << result << " expected: " << solution << ")" <<  endl;
    }


    result = velY(0.0,1.0);
    solution = -9.81;
    deviation = pow(result-solution,2.0);
    if (deviation > maxError){
        cout << "VelY() is malfunctioning (returned: "
            << result << " expected: " << solution << ")" <<  endl;
    }

    result = posX(0, 10.0,3.0);
    solution = 30;
    deviation = pow(result-solution,2.0);
    if (deviation > maxError){
        cout << "PosX() is malfunctioning (returned: "
            << result << " expected: " << solution << ")" <<  endl;
    }


    result = posY(0, 0.0,1.0);
    solution = -4.905;
    deviation = pow(result-solution,2.0);
    if (deviation > maxError){
        cout << "PosY() is malfunctioning (returned: "
            << result << " expected: " << solution << ")" <<  endl;
    }

    result = flightTime(30.0);
    solution = 6.116;
    deviation = pow(result-solution,2.0);
    if (deviation > maxError){
        cout << "FlightTime() is malfunctioning (returned: "
            << result << " expected: " << solution << ")" <<  endl;
    }


    result = getVelocityX(0.0,1.0);
    solution = 1.0;
    deviation = pow(result-solution,2.0);
    if (deviation > maxError){
        cout << "getVelocityX() is malfunctioning (returned: "
            << result << " expected: " << solution << ")" <<  endl;
    }


    result = getVelocityY(0.0,1.0);
    solution = 0.0;
    deviation = pow(result-solution,2.0);
    if (deviation > maxError){
        cout << "getVelocityY() is malfunctioning (returned: "
            << result << " expected: " << solution << ")" <<  endl;
    }


    getVelocityVector(0.0,1.0, &a,&b);
    deviation = pow(a-1.0,2.0)+pow(b-0.0,2.0);
    if (deviation > maxError){
        cout << "getVelocityVector() is malfunctioning (returned: (" << a << "," << b << ") expected: (1.0 , 0.0)" <<  endl;
    }

    printTime(3665.5);
    printTime(3565.5);
    printTime(7065.5);

    getUserInput(&a,&b);
    cout << "User wrote: " << a << " , " << b << endl;

    playTargetPractice();
    return 0;
}
