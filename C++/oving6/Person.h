#pragma once
#include <string>
#include "Car.h"

class Person {
private:
	std::string name;
	std::string email;
	Car *car;
public:
	Person(std::string name, std::string email, Car *car);
	Person(std::string name, std::string email) : Person(name, email, nullptr) {};
	string getName() const;
	string getEmail() const;
	void setEmail(string email);
	bool hasAvailableSeats() const;
};

std::ostream& operator<<(std::ostream& os, const Person& p);
bool operator ==(const Person &p1, const Person &p2);
bool operator <(const Person &p1, const Person &p2);