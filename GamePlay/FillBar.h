#include <SFML/Graphics.hpp>
#include <iostream>

class FillBar {
public:
    int x;
    int y;
    int w;
    int h;
    float amount;
    sf::Color fgColor;
    sf::Color bgColor;
    int alignment; // 0 for left, 1 for right

    sf::RectangleShape background;
    sf::RectangleShape foreground;

    FillBar(int posX, int posY, int width, int height, sf::Color foregroundColor, sf::Color backgroundColor, int leftOrRight) {
        x = posX;
        y = posY;
        w = width;
        h = height;
        amount = 1.0f;
        alignment = leftOrRight;
        fgColor = foregroundColor;
        bgColor = backgroundColor;
        foreground.setSize(sf::Vector2f((float) w, (float) h));
        background.setSize(sf::Vector2f((float) w, (float) h));
        foreground.setPosition(x, y);
        background.setPosition(x, y);
        foreground.setFillColor(fgColor);
        background.setFillColor(bgColor);
    }

    void update() {
        background.setPosition(x, y);
        if (alignment == 0) {
            foreground.setPosition(x, y);
        }
        //foreground.setSize(sf::Vector2f((float) w * amount, (float) h));
        //background.setSize(sf::Vector2f((float) w, (float) h));
        foreground.setScale(amount, 1.0f);
        //cout << "fill bar" << endl;
    }
};