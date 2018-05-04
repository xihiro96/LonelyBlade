//
// Created by justi_000 on 4/28/2018.
//

#ifndef SFMLDEMO_MOVEBUTTON_H
#define SFMLDEMO_MOVEBUTTON_H
#include <SFML/Graphics.hpp>
#define PI 3.14159265

class MoveButton {
private:
    sf::CircleShape appearance;
    sf::Color color;
    sf::Color Hcolor;
    bool textured;
    sf::Texture *texture;
    sf::Texture *Htexture;
    float centerX;
    float centerY;
    float posX;
    float posY;
public:
    //Constructors
    bool active;
    MoveButton();
    MoveButton(bool);
    MoveButton(float,float,sf::Color,sf::Color,sf::Color,float,float);    //init x, y, fill color, outline color, outline thickness, radius
    MoveButton(float,float,sf::Texture *,sf::Texture *, float);

    //Get functions
    sf::CircleShape getAppearance();
    void highlight();
    void unhighlight();
    void setCenter(float, float);
    void setPosition(float, float);
    sf::Vector2f getPosition();
    sf::Vector2f getCenter();
    float radius;
};


#endif //SFMLDEMO_MOVEBUTTON_H
