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
#include "../include/Target.h"
#include "../include/Player.h"
#include "../include/Target.h"
#include "../include/Arrow.h"
#include "../include/Bow.h"


using namespace std;
using namespace sf;

class Game
{
    public:
        Game();
        ~Game();

        void runGame();

    protected:

        enum GameState{MENU,OPTIONS,GAME,GAME_OVER,END};
        GameState state;

    private:
        Font font;
        int diff;
        Sprite backgroundSprite;
	    Texture backgroundTexture;
	    double x;

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
        int czas(clock_t t);
        int a=0;
        float angle;
};

#endif // GAME_H
