#include <game.h>

using namespace sf;

void Game::gameStart()
{

    Texture backgroundTexture;
    Sprite backgroundSpirte;

    backgroundTexture.loadFromFile("jungle.png");
    backgroundSpirte.setTexture(backgroundTexture);

    while (state != END)
    {
        Text title ("Archer The Game",font,30);
        title.setStyle(Text::Bold);
        title.setPosition(800/2-title.getGlobalBounds().width/2,20);


        Event event;

        while (window.pollEvent(event))
        {

            if (event.type==Event::Closed || Evebt::KeyPressed && event.key.code == Keyboard::Escape)
                state = END;

        }

        window.clear();
        window.draw(title);
        window.display();

    }

}
