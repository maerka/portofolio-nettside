#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Cannonball;
class Cannon;
class Target;

// in order to speed up the simulation
// we use a factor to speed it up
// changes this to make the simulation
// go faster or slower
const double SPEED_FACTOR = 3;

// returns true if the cannonball has hit the target
bool hitTarget(const Cannonball& c, const Target& t);



class Target {
    double size;     // size of the target (a square)
    double position; // position along the x-axis
    sf::RectangleShape shape;
public:
    Target(double size, double position);
    void update();
    // draw the shape to window
    void draw(sf::RenderWindow& window);
    friend bool hitTarget(const Cannonball& c, const Target& t);
};



class Cannon {
    double velocity = 50;   // velocity of cannonballs
    double theta = 20;      // angle (degrees)
    double length = 70;     // length of cannon
    double width = 3;      // cannon width
    sf::RectangleShape shape;
public:
    Cannon();
    double getTipX() const;     // X-coordinate of the tip of the cannon
    double getTipY() const;     // Y-coordinate of the tip of the cannon
    void incrementAngle(double dtheta = 1);      // increment the angle of the cannon by dtheta
    void decrementAngle(double dtheta = 1);      // decrement the angle of the cannon by dtheta
    void incrementVelocity(double dvel = 5);   // increment firing velocity by dvelocity
    void decrementVelocity(double dvel = 5);   // decrement firing velocity by dvelocity

    // shoot a cannonball, and return the cannonball
    Cannonball shoot();
    // update the shape
	void update();
    // draw the shape to window
    void draw(sf::RenderWindow& window);
};



class Cannonball {
    double size = 10; // radius of cannonball
    // start velocities
    double startVelX, startVelY;
    // start position
    double startPosX, startPosY;
    sf::CircleShape shape;
    // a clock, keeping track of time since launch
    sf::Clock clock;
public:
    Cannonball(double angle, double initial_velocity, double startPosX, double startPosY);
    // get time in the air in seconds, as defined by clock
    double getAirTime() const;
    // get position at current time
    double getPosX() const;
    double getPosY() const;
    // returns true if the cannonball has landed
    bool hasLanded() const;
    // update the shape
    void update();
    // draw the shape to window
    void draw(sf::RenderWindow& window);
    friend bool hitTarget(const Cannonball& c, const Target& t);
};

