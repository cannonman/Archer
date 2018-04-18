#ifndef ARROW_H
#define ARROW_H

#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>
#define BEGIN_X

using namespace sf;
using namespace std;

class Arrow
{
    public:
        Arrow (float x, float y);
        Arrow()=delete;
        virtual ~Arrow();
        Sprite aSprite;
        Texture aTexture;
        float beginX, beginY;

        Vector2f currVelo;
        float maxSpeed;

        void release();

        Sprite getSprite();
        void changeAngleUp();
        void setAngle(float angle);
        void changeAngleDown();
        void resetPosition();
        bool ifReleased();
        int getBeginX();
        int getBeginY();


protected:


    private:
        RectangleShape arrow;
        bool released;

};

#endif // ARROW_H
