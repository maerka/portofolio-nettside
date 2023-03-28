#include "GameObjects.h"

#include "cannonball.h"
#include <cmath>

// implement all (member) functions in this file

bool hitTarget(const Cannonball& c, const Target& t) {
    return c.shape.getGlobalBounds().intersects(t.shape.getGlobalBounds());
}

// ***** TARGET *****

Target::Target(double size, double position) {
	this->size = size;
	this->position = position;
	shape = sf::RectangleShape(sf::Vector2f(size, size));
	shape.setPosition(sf::Vector2f(position, 0));
	shape.setFillColor(sf::Color::Cyan);
}

void Target::update() {
}

void Target::draw(sf::RenderWindow& window) {
	window.draw(shape);
}


// ***** CANNONBALL *****

Cannonball::Cannonball(double angle, double initial_velocity, double startPosX, double startPosY) {
	startVelX = getVelocityX(angle, initial_velocity);
	startVelY = getVelocityY(angle, initial_velocity);
	this->startPosX = startPosX;
	this->startPosY = startPosY;
	double size = 7;
	shape = sf::CircleShape(size);
	shape.setOrigin(size, size);
	shape.setFillColor(sf::Color::Magenta);
}

double Cannonball::getAirTime() const {
	return SPEED_FACTOR*clock.getElapsedTime().asSeconds();
}

double Cannonball::getPosX() const {
	return posX(startPosX, startVelX, getAirTime());
}
double Cannonball::getPosY() const {
	return posY(startPosY, startVelY, getAirTime());
}

bool Cannonball::hasLanded() const {
    return getPosY() + size < 0;
}

void Cannonball::update() {
	shape.setPosition(getPosX(), getPosY());
}
void Cannonball::draw(sf::RenderWindow& window) {
	window.draw(shape);
}



// ***** CANNON *****

Cannon::Cannon() {
	shape = sf::RectangleShape(sf::Vector2f(length, width));
	shape.setOrigin(width / 2, 0);
	shape.setPosition(0, 0);
	shape.setFillColor(sf::Color::Green);
}



double Cannon::getTipX() const {
    return length*cos(degToRad(theta));
}

double Cannon::getTipY() const {
    return length*sin(degToRad(theta));
}

void Cannon::incrementAngle(double dtheta) {
	theta += dtheta;
}
void Cannon::decrementAngle(double dtheta) {
	theta -= dtheta;
}
void Cannon::incrementVelocity(double dvel) {
	velocity += dvel;
}
void Cannon::decrementVelocity(double dvel) {
	velocity -= dvel;
}

Cannonball Cannon::shoot() {
	return Cannonball(theta, velocity, getTipX(), getTipY());
}

void Cannon::update() {
	shape.setRotation(theta); // Burde vært bare theta eller -90 ?
}

void Cannon::draw(sf::RenderWindow& window) {
	window.draw(shape);
}