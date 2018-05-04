//
// Created by justi_000 on 4/28/2018.
//

#ifndef SFMLDEMO_MOVEMENU_H
#define SFMLDEMO_MOVEMENU_H


#define BUTTON_RADIUS 25

#include "MoveButton.h"
#include "move.h"
#include <vector>


class MoveMenu {
private:
    int numButtons;
    sf::Vector2f center;
    float radius;

public:
    std::vector<MoveButton> piMenu;
    MoveMenu();
    MoveMenu(float,float,float);    //center x, center y, radius
    MoveMenu(float,float,float, std::vector<Move>);    //center x, center y, radius
    sf::Vector2f getCenter();
    void setCenter(sf::Vector2f);
    void setMenuPosition(sf::Vector2f);
    void resetMenuPosition();
};


#endif //SFMLDEMO_MOVEMENU_H
