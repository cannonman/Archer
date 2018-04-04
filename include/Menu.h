#ifndef MENU_H
#define MENU_H

#pragma once
#include <SFML/Graphics.hpp>

#define MAX_NUMBER_OF_ITEMS 3

using namespace sf;

class Menu
{
    public:
        Menu(float widht, float height);


        ~Menu();

        void draw(RenderWindow &window);
        void MoveUp();
        void MoveDown();

        int getPressedItem() {return selected;}

    private:
        int selected;
        Font font;
        Text menu[MAX_NUMBER_OF_ITEMS];





};

#endif // MENU_H
