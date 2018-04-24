//#include "Bow.h"
#include "../include/Bow.h"

Bow::Bow(float wX, float wY)
{
    bTexture.loadFromFile("bowNormal.png");
    bSprite.setTexture(bTexture);

    bSprite.setPosition(wX,wY);
    bSprite.setRotation(0);
    angle = 0;

}

Bow::~Bow()
{
    //dtor
}

Sprite Bow::getSprite()
{
    return bSprite;
}

void Bow::changeAngleUp()
{
    bSprite.rotate(-2.5);
    angle-=2.5;
}

void Bow::changeAngleDown()
{
    bSprite.rotate(2.5);
    angle+=2.5;
}

void Bow::setAngle(float angle)
{
    bSprite.setRotation(angle);
}

void Bow::reset()
{
    bSprite.setRotation(0);
}

float Bow::getAngle()
{
    return angle;
}
