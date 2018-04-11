#ifndef Gameplay_h
#define Gameplay_h

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <Windows.h>
#include <Player.h>
#include <string>

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

        void menu();
        void options();
        void gameStart();
};

#endif // GAME_H
