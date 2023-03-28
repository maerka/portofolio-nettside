#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "Meeting.h"

vector<const Meeting*>Meeting::meetings;

Meeting::Meeting(int day, int startTime, int endTime, Campus location, std::string subject, const Person* leader) {
	this->day = day;
	this->startTime = startTime;
	this->endTime = endTime;
	this->location = location;
	this->subject = subject;
	this->leader = leader;

	addParticipant(leader);
}

Meeting::~Meeting() {
	/*vector<const Meeting*> ::iterator it;*/
	for (auto it = meetings.begin(); it != meetings.end(); it++) {
		if (*it == this) {
			meetings.erase(it);
		}
	}
}
	

int Meeting::getDay() const{
	return day;
}
int Meeting::getStartTime() const{
	return startTime;
}
int Meeting::getEndTime() const{
	return endTime;
}
Campus Meeting::getLocation() const {
	return location;
}
string Meeting::getSubject() const {
	return subject;
}

Person Meeting::getLeader() const{
	return *leader;
}

//void Meeting::addParticipant(const Person *newPerson) {
//	// Dette blir lederen gjennom konstruktør
//	if (participants.size() == 0) {
//		participants.push_back(newPerson);
//		cout << "Lista var tom" << endl;
//	}
//	
//	//Sjekker først om ny person er bakerst i alfabetet. I så fall legger til ny person bakerst.
//	else if (!(newPerson < participants[participants.size()-1])) {
//		participants.push_back(newPerson);
//	}
//
//	else {
//		//Går gjennom lista og finner ut hvor ny person skal plasseres
//		for (int i = 0; i < participants.size()-1; i++) {
//			if (newPerson < participants[i])
//
//				// Gir alle elementene i vektoren et elementnummer høyere. Starter i slutten og jobber seg tilbake til start.
//				for (int j = participants.size(); j > i; i--) {
//					participants[j] = participants[j - 1];
//				}
//			//Nå er det plass for den nye personen
//			participants[i] = newPerson;
//		}
//	}
//}

void Meeting::addParticipant(const Person *person) {
	if (participants.size() == 0) {
		this->participants.push_back(person);
	}
	else if (*(this->participants[(participants.size() - 1)]) < *person) {
		(this->participants).push_back(person);
	}
	else {
		for (int i = 0; i < participants.size(); i++) {
			if (*person < *participants[i]) {
				(this->participants).insert((participants.begin() + i), person);
				break;
			}
		}
	}
}

vector<string> Meeting::getParticipantList() const {
	vector <string> listOfNames;
	for (int i = 0; i < participants.size(); i++) {
		string name = participants[i]->getName();
		//cout <<"Person "<<i+1<<": "<< name << endl;
		listOfNames.push_back(name);
	}
	return listOfNames;
}
vector<const Person*> Meeting::findPotentialCoDriving() {
	vector<const Person*> personsWithFreeSeat;
	for (int i = 0; i<participants.size(); i++) {
		const Person* person = participants[i];
		if (person->hasAvailableSeats()) {
			personsWithFreeSeat.push_back(person);
		}
	}
	return personsWithFreeSeat;
}


ostream& operator<<(ostream& os, const Campus& c) {
	os << static_cast<int>(c) << endl;
	return os;
}

std::ostream& operator<<(std::ostream& os, const Meeting& m) {
	os << "Subject:" << m.getSubject()  << endl;
	os << "Location: " << m.getLocation();
	os << "Start time:" << m.getStartTime() << endl;
	os << "End time: " << m.getEndTime() << endl;
	os << "Meeting leader: " << m.getLeader() << endl;
	vector<string>participantsAtMeeting = m.getParticipantList();
	os << "Participants at meating:" << endl;
	for (int i = 0; i< participantsAtMeeting.size(); i++)
		os << participantsAtMeeting[i] << endl;
	return os;
}