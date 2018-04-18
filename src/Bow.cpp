#include "../include/Bow.h"

Bow::Bow(float wX, float wY)
{
    bTexture.loadFromFile("bowNormal.png");
    bSprite.setTexture(bTexture);

    bSprite.setPosition(wX,wY);

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
}

void Bow::changeAngleDown()
{
    bSprite.rotate(2.5);
}

void Bow::reset()
{
    bSprite.setRotation(0);
}
