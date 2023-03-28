#include <iostream>
#include "cannonball.h"
#include "utilities.h"
#include <cmath>
#include <ctime>
using namespace std;

// ***** OPPGAVE 2 *****
//OPPG A)
double acclX() {
	return 0;
}
double acclY() {
	return -9.81;
}

//OPPG B)
double velX(double initVelocityX, double time) {
	return initVelocityX + acclX()*time;
}
double velY(double initVelocityY, double time) {
	return initVelocityY + acclY()*time;
}

//OPPG C)
double posX(double initPosition, double initVelocity, double time) {
	return initPosition + initVelocity*time + (acclX()*pow(time,2)) / 2;
}
double posY(double initPosition, double initVelocity, double time) {
	return initPosition + initVelocity*time + (acclY()*pow(time,2)) / 2;
}

//OPPG D)
//Rett bruk av int og double og %?
void printTime(double sekunder) {
	int timer = sekunder / 3600;
	double restTimer = sekunder - 3600 * timer; //std::fmod(sekunder, 3600);
	int minutter = restTimer / 60;
	double restMinutter = restTimer - 60*minutter; //std::fmod(restTimer, 60);

	std::cout << "Tid: " << timer << "time(r), "<< minutter << "minutt(er), "<< restMinutter<< "sekund" << std::endl;
}

//OPPG E)
double flightTime(double initVelocityY) {
	return (-2 * initVelocityY) / acclY();
}


// ***** OPPGAVE 4 *****
//OPPG A)
void getUserInput(double *theta, double *absVelocity) {
	cout << "Skriv inn antall grader:" << endl;
	cin >> *theta;

	cout << "Skriv inn fart:" << endl;
	cin >> *absVelocity;
}

double degToRad(double deg) {
	return deg * 2 * 3.14159265359 / 360;
}

double getVelocityX(double theta, double absVelocity) {
	double rad = degToRad(theta);
	return absVelocity * cos(rad);
}
double getVelocityY(double theta, double absVelocity) {
	double rad = degToRad(theta);
	return absVelocity * sin(rad);
}

void getVelocityVector(double theta, double absVelocity, double *velocityX, double *velocityY) {
	*velocityX = getVelocityX(theta, absVelocity);
	*velocityY = getVelocityY(theta, absVelocity);
}


//oppg B)
double getDistanceTraveled(double velocityX, double velocityY){
	double time = flightTime(velocityY);
	return posX(0, velocityX, time);
}

//returnerer positivt svar hvis for kort. Negativt svar hvis for langt
double targetPractice(double distanceToTarget, double velocityX, double velocityY) {
	double distance = getDistanceTraveled(velocityX, velocityY); //Hvor langt kula blir skutt
	return distanceToTarget - distance;
	
	/* ALTERNATIV MED ABSOLUTTVERDI
	if (distance < distanceToTarget) {
		return distanceToTarget - distance;
	}
	else if (distance > distanceToTarget) {
		return distance - distanceToTarget;
	}
	else {
		return 0; 
	}   */
}


// ***** OPPGAVE 6 *****
void playTargetPractice() {

	cout << "SJOROVERNE KOMMER! ALLE MANN TIL KANONENE!!" << endl;

	srand(time(nullptr));
	int DistanceToTarget = randomWithLimits(100, 1000);
	cout << "Distance To Target: "<< DistanceToTarget << endl;

	

	for (int i = 0; i < 5; i++) {

		double theta;
		double absVelocity;
		double velocityX;
		double velocityY;

		getUserInput(&theta, &absVelocity); //Lagrer inputdata i theta og absVelocity
		getVelocityVector(theta, absVelocity, &velocityX, &velocityY); //Lagrer inputdata som hastighet i x- og y-retning
		double shooting = targetPractice(DistanceToTarget, velocityX, velocityY);
		cout << "Kula gikk " << getDistanceTraveled(velocityX,velocityY) << " meter." << endl;
		
		if (shooting < 5 && shooting > -5) {
			cout << "\nGRATULERER! DU SENKET SJOROVERSKUTA!" << endl;
			break;
		}
		else if (shooting > 0){
			cout << "Huffda! Her trengs det mer krutt eller annen vinkel.\n" << endl;
		}
		else {
			cout << "Oi! Naa gikk kula for langt.\n" << endl;
		}
		//Kan denne settes lik antall iterasjoner
		if (i == 4) {
			cout << "\nNEI!! Du har brukt " << i+1 << " forsok! Sjoroverne traff oss. Alle mann i livbaatene!!!" << endl;
		}
	
	}
	


	//double distanceTraveled = getDistanceTraveled(velocityX, velocityY); //Angir hvor langt kula skytes
}
