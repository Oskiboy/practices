#include "GameObjects.h"

#include "cannonball.hpp"
#include <cmath>
#include <iostream>

// implement all (member) functions in this file

bool hitTarget(const Cannonball& c, const Target& t) {
    return c.shape.getGlobalBounds().intersects(t.shape.getGlobalBounds());
}


/* 
    Memberfunctions of cannonball
*/

bool Cannonball::hasLanded() const {
    return getPosY() + size < 0;
}

double Cannonball::getAirTime() const {
    return SPEED_FACTOR*clock.getElapsedTime().asSeconds();
}

//The shape initializer may cause errors.
Cannonball::Cannonball(double angle, double initial_velocity, double startPosX_i, double startPosY_i):
startPosX(startPosX_i), startPosY(startPosY_i), shape(this->size), clock()
{   
    double initVelX = 0, initVelY = 0;
    getVelocityVector(angle, initial_velocity, &initVelX, &initVelY);

    this->startVelX = initVelX;
    this->startVelY = initVelY;

    this->shape.setOrigin(this->size, this->size);
    this->shape.setFillColor(sf::Color(169,169,169));

}

double
Cannonball::getPosX() const
{
    return posX(this->startPosX, this->startVelX, getAirTime());
}

double
Cannonball::getPosY() const
{
    return posY(this->startPosY, this->startVelY, getAirTime());
}

void
Cannonball::update()
{
    this->shape.setPosition(this->getPosX(), this->getPosY());
}

void
Cannonball::draw(sf::RenderWindow& window)
{
    window.draw(this->shape);
}

/*
    Memberfuncitons of target.
*/

Target::Target(double size, double position):
size(size), position(position)
{
    this->shape = sf::RectangleShape(sf::Vector2f(this->size, this->size));
    this->shape.setFillColor(sf::Color::Red);
    this->shape.setPosition(this->position, 0);
}

void
Target::update()
{

}

void
Target::draw(sf::RenderWindow& window)
{
    window.draw(this->shape);
}


/*
    Memberfunctions of cannon.
*/
Cannon::Cannon()
{
    this->shape = sf::RectangleShape(sf::Vector2f(this->length, this->width));
    this->shape.setOrigin(this->width/2, 0);
    this->shape.setPosition(0,0);
}

void
Cannon::update()
{
    this->shape.setRotation(this->theta);
}

void
Cannon::draw(sf::RenderWindow& window)
{
    window.draw(this->shape);
}

void
Cannon::decrementAngle(double dtheta)
{
    this->theta-=dtheta;
}

void
Cannon::incrementAngle(double dtheta)
{
    this->theta+=dtheta;
}

void
Cannon::incrementVelocity(double dvel)
{
    this->velocity+=dvel;
}

void
Cannon::decrementVelocity(double dvel)
{
    this->velocity-=dvel;
}

double Cannon::getTipX() const {
    return length*cos(degToRad(theta)) - 10;
}

double Cannon::getTipY() const {
    return length*sin(degToRad(theta)) + this->width/2;
}

Cannonball
Cannon::shoot()
{
    Cannonball ball = Cannonball(this->theta, this->velocity, this->getTipX(), this->getTipY());
    return ball;
}

void
Cannon::printTheta(void) const
{
    std::cout << "Theta: " << this->theta << std::endl;
}

void
Cannon::printVelocity(void) const
{
    std::cout << "Vel: " << this->velocity << std::endl;
}


