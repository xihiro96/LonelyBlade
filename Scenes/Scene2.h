//
// Created by mhendrix on 4/26/18.
//

#ifndef SFMLDEMO_SCENE2_H
#define SFMLDEMO_SCENE2_H
#include "sharedScenes.h"
void resetGlobalsScene2();
void inBarScript(sf::RenderWindow * window, int * enterPressed);
void afterPartyScript(sf::RenderWindow * window, int * enterPressed);
void beforeStranger(sf::RenderWindow * window, int * enterPressed);
void afterStranger(sf::RenderWindow * window, int * enterPressed);
void bartenderIntro(sf::RenderWindow * window, int * enterPressed);
void strangerTalk1(sf::RenderWindow * window, int * enterPressed);
void postBattle2Script(sf::RenderWindow * window, int * enterPressed);
GameState runScene2B(sf::RenderWindow * window, sf::Clock * sceneClock);
GameState runScene2A(sf::RenderWindow * window, sf::Clock * sceneClock);
#endif //SFMLDEMO_SCENE2_H
