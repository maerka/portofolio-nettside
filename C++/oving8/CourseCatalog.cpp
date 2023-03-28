#include<string>
#include<map>
#include<utility>
using namespace std;
#include"CourseCatalog.h"

CourseCatalog::CourseCatalog(map<string, string> catalog) {
	this->catalog = catalog;
}

CourseCatalog::CourseCatalog(map<string, int> catalogWithInt) {
	this->catalogWithInt = catalogWithInt;
}

void CourseCatalog::addCourse(string courseCode,string courseName) {
	//catalog[courseCode] = courseName; //Denne koden oppdaterer med nytt navn dersom koden finnes fra før
	catalog.insert(make_pair(courseCode, courseName)); // Denne koden oppdaterer IKKE dersom koden finnes fra før
}

void CourseCatalog::removeCourse(string courseCode) {
	catalog.erase(courseCode);
}

string CourseCatalog::getCourse(string code) {
	return catalog[code];
}

bool CourseCatalog::searchForElement(string element) {
	if (catalogWithInt.find(element) == catalogWithInt.end()) {
		return false;
	}
	else { return true; }
	//for (auto it = catalogWithInt.begin(); it != catalogWithInt.end(); it++) {
	//	if (element == *it) {
	//		return true;
	//	}
	//	else {
	//		return false;
	//	}
	//}
}

ostream& operator<<(ostream& os, const CourseCatalog& cc) {
	string courseName;
	string courseCode;
	for (auto it = cc.catalog.begin(); it != cc.catalog.end(); it++) {
		os << it->first << ": " << it->second << endl;
	}
	return os;
}