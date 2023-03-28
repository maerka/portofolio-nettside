#pragma once
#include<iostream>

class Car {
private:
	int freeSeats;
public:
	Car(int freeSeats);
	bool hasFreeSeats() const;
	void reserveFreeSeat();
};