//#include "Arrow.h"
#include "../include/Arrow.h"
#define BEGIN_X 84
#define BEGIN_Y 340


Arrow::Arrow(float x, float y) : currVelo(0.f,0.f), maxSpeed(10.f)
{

    aTexture.loadFromFile("arrowDef.png");
    aSprite.setPosition(getBeginX(), getBeginY());
    aSprite.setTexture(aTexture);
    Arrow::released=false;

}

Arrow::~Arrow()
{
    //dtor
}

void Arrow::release()
{
    released = true;
}

Sprite Arrow::getSprite()
{
    return aSprite;
}

void Arrow::changeAngleUp()
{
    aSprite.rotate(-2.5);
}

void Arrow::changeAngleDown()
{
    aSprite.rotate(2.5);
}

void Arrow::setAngle(float angle)
{
    aSprite.setRotation(angle);
}
void Arrow::resetPosition()
{
    aSprite.setPosition(getBeginX(), getBeginY());
    Arrow::released=false;
}

bool Arrow::ifReleased()
{
    return Arrow::released;
}

int Arrow::getBeginX()
{
    return BEGIN_X;
}

int Arrow::getBeginY()
{
    return BEGIN_Y;
}
