//
// Created by mhendrix on 4/13/18.
//

#ifndef SFMLDEMO_SCENE1_H
#define SFMLDEMO_SCENE1_H
#include "sharedScenes.h"
void resetGlobalsScene1();
void playBrotherFight(sf::RenderWindow * window);
void playBlackCoatFight(sf::RenderWindow * window);
void beginScript1B(sf::RenderWindow * window, int * enterPressed);
void beginScript1B2(sf::RenderWindow * window, int * enterPressed);
void beginScript1B3(sf::RenderWindow * window, int * enterPressed);
void beginScript1B4(sf::RenderWindow * window, int * enterPressed);
void resetFade();
void beginScript(sf::RenderWindow * window, int * enterPressed);
GameState runScene1B(sf::RenderWindow * window, sf::Clock * sceneClock1);
GameState runScene1(sf::RenderWindow * window, sf::Clock * sceneClock);





#endif //SFMLDEMO_SCENE1_H
