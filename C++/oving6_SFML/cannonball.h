#pragma once

// ***** OPPGAVE 1 *****
//OPPG A)
double acclX();
double acclY();

//OPPG B)
double velX(double initVelocityX, double time);
double velY(double initVelocityY, double time);

//OPPG C)
double posX(double initPosition, double initVelocity, double time);
double posY(double initPosition, double initVelocity, double time);

//OPPG D)
void printTime(double sekunder);

//OPPG E)
double flightTime(double initVelocityY);


// ***** OPPGAVE 2 *****
//OPPG A)
/* Ber brukeren om to tall, en vinkel (i grader), og en fart.
Disse verdiene skal lagres i minnet som pekerne
theta og absVelocity peker paa.*/
void getUserInput(double *theta, double *absVelocity);

// Konverterter fra grader til radianer
double degToRad(double deg);

// Returnerer henholdsvis farten i X-, og Y-retning, gitt en vinkel
//theta og en absoluttfart absVelocity.
double getVelocityX(double theta, double absVelocity);
double getVelocityY(double theta, double absVelocity);

/*Dekomponerer farten gitt av absVelocity, i X- og Y-komponentene
gitt vinkelen theta. Disse komponentene lagres i minnet.*/
void getVelocityVector(double theta, double absVelocity, double *velocityX, double *velocityY);

//OPPG B)
double getDistanceTraveled(double velocityX, double velocityY);

//OPPG C)
double targetPractice(double distanceToTarget, double velocityX, double velocityY);


// ***** OPPGAVE 6 *****
void playTargetPractice();
