#ifndef PLAYER_H
#define PLAYER_H

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

using namespace std;
using namespace sf;


class Player
{
    public:
        Player();
        Player(float startX, float StartY);
        virtual ~Player();

        Sprite getSpirte();

        Vector2f pozycja;
        RectangleShape ksztalt;
        Sprite pSprite;
        Texture pTexture;
        Text tekst;

    protected:

    private:
};

#endif // PLAYER_H
