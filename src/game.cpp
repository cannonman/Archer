#include "game.h"
#include <iostream>
#include <math.h>

#define _USE_MATH_DEFINES


#define M_PI 3.14159265358979323846
#define FRAMERATE 60
#define MAX_ANGLE -40
#define MIN_ANGLE 10
#define ARROW_SPEED 10

using namespace std;

RenderWindow window(VideoMode(800,600),"Archer The Game");


Game::Game()
{
    state= END;

    gracz = new Player (-50,200);

    luk = new Bow (84,340);

    strzala = new Arrow(84, 340);

    obiekt = new Target (550,10);

    diff=0;
    time=5;

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

    backgroundTexture.loadFromFile("jungle.png");
    backgroundSprite.setTexture(backgroundTexture); //load texture
    points=0;
        switch (diff)
        {
            case 0: time = 5;
            break;
            case 1: time = 4;
            break;
            case 2: time = 2;
            break;
            //default: time=5;
        }


    while (state != END)
    {


        mainClock.restart(); //start time measure
        Text title ("Archer The Game",font,30);
        Text punkty ("Punkty: ",font,15);
        title.setStyle(Text::Bold);
        title.setPosition(800/2-title.getGlobalBounds().width/2,20); //setting window options
        punkty.setPosition(10,10);


        Event event;


        while (window.pollEvent(event)) //wait for event
        {

            //cout<<"EVENT"<<endl;

            vector.y = -ARROW_SPEED*(-sin((float)M_PI*(angle/180)));
            vector.x =ARROW_SPEED*cos ((float)M_PI*abs(angle/180));



            if (event.type==Event::Closed || Event::KeyPressed && event.key.code == Keyboard::Escape)
                state = END;
                 //game escape

            if (Event::KeyPressed && event.key.code == Keyboard::Up)
            {
                if (angle-1.5>=MAX_ANGLE) {
                        cout<<"UP"<<endl;
                    angle -=1.5;
                    luk->setAngle(angle);
                    if (!strzala->ifReleased()){

                        strzala->setAngle(angle); //lift bow  and arrow up
                    }

                }
            }

            if (Event::KeyPressed && event.key.code == Keyboard::Down)
            {
                if (angle+1.5<=MIN_ANGLE) {
                    angle +=1.5;
                    luk->setAngle(angle);
                    cout<<"w dol"<<endl;

                    if (!strzala->ifReleased()){
                        strzala->setAngle(angle); //lift bow and arrow down

                }
                }
            }

            if (Event::KeyPressed && event.key.code == Keyboard::Space)
            {

                strzala->release();



             if (strzala->aSprite.getPosition().x < 0 || strzala->aSprite.getPosition().x > window.getSize().x) {
                    delete strzala;
                    strzala = new Arrow(84, 340);
                    strzala->setAngle(angle);
                }
                if (strzala->aSprite.getPosition().y < 0 || strzala->aSprite.getPosition().y > window.getSize().y) {
                    delete strzala;
                    strzala = new Arrow(84, 340);
                    strzala->setAngle(angle);
                }

            }

        }

        if (Collision::PixelPerfectTest(strzala->getSprite(),obiekt->getSprite()))
        {
            //cout<<"Kolizja"<<endl;

            points++;

            strzala->resetPosition();
            obiekt->resetPosition();

           // cout<<"Punkty: "<<points<<", Czas: "<<time<<endl;

            if (points%3==0&&time>1)
                time--;


        }


        window.clear();
        window.draw(backgroundSprite);
        window.draw(gracz->getSpirte());
        window.draw(luk->getSprite());
        window.draw(strzala->getSprite());

        if (a==0)
        {
        if (obiekt->aSprite.getPosition().y<600&& czas(clock())%time==0)
        {

            obiekt->objMove();

           // cout<<a<<endl;

            a++;
           // cout<<a<<endl;





        }
        if (obiekt->aSprite.getPosition().y>600)
        {
            //cout<<"Obiekt poza obszarem, koniec gry"<<endl;
            state = GAME_OVER;
        }
        }
        else if(czas(clock())%time!=0) {a=0;}

        if (strzala->ifReleased()){

            strzala->aSprite.move(vector);
        }

        window.draw(strzala->getSprite());
        window.draw(obiekt->getSprite());
        window.draw(title);
        window.draw(punkty);
        window.display();

        elapsed = mainClock.getElapsedTime(); //get time measured
        sleep((sf::milliseconds(1000/FRAMERATE) - mainClock.getElapsedTime()));

    }

}




void Game::options()
{

    Text title1 ("Archer The Game",font,80);
    title1.setStyle(Text::Bold);
    Text title2 ("Options",font,60);
    title1.setPosition(800/2-title1.getGlobalBounds().width/2,20);
    title2.setPosition(800/2-title2.getGlobalBounds().width/2,120);


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
                cout<<diff<<endl;

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

   // cout<<diff<<endl;

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
