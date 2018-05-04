//
// Created by mhendrix on 5/3/18.
//

#ifndef SFMLDEMO_RUNBATTLE_H
#define SFMLDEMO_RUNBATTLE_H
#include "character.h"
#include "FillBar.h"
#include <SFML/Graphics.hpp>
#include <cmath>
#include "../MainGame.h"
#include <stdlib.h>
void resetBattle();
GameState runBattle1(sf::RenderWindow * window);
GameState runBattle2(sf::RenderWindow * window);
GameState runBattle3(sf::RenderWindow * window);
GameState runBattle4(sf::RenderWindow * window);
float distanceFormula(float, float, float, float);
float distanceFormula2(float, float, float, float);
int isHoveringAlly(sf::Vector2i);
int isHoveringAlly2(int, sf::Vector2i);
int isHoveringEnemy(sf::Vector2i);
int isHoveringEnemy2(int, sf::Vector2i);
int isHoveringMove(MoveMenu &, sf::Vector2i);
void drawPiMenu(sf::CircleShape &, sf::Vector2f);
#endif //SFMLDEMO_RUNBATTLE_H
