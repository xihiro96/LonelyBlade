//
// Created by justi_000 on 4/28/2018.
//

#include "MoveButton.h"

MoveButton::MoveButton() {
    appearance = sf::CircleShape(0);
}

MoveButton::MoveButton(float x, float y, sf::Color fillColor, sf::Color highlightColor, sf::Color outlineColor, float outlineThickness, float radiusIn) {
    active = true;
    appearance = sf::CircleShape(radiusIn);
    //appearance.setPosition(x-radiusIn, y-radiusIn);
    color = fillColor;
    Hcolor = highlightColor;
    appearance.setFillColor(color);
    appearance.setOutlineColor(outlineColor);
    appearance.setOutlineThickness(outlineThickness);
    radius = radiusIn;
    textured = false;
}

MoveButton::MoveButton(float x, float y, sf::Texture *fillTex, sf::Texture *highlightTex, float radiusIn) {
    active = true;
    appearance = sf::CircleShape(radiusIn);
    //appearance.setPosition(x-radiusIn, y-radiusIn);
    //color = fillColor;
    //Hcolor = highlightColor;
    texture = fillTex;
    Htexture = highlightTex;
    textured = true;
    appearance.setTexture(texture);
    //appearance.setFillColor(color);
    //appearance.setOutlineColor(outlineColor);
    //appearance.setOutlineThickness(outlineThickness);
    radius = radiusIn;
}

MoveButton::MoveButton(bool isActive) {
    active = false;
    appearance = sf::CircleShape(30.0f);
    radius = 25.0;
    color = sf::Color(100,100,100,255);
    Hcolor = sf::Color(150,150,150,255);
}

void MoveButton::highlight() {
    if (textured) {
        appearance.setTexture(Htexture);
    } else {
        appearance.setFillColor(Hcolor);
    }
}

void MoveButton::unhighlight() {
    if (textured) {
        appearance.setTexture(texture);
    } else {
        appearance.setFillColor(color);
    }
}

sf::CircleShape MoveButton::getAppearance(){
    return appearance;
}

void MoveButton::setCenter(float x, float y){
    centerX = x;
    centerY = y;
}

void MoveButton::setPosition(float x, float y){
    posX = x;
    posY = y;
    appearance.setPosition(x,y);
    setCenter(x + radius, y + radius);
}

sf::Vector2f MoveButton::getPosition(){
    return sf::Vector2f(posX, posY);
}

sf::Vector2f MoveButton::getCenter(){
    return sf::Vector2f(centerX, centerY);
}