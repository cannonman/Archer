#ifndef ENGINE_H
#define ENGINE_H

#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace sf;

class Engine
{

    private:

        RenderWindow gameWindow;
        int wWidth;
        int wHeight;
        int timeDelay;

        Sprite BackgroundSpirte;
        Texture BackgroundTexture;

        // Scenery &scenery;
        //Player &player;
        //Object &object;
        //Bow &bow;
        //Arrow &arrow;
        //Score &score;

        bool targetHit;
        sf::Text message;

        void input();  // ??
        void update(float drAsSeconds);  // ??
        void draw();

           public:
        Engine();

        void start();

};

#endif // ENGINE_H
