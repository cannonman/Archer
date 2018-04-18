#include "../include/game.h"
#include <iostream>

using namespace std;

RenderWindow window(VideoMode(800,600),"Archer The Game");


Game::Game()
{
    window.setFramerateLimit(60);

    state= END;

    gracz = new Player (-50,200);

    luk = new Bow (84,340);

    strzala = new Arrow (84,340);

    obiekt = new Target (600,1);

    if(!font.loadFromFile("arial.ttf"))
    {

        //error

    }

    state = MENU;
}

Game::~Game()
{
    //dtor
}

void Game::runGame()
{

    while (state != END)
    {
        switch (state)
        {
        case GameState::MENU:
            menu();
            break;
        case GameState::GAME:
            gameStart();
            break;
        case GameState::OPTIONS:
            options();
            break;

        }
    }

}

void Game::gameStart()
{

   // Texture backgroundTexture;
   // Sprite backgroundSpirte;

    vector<Arrow*> strzaly;
    backgroundTexture.loadFromFile("jungle.png");
    backgroundSprite.setTexture(backgroundTexture);

    while (state != END)
    {
        Text title ("Archer The Game",font,30);
        title.setStyle(Text::Bold);
        title.setPosition(800/2-title.getGlobalBounds().width/2,20);


        Event event;

        while (window.pollEvent(event))
        {

            if (event.type==Event::Closed || Event::KeyPressed && event.key.code == Keyboard::Escape)
                state = END;

            if (Event::KeyPressed && event.key.code == Keyboard::Up)
            {
                luk->changeAngleUp();
                strzala->changeAngleUp();
            }

            if (Event::KeyPressed && event.key.code == Keyboard::Down)
            {
                luk->changeAngleDown();
                strzala->changeAngleDown();
            }

            if (Mouse::isButtonPressed(Mouse::Left))
            {



                mousePos = Vector2f(Mouse::getPosition(window));
                playerPos= gracz -> pozycja;
                aimDir = mousePos - playerPos;
                x=(sqrt( pow(aimDir.x,2)+pow(aimDir.y,2)));
                aimDirNorm = Vector2f(aimDir.x/x,aimDir.y/x);
               // cout<<strzaly.size()<<endl;


                strzaly.push_back(strzala);
               // cout<<strzaly.size()<<endl;

                strzala->aSprite.setPosition(playerPos);
                strzala->currVelo = aimDir * strzala->maxSpeed;

                //cout<<strzala->currVelo.x<<"  "<<strzala->maxSpeed<<endl;

                strzaly.push_back(strzala);
                //cout<<strzaly.size()<<endl;

                for (size_t i = 0 ; i<strzaly.size(); i++)
                {
                    strzaly[i]->aSprite.move(strzaly[i]->currVelo);

                    if (strzaly[i]->aSprite.getPosition().x < 0 || strzaly[i]->aSprite.getPosition().x > window.getSize().x ||
                        strzaly[i]->aSprite.getPosition().y < 0 || strzaly[i]->aSprite.getPosition().y > window.getSize().y )
                    {
                        strzaly.erase(strzaly.begin() + i);
                    }

                }
                //cout<<strzaly.size()<<endl;



                //cout<< aimDirNorm.x << " " <<aimDirNorm.y <<endl;

            }

        }

        window.clear();
        window.draw(backgroundSprite);
        window.draw(gracz->getSpirte());
        window.draw(luk->getSprite());
        //cout<<"xd"<<endl;

        //cout<<czas(clock());
       // cout<<czas(clock())<<endl;



        if (a==0)
        {
        if (obiekt->aSprite.getPosition().y<600&& czas(clock())%5==0)
        {

            obiekt->objMove();
            //cout<<"XDD"<<endl;
            cout<<a<<endl;

            a++;
            cout<<a<<endl;





        }
        if (obiekt->aSprite.getPosition().y>600)
        {
            cout<<"Obiekt poza obszarem, koniec gry"<<endl;
        }
        }
        else if(czas(clock())%5!=0) {a=0;}

        for (size_t i = 0 ;i<strzaly.size();i++)
        {
            window.draw(strzala->getSprite());
            //cout<<"??"<<endl;
        }
        window.draw(strzala->getSprite());
        window.draw(obiekt->getSprite());
        window.draw(title);
        window.display();

    }

}




void Game::options()
{
    Text title1 ("Archer The Game",font,80);
    title1.setStyle(Text::Bold);
    Text title2 ("Options",font,60);
    title1.setPosition(800/2-title1.getGlobalBounds().width/2,20);
    title2.setPosition(800/2-title2.getGlobalBounds().width/2,120);

    diff=0;

    Text poziom;
    Text powrot;

    string str1[] = {"Easy","Normal","Hard"};

    poziom.setFont(font);
    poziom.setCharacterSize(65);

    poziom.setString(str1[0]);
    poziom.setPosition(800/2-poziom.getGlobalBounds().width/2,250);

    powrot.setFont(font);
    powrot.setCharacterSize(65);

    powrot.setString("Back");
    powrot.setPosition(1280/2-poziom.getGlobalBounds().width/2,250+2*120);

    while (state == OPTIONS)
    {
        Vector2f mouse(Mouse::getPosition(window));

        Event event;

        while (window.pollEvent(event))
        {
            if (event.type==Event::Closed || Event::KeyPressed && event.key.code == Keyboard::Escape)
                state = END;

            else if (powrot.getGlobalBounds().contains(mouse) && event.type == Event::MouseButtonReleased
                       && event.key.code== Mouse::Left)
                        state = MENU;

            if(poziom.getGlobalBounds().contains(mouse) && event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left)
            {
                if(diff==2) diff=0;
                else diff++;
                poziom.setString(str1[diff]);
                poziom.setPosition(800/2-poziom.getGlobalBounds().width/2,250);

            }


        }

            if(poziom.getGlobalBounds().contains(mouse))
            poziom.setColor(Color::Red);
            else poziom.setColor(Color::White);

            if(powrot.getGlobalBounds().contains(mouse))
            powrot.setColor(Color::Red);
            else powrot.setColor(Color::White);

            window.clear();

            window.draw(title1);
            window.draw(title2);
            window.draw(poziom);
            window.draw(powrot);

            window.display();


    }



}

void Game::menu()
{


    Text title ("Archer The Game",font,80);
    title.setStyle(Text::Bold);

    title.setPosition(800/2-title.getGlobalBounds().width/2,20);

    const int ile = 3;

    Text tekst[ile];

    string str[] = {"Play","Options","Exit"};

    for (int i=0;i<ile;i++)
    {


        tekst[i].setFont(font);
        tekst[i].setCharacterSize(65);

        tekst[i].setString(str[i]);
        tekst[i].setPosition(1280/2-tekst[i].getGlobalBounds().width/2,250+i*120);

    }

      while(state == MENU)
      {

          Event event;

          Vector2f mouse (Mouse::getPosition(window));

          while (window.pollEvent(event))
          {
              if (event.type==Event::Closed || Event::KeyPressed && event.key.code == Keyboard::Escape)
                state = END;

              else if (tekst[2].getGlobalBounds().contains(mouse) && event.type == Event::MouseButtonReleased
                       && event.key.code== Mouse::Left)
                        state = END;
              if (tekst[0].getGlobalBounds().contains(mouse) && event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left)
                    state = GAME;
              if (tekst[1].getGlobalBounds().contains(mouse) && event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left)
                state = OPTIONS;

          }
            for(int i=0;i<ile;i++)
            if(tekst[i].getGlobalBounds().contains(mouse))
            tekst[i].setColor(Color::Red);
            else tekst[i].setColor(Color::White);

            window.clear();

            window.draw(title);
            for (int i =0; i<ile; i++)
            window.draw(tekst[i]);
            window.display();
      }

}

int Game::czas (clock_t t)
{
    return static_cast <int> (t) / CLOCKS_PER_SEC;
}
