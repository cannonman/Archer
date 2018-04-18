//
// Created by gsh on 17.04.18.
//

#include "../include/Target.h"

Target::Target (float x, float y){
    aTexture.loadFromFile("arrowDef.png");
    aSprite.setTexture(aTexture);

    aSprite.setPosition(x,y);
}

Target::~Target(){
    //destruktor
}

void Target::increaseSpeed(float speed) {
    Target::targetSpeed+=speed;
}

void Target::setSpeed(float speed) {
    Target::targetSpeed = speed;
}

Sprite Target::getSprite(){
    return aSprite;
}

Texture Target::getTexture(){
    return aTexture;
}

void Target::objMove()
{

    aSprite.move(0,100);
    cout<<"ruch"<<endl;

}

Vector2f Target::objPos()
{

 return Vector2f(aSprite.getPosition().x,aSprite.getPosition().y);

}
