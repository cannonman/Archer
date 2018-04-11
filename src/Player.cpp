#include "Player.h"

Player::Player(float startX, float startY)
{
    pTexture.loadFromFile("pirate.png");
    pSprite.setTexture(pTexture);

    pSprite.setPosition(startX,startY);
}

Player::~Player()
{
    //dtor
}

Sprite Player::getSpirte()
{
    return pSprite;
}
