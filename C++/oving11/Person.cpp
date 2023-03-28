//#include<forward_list>
#include"Person.h"

Person::Person(std::string fName, std::string lName) {
	this->fName = fName;
	this->lName = lName;
}

Person::~Person() {
	fName = "";
	lName = "";
}

//void Person::insertOrdered(std::forward_list<Person> & l, const Person& p) {
//	std::forward_list<Person>::iterator temp = l.before_begin();
//	std::cout << "TEST 1" << std::endl;
//
//	for (std::forward_list<Person>::iterator it = l.begin(); it != l.end(); ++it) {
//		std::cout << "TEST 2" << std::endl;
//		if (p < *it) {
//			break;
//			std::cout << "TEST 3" << std::endl;
//		}
//		temp++;
//	}
//	l.insert_after(temp, p);
//}


bool operator <(const Person& lhs, const Person& rhs) {
	if (lhs.lName == rhs.lName) {
		return(lhs.fName < rhs.fName);
	}
	else {
		return (lhs.lName < lhs.lName);
	}
}