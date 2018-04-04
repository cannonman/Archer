#include "Menu.h"

Menu::Menu(float width, float height)
{
    if (!font.loadFromFile("arial.ttf"))
    {
    //error
    }
    menu[0].setFont(font);
    menu[0].setColor(Color::Red);
    menu[0].setString("Play");
    menu[0].setPosition(sf::Vector2f(width/2, height/(MAX_NUMBER_OF_ITEMS + 1) * 1));

    menu[1].setFont(font);
    menu[1].setColor(Color::White);
    menu[1].setString("Options");
    menu[1].setPosition(sf::Vector2f(width/2, height/(MAX_NUMBER_OF_ITEMS + 1) * 2));

    menu[2].setFont(font);
    menu[2].setColor(Color::White);
    menu[2].setString("Exit");
    menu[2].setPosition(sf::Vector2f(width/2, height/(MAX_NUMBER_OF_ITEMS + 1) * 3));

    selected=0;

}

Menu::~Menu()
{
    //dtor
}

void Menu::draw(sf::RenderWindow &window)
{

    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        window.draw(menu[i]);
    }

}

void Menu::MoveUp()
{
    if (selected - 1 >= 0)
    {
        menu[selected].setColor(Color::White);
        selected--;
        menu[selected].setColor(Color::Red);
    }
}

void Menu::MoveDown()
{
    if (selected + 1 <= 2)
    {
        menu[selected].setColor(Color::White);
        selected++;
        menu[selected].setColor(Color::Red);
    }
}
