#ifndef ARROW_H
#define ARROW_H

#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>

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

        Vector2f currVelo;
        float maxSpeed;

        Sprite getSprite();
        void changeAngleUp();
        void changeAngleDown();
        void reset();
        bool ifReleased();


    protected:

    private:
        RectangleShape arrow;
        bool released;
};

#endif // ARROW_H
