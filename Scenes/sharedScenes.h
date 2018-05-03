//
// Created by mhendrix on 4/20/18.
//

#ifndef SFMLDEMO_SHAREDSCENES_H
#define SFMLDEMO_SHAREDSCENES_H
#include "SFML/Graphics.hpp"
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include "../MainGame.h"
//cursor positions

const sf::Vector2f cursorLow= sf::Vector2f(1770,1060);
const sf::Vector2f cursorHigh= sf::Vector2f(1770,1050);
//samurai faces
const sf::IntRect samuraiSmile = sf::IntRect(1292, 5, 252, 252);
const sf::IntRect samuraiConcern = sf::IntRect(776, 2, 252, 252);
const sf::IntRect samuraiGrimace = sf::IntRect(1550, 2, 252, 252);
const sf::IntRect samuraiCalm = sf::IntRect(1808, 2, 252, 252);
const sf::IntRect samuraiYell = sf::IntRect(2, 2, 252, 252);
const sf::IntRect samuraiExtremeYell = sf::IntRect(518, 2, 252, 252);

const sf::Vector2f samuraiSmilePos = sf::Vector2f(500, 380);
//concern, grimace, calm position, yell, extremeyell
const sf::Vector2f samuraiOtherPos = sf::Vector2f(500, 374);


//brotherfaces
const sf::IntRect brotherSmile = sf::IntRect(780, 2, 252, 252);
const sf::IntRect brotherAnnoyed = sf::IntRect(1038, 2, 252, 252);
const sf::IntRect brotherStern =  sf::IntRect(1296, 2, 252, 252);
const sf::IntRect brotherYell = sf::IntRect(6, 2, 252, 252);

const sf::Vector2f brotherPos = sf::Vector2f(1400,380);

//textBox
const sf::Color textBoxcolor = sf::Color(44,14,14,255);

//Amy Faces
const sf::IntRect bartenderFrown = sf::IntRect(780, 2, 252, 252);
const sf::IntRect bartenderSmile = sf::IntRect(1035, 2, 252, 252);
const sf::IntRect bartenderBigSmile = sf::IntRect(520, 2, 252, 252);
const sf::IntRect bartenderUpset = sf::IntRect(260, 2, 252, 252);
const sf::IntRect bartenderEvilSmile = sf::IntRect(2, 2, 252, 252);
//nameBox
const sf::Vector2f nameBoxSize = sf::Vector2f(150,50);
const sf::Color nameBoxColor = sf::Color(222,184,135);
const sf::Vector2f brotherNamePos = sf::Vector2f(1510,845);
const sf::Vector2f baryNamePos = sf::Vector2f(1530,845);
const sf::Vector2f strangerNamePos = sf::Vector2f(1540,845);
const sf::Vector2f amyNamePos = sf::Vector2f(1535,845);
const sf::Vector2f brotherNameBoxPos = sf::Vector2f(1500,850);
const sf::Vector2f samuraiNameBoxPos = sf::Vector2f(225,850);
const sf::Vector2f samuraiNamePos = sf::Vector2f(257,845);
const std::string samuraiName = "Silas";
const std::string brotherName = "Xander";
const std::string strangerName = "???";
const std::string barName = "Bary";
const std::string bartenderName = "Amy";
const std::string islandManName = "Kato";
//cursor
const sf::Color cursorColor = sf::Color(255,215,0,255);
const sf::Vector2f cursorFlip = sf::Vector2f(1.f,-1.f);
//text position
const sf::Vector2f textPos = sf::Vector2f(290, 905);

void introChapterNum(sf::RenderWindow * window, std::string * string, sf::Clock * smallClock);
void partyJoin(sf::RenderWindow * window, std::string * string, sf::Clock * smallClock);
void initNameBox(sf::RectangleShape * nameBox, sf::Vector2f namePos);
void initNameTag(sf::Text * name, sf::Font * font, sf::Vector2f nameTagPos, std::string nameText);
void createScript(sf::Text * text, sf::Font * font, std::string line);
void fillBackground(sf::RenderWindow * window, std::string * backgroundFile, sf::Uint8 * fadeVal, sf::Clock * smallClock);
void fillImage(sf::RenderWindow * window, std::string * backgroundFile, sf::Uint8 * fadeVal, sf::Clock * smallClock);
void runText(sf::RenderWindow * window, const std::string * string, int x, int y, sf::Uint8 * fadeVal, sf::Clock * smallClock, bool * fadeOut, bool * holdText);
void slideInSprites(sf::RenderWindow * window, const std::string * back, int * spritePosition, sf::Clock * smallClock, int * textBoxPos, const std::string * string1, const std::string * string2, const sf::IntRect * expression1, const sf::IntRect * expression2);
void slideSpriteRight(sf::RenderWindow * window, const std::string * back, int * spritePosition, sf::Clock * smallClock, int * textBoxPos, const std::string * string1, const std::string * string2, const sf::IntRect * expression1, const sf::IntRect * expression2);
void slideSamurai(sf::RenderWindow * window, std::string * fileName, const sf::IntRect * expression, sf::Clock * smallClock, int * spritePosition, int * textBoxPos);
void displayBlack(sf::RenderWindow * window);

void initSelect();
void playSelect();
#endif //SFMLDEMO_SHAREDSCENES_H
