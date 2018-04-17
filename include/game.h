#ifndef GAME_H
#define GAME_H

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
//#include <Windows.h>
#include <string>
#include "Player.h"
#include "Bow.h"
#include "Arrow.h"

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

	    Player* gracz;
	    Bow* luk;
	    Arrow* strzala;

        void menu();
        void options();
        void gameStart();
};

#endif // GAME_H
