#include "Engine.h"

using namespace sf;

Engine::Engine()
{
    gameWindow.create(VideoMode(800, 600), "Archer The Game");

    //BackgroundTexture.loadFromFile() //Wczytanie tekstur
    //BackgroundSprite.setTexture()  //u¿ycie tekstur

   // world = new World(); //wczytanie swiata
   // player = new Player();  //wczytanie postacie
   // object = new Object(); //wczytanie przeciwnika
   // arrow = new Arrow(); //wczytanie strzal
   // score = new Score()  //wczytanie wyniku

   targetHit = false;
   timeDelay=0;
}

void Engine::start()
{
    gameWindow.clear(Color::Black);
    gameWindow.display();
}
