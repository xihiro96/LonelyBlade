//
// Created by justi_000 on 4/28/2018.
//

#include <cmath>
#include "MoveMenu.h"


MoveMenu::MoveMenu() {center = sf::Vector2f(0.0f,0.0f); numButtons = 8; radius = 20; piMenu.clear();}
MoveMenu::MoveMenu(float x, float y, float r) {
    center = sf::Vector2f(x, y);
    radius = r;
    numButtons = 8;
    piMenu.clear();
    for(int i = 0; i < numButtons; ++i){
        MoveButton mButton(false);
        //piMenu.push_back(mButton);
    }
}

MoveMenu::MoveMenu(float x, float y, float r, std::vector<Move> moves) {
    center = sf::Vector2f(x, y);
    radius = r;
    numButtons = 8;
    piMenu.clear();
    for(int i = 0; i < numButtons; ++i) {

        MoveButton mButton;
        if (moves[i].exists == true) {
            //mButton = MoveButton(false);
            if (moves[i].textured) {
                mButton = MoveButton(-100.0f,-100.0f, moves[i].texture, moves[i].texture2,BUTTON_RADIUS);
            } else {
                mButton = MoveButton(-100.0f,-100.0f,sf::Color::Green, sf::Color::Cyan,sf::Color::Yellow,2.0f,BUTTON_RADIUS);  //button off-center displacement already accounted for in MoveButton.cpp; hide buttons at init
            }
        } else {
            mButton = MoveButton(false);
        }
        piMenu.push_back(mButton);
    }
}

sf::Vector2f MoveMenu::getCenter(){
    return center;
}

void MoveMenu::setCenter(sf::Vector2f c)
{
    center = c;
}

void MoveMenu::setMenuPosition(sf::Vector2f c){
    setCenter(c);
//    printf("%i\n",piMenu.size());
    for(int i = 0; i < numButtons; ++i)
    {
        piMenu[i].setPosition(center.x + radius*cos(i*2*PI/numButtons),center.y + radius*sin(i*2*PI/numButtons));
    }
}

void MoveMenu::resetMenuPosition(){
//    setCenter(c);
    for(int i = 0; i < piMenu.size(); ++i)
    {
        piMenu[i].setPosition(-100.0f,-100.0f);
    }
}