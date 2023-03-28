#pragma once
#include <string>
#include <map>

class CourseCatalog {
		std::map<std::string, std::string> catalog;
		std::map<std::string, int> catalogWithInt; //map til oppg4
	public:
		CourseCatalog(map<std::string,std::string> newCatalog);
		CourseCatalog(map<std::string, int> newCatalog); //til oppg4
		void addCourse(std::string courseCode, std::string courseName);
		void removeCourse(std::string courseCode);
		bool searchForElement(std::string element); //Oppg4
		std::string getCourse(std::string code);
		friend std::ostream& operator<<(std::ostream& os, const CourseCatalog& cc);
};