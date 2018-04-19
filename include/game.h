#ifndef GAME_H
#define GAME_H

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
//#include <windows.h>
#include <string>
#include <cmath>
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdio>
#include "Target.h"
#include "Player.h"
#include "Target.h"
#include "Arrow.h"
#include "Bow.h"
#define _USE_MATH_DEFINES
#include "Collision.h"

using namespace std;
using namespace sf;

class Game
{
    public:
        Game();
        ~Game();

        void runGame();

    protected:

        enum GameState{MENU,OPTIONS,GAME,GAME_OVER,END,TARGETHIT};
        GameState state;

    private:
        Font font;

        Sprite backgroundSprite;
	    Texture backgroundTexture;
	    double x;
	    bool kolizja;

	    Clock mainClock;
	    Time elapsed;

	    Vector2f mousePos;
	    Vector2f playerPos;
	    Vector2f aimDir;
	    Vector2f aimDirNorm;
	    Vector2f vector;

	    Player* gracz;
	    Bow* luk;
	    Arrow* strzala;
	    Target* obiekt;

        void menu();
        void options();
        void gameStart();
        void gameOver();
        int czas(clock_t t);
        int a=0;
        int score;
        float angle;
        int time;
        int diff;
        int lives;
};

#endif // GAME_H
