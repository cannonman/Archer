#include "Player.h"

Player::Player(float startX, float startY)
{
    pTexture.loadFromFile("pirate.png");
    pSprite.setTexture(pTexture);

    pSprite.setPosition(startX,startY);

    pozycja = Vector2f (pSprite.getPosition().x, pSprite.getPosition().y);
}

Player::~Player()
{
    //dtor
}

Sprite Player::getSpirte()
{
    return pSprite;
}
