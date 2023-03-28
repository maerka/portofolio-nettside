#include<iostream>
using namespace std;
#include"Car.h"

Car::Car(int freeSeats) {
	this ->freeSeats = freeSeats;
}

bool Car::hasFreeSeats() const {
	//cout << "Ledige plasser: " << freeSeats << endl;
	if (freeSeats > 0)  return true ;
	else return false;
}
void Car::reserveFreeSeat() {
	freeSeats--;
}

