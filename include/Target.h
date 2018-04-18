//
// Created by gsh on 17.04.18.
//

#ifndef ARCHER_TARGET_H
#define ARCHER_TARGET_H

#pragma once
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Target{
public:
    Target (float x, float y);
    virtual ~Target();
    Sprite getSprite();
    Texture getTexture();
    void setSpeed(float speed);
    void increaseSpeed(float speed);
private:
    Sprite aSprite;
    Texture aTexture;
    float targetSpeed;
};

#endif //ARCHER_TARGET_H