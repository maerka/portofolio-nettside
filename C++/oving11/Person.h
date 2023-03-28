#pragma once
#include<string>
#include<iostream>
#include<forward_list>

class Person {
private:
	std::string fName;
	std::string lName;

public:
	Person(std::string fName, std::string lName);
	~Person();
	//void insertOrdered(std::forward_list<Person> & l, const Person& p);

	friend std::ostream& operator<<(std::ostream& os, const Person& person) {
		os << person.fName << "\t" << person.lName << std::endl;
		return os;
	}
	friend bool operator <(const Person& lhs, const Person& rhs);
};

