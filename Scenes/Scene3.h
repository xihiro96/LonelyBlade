//
// Created by mhendrix on 4/28/18.
//

#ifndef SFMLDEMO_SCENE3A_H
#define SFMLDEMO_SCENE3A_H

#include "sharedScenes.h"
void resetGlobalsScene3();
void postIslandFight(sf::RenderWindow * window, int * enterPressed);
GameState runScene3B(sf::RenderWindow * window, sf::Clock * sceneClock);
void enterIslandScript(sf::RenderWindow * window, int * enterPressed);
void enterDangerScript(sf::RenderWindow * window, int * enterPressed);
GameState runScene3A(sf::RenderWindow * window, sf::Clock * sceneClock);
#endif //SFMLDEMO_SCENE3A_H
