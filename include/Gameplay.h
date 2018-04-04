#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <game.h>

using namespace sf;



class Gameplay
{
    public:
        Gameplay (RenderWindow* window);
        ~Gameplay();

        Sprite wBackgroundSprite;
        Texture wBackgroundTexture;

        void startGame();

        RenderWindow *window;



    protected:

    private:
};

#endif // GAMEPLAY_H
