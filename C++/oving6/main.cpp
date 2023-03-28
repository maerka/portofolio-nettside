#include <iostream>
#include <vector>
using namespace std;
#include"Car.h"
#include "Person.h"
#include "Meeting.h"

void main() {
	// ***** TEST CAR *****
	cout << "***** Test av Car *****" << endl;
	Car test(100);
	cout << test.hasFreeSeats() << endl;
	test.reserveFreeSeat();
	cout << test.hasFreeSeats() << endl;


	// ***** TEST PERSON, mange boolske *****
	cout << "\n***** Test av Person *****" << endl;
	string navn = "Truls";
	string mail = "trulsern@hotmail.com";
	Car bil1 = Car(4);
	Person person1(navn,mail,  &bil1);
	cout << person1.getEmail() << endl;

	navn = "Marte";
	mail = "marte@hotmail.com";
	Car bil2 = Car(4);
	Person person2(navn, mail, &bil2);
	navn = "Ronny";
	mail = "ronny@hotmail.com";
	Car bil3 = Car(0);
	Person person3(navn, mail, &bil3);
	navn = "Johanne";
	mail = "johanne@hotmail.com";
	Person person4(navn, mail);
	

	// Utskiftsoperator
	cout << person1 << endl;
	cout << person2 << endl;
	cout << person3 << endl;
	cout << person4 << endl;
	

	//Operatorer
	cout << "person1 == person1: "<<(person1 == person1) << endl;
	cout << "person1 == person1: " << (person1 == person2) << endl;
	cout << "Marte < Ronny: " << (person2 < person3) << endl;
	cout << "Ronny < Marte: " << (person3 < person2) << endl;

	// hasFreeSeats
	cout << "ledige seter, person 2: " << person2.hasAvailableSeats() << endl;
	cout << "ledige seter, person 3: " << person3.hasAvailableSeats() << endl;
	cout << "ledige seter, person 4: " << person4.hasAvailableSeats() << endl;


	// ***** TEST MEETINGS *****
	navn = "Yngve";
	mail = "johanne@hotmail.com";
	Person person5(navn, mail);

	navn = "Ane";
	mail = "johanne@hotmail.com";
	Person person6(navn, mail);

	cout << "\n***** Test av Person *****" << endl;
	Meeting meating= Meeting(5, 12, 14,  GJO, "snoemangel",  &person1); //Erlend

	meating.addParticipant(&person4); //Johanne
	meating.addParticipant(&person3); // Marte
	meating.addParticipant(&person5); // Yngve
	meating.addParticipant(&person2); // Ronny
	meating.addParticipant(&person6); // Ane

	meating.getParticipantList();
	

	cout << meating.getDay() << endl;
	cout << "\nTEST AV UTSKRIFT AV MEETING" << endl;
	cout << meating << endl;
	
	
	




	
}

