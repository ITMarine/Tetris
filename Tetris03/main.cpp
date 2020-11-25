#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <ctime>
#include "map.h"


using namespace std;
using namespace sf;

enum FigureType
{
    SQUARE, STICK, FORK, LBOOT, RBOOT, LSHOE, RSHOE
};
enum FigureState
{
    UP, DOWN, LEFT, RIGHT
};

class Figure
{
public:

    Figure(int _type)
    {
        switch(_type)
        {
            case 0: {type=SQUARE; figureArray_fill(square); break;}
            case 1: type=STICK; break;
            case 2: type=FORK; break;
            case 3: type=LBOOT; break;
            case 4: type=RBOOT; break;
            case 5: type=LSHOE; break;
            case 6: type=RSHOE; break;

        }

        state = UP;
        figure_x = 4;
        figure_y = 0;
    }
    ~Figure(){}

    void figureArray_fill(std::string *sample)
    {
        for (int i=0; i<4; i++)
             for (int j=0; j<4; j++)
                figure_array[i][j]=sample[i][j];
    }

    void well_update()
    {


    }


    int figure_x, figure_y;
    float d_speed;
    string figure_array[4];
    Sprite f_sprite;

private:
    FigureType type;
    FigureState state;


};

void TextureLoad();

int main()
{


    srand(time(0));
    sf::Clock clock;
    sf::RenderWindow app(sf::VideoMode(800, 600), "SFML window");
    sf::Texture redTexture, blueTexture, greenTexture, purpleTexture, orangeTexture;
    redTexture.loadFromFile("/home/paul/C++/Tetris03/redsquare20x20.png");
    blueTexture.loadFromFile("/home/paul/C++/Tetris03/bluesquare20x20.png");
    greenTexture.loadFromFile("/home/paul/C++/Tetris03/greensquare20x20.png");
    purpleTexture.loadFromFile("/home/paul/C++/Tetris03/purplesquare20x20.png");
    orangeTexture.loadFromFile("/home/paul/C++/Tetris03/orangesquare20x20.png");

    Sprite well_sprite;

    //Figure figure(rand()%7);
    Figure figure(0);


    while (app.isOpen())
    {


        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time=time/800;

        // Process events
        sf::Event event;
        while (app.pollEvent(event))
        {
                if (event.type == sf::Event::Closed)
                app.close();
        }

        app.clear();

        figure.well_update();

//================== setting figure into well =============================
        for (int i=0; i<4; i++)
            for (int j=0; j<4; j++)
            {
                if (figure.figure_array[i][j]=='1')
                tile_map[i+figure.figure_y][j+figure.figure_x]='s';
            }
//================== making Well at screen ================================
        for(int i=0; i<HEIGHT; i++)
            for(int j=0; j<WIDTH; j++)
            {
                if (tile_map[i][j]=='r')
                {
                    well_sprite.setPosition(j*20+300, i*20+100);
                    well_sprite.setTexture(blueTexture);
                    app.draw(well_sprite);
                }
                if (tile_map[i][j]=='s')
                {
                     well_sprite.setPosition(j*20+300, i*20+100);
                     well_sprite.setTexture(redTexture);
                     app.draw(well_sprite);
                }
            }
//=========================================================================

        app.display();
    }

    return EXIT_SUCCESS;
}
