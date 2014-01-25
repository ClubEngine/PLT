#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>

using namespace std;

int main()
{
    bool mouseispressed;

    struct selected {
        sf::Vector2i p1;
        sf::Vector2i p2;
    };
    float aux;

    selected selected;

    float a = -10.0;
    float b = -10.0;
    float c = -10.0;
    float d = -10.0;
    int width =800;
    int height =600;
    int map[width/10][height/10];
    for (int i = 0 ; i < width/10 ; i++)
    {
        for (int j = 0 ; j < height/10 ; j++)
        {
            map[i][j] = 0;
        }
    };

    sf::RenderWindow window(sf::VideoMode(width,height), "mouseInput",sf::Style::Default);
    window.setKeyRepeatEnabled(false);

    sf::RectangleShape cursor(sf::Vector2f(10,10));
    sf::RectangleShape herbe(sf::Vector2f(10,10));

    herbe.setFillColor(sf::Color(0,255,0));
    herbe.setOutlineThickness(0.5);
    herbe.setOutlineColor(sf::Color::White);

    cursor.setFillColor(sf::Color(255,0,0,127));
    cursor.setOutlineThickness(0.5);
    cursor.setOutlineColor(sf::Color::White);

    sf::Texture grid;
    if (!grid.loadFromFile("grid.png", sf::IntRect(0,0,width,height)))
    {
        return 1;
    }

    sf::Sprite gridsprite;
    gridsprite.setTexture(grid);

    sf::Event event;

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            /*
            sf::Vector2i mpos = sf::Mouse::getPosition(window);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                cout << "Mouse cliked at : " << "(" << mpos.x << "," << mpos.y << ")" << endl;
            }
            */

            if (event.type == sf::Event::MouseButtonPressed)
            {
                mouseispressed = true;
                cout << "Mouse clicked at : " << "(" << event.mouseButton.x << "," << event.mouseButton.y << ")" << endl;
                cout << "corresponding to : " << "(" << floor((float)event.mouseButton.x/10.0) << "," << floor((float)event.mouseButton.y/10.0) << ")" << endl;
                a = floor((float)event.mouseButton.x/10.0)*10.0;
                b = floor((float)event.mouseButton.y/10.0)*10.0;
                cout << "a = " << a << "," << " b = " << b << endl;
                selected.p1.x = a;
                selected.p1.y = b;
                selected.p2.x = a+10;
                selected.p2.y = b+10;
                /*
                while (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    c = floor(sf::Mouse::getPosition(window).x/10.0)*10.0;
                    d = floor(sf::Mouse::getPosition(window).y/10.0)*10.0;

                };
                cout << "c = " << c << "," << " d = " << d << endl;
                */
            }

            if (mouseispressed && sf::Event::MouseMoved)
            {
                c = ceil(sf::Mouse::getPosition(window).x/10.0)*10.0;
                d = ceil(sf::Mouse::getPosition(window).y/10.0)*10.0;
                cout << "c = " << c << "," << " d = " << d << endl;
                selected.p2.x = c;
                selected.p2.y = d;
            }

            if (event.type == sf::Event::MouseButtonReleased)
            {
              if (selected.p1.x > selected.p2.x)
              {
                  aux = selected.p1.x;
                  selected.p1.x = selected.p2.x;
                  selected.p2.x = aux;
              }

              if (selected.p1.y > selected.p2.y)
              {
                  aux = selected.p1.y;
                  selected.p1.y = selected.p2.y;
                  selected.p2.y = aux;
              }

              if (selected.p2.x > width){
                  selected.p2.x = width;
              }
              if (selected.p2.y > height){
                  selected.p2.y = height;
              }

              if (selected.p1.x < 0){
                  selected.p1.x = 0;
              }
              if (selected.p1.y < 0){
                  selected.p1.y = 0;
              }
              mouseispressed = false;
            }

            /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)){
                cout << "coucou" << selected.p1.x << "," << selected.p2.x << ","<< selected.p1.y << ","<< selected.p2.y << "." ;
                for (int i = selected.p1.x ; i <= selected.p2.x ; i++)
                {
                    for (int j = selected.p1.y ; j <= selected.p2.y ; j++)
                    {
                        map[i][j] = 1;
                    }
                }
            }*/
            if (event.type == sf::Event::KeyPressed)
            {
                for (int i = selected.p1.x/10 ; i < selected.p2.x/10 ; i++)
                {
                    for (int j = selected.p1.y/10 ; j < selected.p2.y/10 ; j++)
                    {
                        switch (event.key.code)
                        {
                        case sf::Keyboard::H : {
                            map[i][j] = 1;
                            break;
                        }
                        case sf::Keyboard::R : {
                            map[i][j] = 2;
                            break;
                        }
                        case sf::Keyboard::P : {
                            map[i][j] = 3;
                            break;
                        }
                        case sf::Keyboard::BackSpace : {
                            map[i][j] = 0;
                            break;
                        }
                        }
                    }
                }

                /* ==============template code :==================
                if (event.key.code == sf::Keyboard::)
                {
                    for (int i = selected.p1.x/10 ; i < selected.p2.x/10 ; i++)
                    {
                        for (int j = selected.p1.y/10 ; j < selected.p2.y/10 ; j++)
                        {
                            map[i][j] = 1;
                        }
                    }
                }
                ==================================================*/
                /*
                if (event.text.unicode < 128)
                {
                    cout << event.text.unicode;
                    switch (event.text.unicode) {
                    case 104:
                    {
                        for (int i = selected.p1.x ; i <= selected.p2.x ; i++)
                        {
                            for (int j = selected.p1.y ; j <= selected.p2.y ; j++)
                            {
                                map[i][j] = 1;
                            }
                        }
                        cout << "h pressed";
                        break;
                    }
                    }
                }*/
            }


        }


        window.clear(sf::Color::White);

        for (int i = 0 ; i < width/10 ; i++)
        {
            for (int j = 0 ; j < height/10 ; j++)
            {
                switch (map[i][j]) {
                case 1:
                {
                    sf::RectangleShape herbe(sf::Vector2f(10,10));

                    herbe.setFillColor(sf::Color(50,200,50));
                    //herbe.setOutlineThickness(0.5);
                    //herbe.setOutlineColor(sf::Color::White);

                    herbe.setPosition(sf::Vector2f(i*10, j*10));

                    window.draw(herbe);
                    break;
                }
                case 2:
                {
                    sf::RectangleShape herbe(sf::Vector2f(10,10));

                    herbe.setFillColor(sf::Color(150,150,150));
                    //herbe.setOutlineThickness(0.5);
                    //herbe.setOutlineColor(sf::Color::White);

                    herbe.setPosition(sf::Vector2f(i*10, j*10));

                    window.draw(herbe);
                    break;
                }
                case 3:
                {
                    sf::RectangleShape herbe(sf::Vector2f(10,10));

                    herbe.setFillColor(sf::Color(50,200,50));
                    //herbe.setOutlineThickness(0.5);
                    //herbe.setOutlineColor(sf::Color::White);

                    herbe.setPosition(sf::Vector2f(i*10, j*10));

                    window.draw(herbe);
                    break;
                }
                }
            }
        };
        window.draw(gridsprite);

        cursor.setSize((sf::Vector2f)(selected.p2-selected.p1));
        cursor.setPosition((sf::Vector2f)selected.p1);

        window.draw(cursor);

        window.display();
    }
    return 0;
}

