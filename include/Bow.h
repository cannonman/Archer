#ifndef BOW_H
#define BOW_H

#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Bow
{
    public:
        Bow(float wX,float wY);
        float bowAngle;
        Sprite bSprite;
        Texture bTexture;

        void changeAngleUp();
        void changeAngleDown();
        float getAngle();
        void setAngle(float angle);

        void reset();
        Sprite getSprite();

        virtual ~Bow();

    protected:
        float angle;
    private:

};

#endif // BOW_H
