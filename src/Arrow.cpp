#include "../include/Arrow.h"

Arrow::Arrow(float x, float y)
{

    aTexture.loadFromFile("arrowDef.png");
    aSprite.setTexture(aTexture);

    aSprite.setPosition(x,y);



}

Arrow::~Arrow()
{
    //dtor
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

void Arrow::reset()
{
    aSprite.setRotation(0);
}
