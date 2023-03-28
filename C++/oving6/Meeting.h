#pragma once
#include <iostream>
#include<vector>
#include"Person.h"

enum Campus { TRH, GJO, AAL };

class Meeting {
private:
	int day;
	int startTime;
	int endTime;
	Campus location;
	std::string subject;
	const Person* leader;
	vector<const Person*> participants;
	static vector<const Meeting*> meetings;
public:
	Meeting(int day, int startTime, int endTime, Campus location, std::string subject, const Person* leader);
	~Meeting();
	
	int getDay() const;
	int getStartTime() const;
	int getEndTime() const;
	Campus getLocation() const;
	string getSubject() const;
	Person getLeader() const;
	void addParticipant(const Person *person);
	vector<string> getParticipantList()const;
	vector<const Person*> findPotentialCoDriving();


};

std::ostream& operator<<(std::ostream& os, const Campus& c);
std::ostream& operator<<(std::ostream& os, const Meeting& m);