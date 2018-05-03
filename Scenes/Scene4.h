//
// Created by mhendrix on 4/30/18.
//

#ifndef SFMLDEMO_SCENE4A_H
#define SFMLDEMO_SCENE4A_H
#include "sharedScenes.h"
void resetGlobalsScene4();
void beforeFinalBoss(sf::RenderWindow * window, int * enterPressed);
void beforeBar(sf::RenderWindow * window, int * enterPressed);
GameState runScene4A(sf::RenderWindow * window, sf::Clock * sceneClock);
void lastWords(sf::RenderWindow * window, int * enterPressed);
void almostDoneScript(sf::RenderWindow * window, int * enterPressed);
GameState runScene4B(sf::RenderWindow * window, sf::Clock * sceneClock);
#endif //SFMLDEMO_SCENE4A_H
