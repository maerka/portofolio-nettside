#include <string>
using namespace std;
#include "Person.h"
#include "Car.h"

Person::Person(string name, string email, Car *car) {
	this->name = name;
	this->email = email;
	this->car = car;
}


string Person::getName() const {
	return name;
}
string Person::getEmail() const {
	return email;
}
void Person::setEmail(string email) {
	this->email = email;
}


bool Person::hasAvailableSeats() const {
	//Sjekker først om personen har en bil
	if (car != nullptr && car->hasFreeSeats()) {
		return true;
	}
	else {
		return false;
	}
}

// **** Klasse slutt, operatorer *****
std::ostream& operator<<(std::ostream& os, const Person& p) {
	os << "Navn: " << p.getName() << endl;
	os << "E-mail: " << p.getEmail() << endl;
	return os;
}

bool operator == (const Person &p1, const Person &p2) {
	return (p1.getName() == p2.getName());
}
bool operator < (const Person &p1, const Person &p2) {
	// plukke ut første bokstav og sjekke om den er mindre
	// Videre skal jeg lage løkke og gå gjennom alle bokstavene.
	string letter1 = p1.getName().substr(0, 1);
	string letter2 = p2.getName().substr(0, 1);
	return (letter1 < letter2);
	//return (p1.getName() == p2.getName());
}

