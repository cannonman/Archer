#ifndef ARROW_H
#define ARROW_H

#pragma once
#include <SFML/Graphics.hpp>

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

        Sprite getSprite();
        void changeAngleUp();
        void changeAngleDown();
        void reset();


    protected:

    private:
        RectangleShape arrow;
};

#endif // ARROW_H
