#include "Gameplay.h"

RenderWindow window;


Gameplay::Gameplay(RenderWindow *window)
{



    if (!wBackgroundTexture.loadFromFile("jungle.png")){//
        };
    wBackgroundSprite.setTexture(wBackgroundTexture);

}

void Gameplay::startGame()
{

    while (window.isOpen())
    {

        Event event;

        while (window.pollEvent(event))
        {
            if (event.type==Event::Closed || Event::KeyPressed && event.key.code == Keyboard::Escape)
                state = END;
        }



    }


}




Gameplay::~Gameplay()
{

}
