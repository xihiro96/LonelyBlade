//
// Created by mhendrix on 4/20/18.
//
#include "sharedScenes.h"
sf::Music selectSound;
void initNameBox(sf::RectangleShape * nameBox, sf::Vector2f namePos){
    nameBox->setFillColor(nameBoxColor);
    nameBox->setOutlineColor(sf::Color(0,0,0));
    nameBox->setOutlineThickness(8.f);
    nameBox->move(namePos);
}
void initNameTag(sf::Text * name, sf::Font * font, sf::Vector2f nameTagPos, std::string nameText){
    name->setFont(*font);
    name->setString(nameText);
    name->setCharacterSize(48);
    name->setColor(sf::Color(0,0,0));
    name->move(nameTagPos);
    name->setStyle(sf::Text::Bold);
}
void createScript(sf::Text * text, sf::Font * font, std::string line){
    text->setFont(*font);
    text->setString(line);
    text->setCharacterSize(42); // in pixels, not points!
    //set colors
    sf::Color colorText(255,255,255,255);
    text->setColor(colorText);
    text->move(textPos);
}
void introChapterNum(sf::RenderWindow * window, std::string * string, sf::Clock * smallClock){
    sf::Text text;
    sf::Font font;
    //load font
    if (!font.loadFromFile("made-in-china.regular.ttf"))
    {
        std::cout << "No font loaded" <<std::endl;
    }
    text.setFont(font);
    text.setString(*string);
    text.setCharacterSize(150); // in pixels, not points!
    //set colors
    sf::Color color(255,255,255,255);
    text.setColor(color);
    sf::Time elapsed1 = smallClock->getElapsedTime();


    text.setPosition(50,450);
    window->clear();
    if (elapsed1.asSeconds() > 1.2){
        window->draw(text);
    }
    window->display();
}

void partyJoin(sf::RenderWindow * window, std::string * string, sf::Clock * smallClock){
    sf::Text text;
    sf::Font font;
    //load font
    if (!font.loadFromFile("Beholder.ttf"))
    {
        std::cout << "No font loaded" <<std::endl;
    }
    text.setFont(font);
    text.setString(*string);
    text.setCharacterSize(150); // in pixels, not points!
    //set colors
    sf::Color color(255,255,255,255);
    text.setColor(color);
    sf::Time elapsed1 = smallClock->getElapsedTime();


    text.setPosition(100,450);
    window->clear();
    if (elapsed1.asSeconds() > .6){
        window->draw(text);
    }
    window->display();
}




void fillBackground(sf::RenderWindow * window, std::string * backgroundFile, sf::Uint8 * fadeVal, sf::Clock * smallClock){
    sf::RectangleShape background(sf::Vector2f(window->getSize().x,window->getSize().y));
    sf::RectangleShape fader(sf::Vector2f(window->getSize().x,window->getSize().y));
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile(*backgroundFile))
    {
        std::cout << "Cannot load background" << std::endl;
    }
    background.setTexture(&backgroundTexture);
    sf::Color color(0,0,0,*fadeVal);
    fader.setFillColor(color);
    sf::Time elapsed1 = smallClock->getElapsedTime();
    //fade in the background by fading away black square
    if(*fadeVal > 0) {
        if(elapsed1.asMilliseconds() > 20) {
            *fadeVal = *fadeVal - 5;
            color.a = *fadeVal;
            fader.setFillColor(color);
            smallClock->restart();
        }
    }
    window->clear();
    window->draw(background);
    window->draw(fader);
    window->display();
}

void fillImage(sf::RenderWindow * window, std::string * backgroundFile, sf::Uint8 * fadeVal, sf::Clock * smallClock){
    sf::RectangleShape background(sf::Vector2f(1300, 800));
    sf::RectangleShape fader(sf::Vector2f(window->getSize().x,window->getSize().y));
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile(*backgroundFile))
    {
        std::cout << "Cannot load background" << std::endl;
    }
    background.setTexture(&backgroundTexture);
    sf::Color color(0,0,0,*fadeVal);
    fader.setFillColor(color);
    sf::Time elapsed1 = smallClock->getElapsedTime();
    //fade in the background by fading away black square
    if(*fadeVal > 0) {
        if(elapsed1.asMilliseconds() > 20) {
            *fadeVal = *fadeVal - 5;
            color.a = *fadeVal;
            fader.setFillColor(color);
            smallClock->restart();
        }
    }
    background.move(sf::Vector2f(300,0));
    window->clear();
    window->draw(background);
    window->draw(fader);
    window->display();
}


void runText(sf::RenderWindow * window, const std::string * string, int x, int y, sf::Uint8 * fadeVal, sf::Clock * smallClock, bool * fadeOut, bool * holdText){

    sf::Text text;
    sf::Font font;
    //load font
    if (!font.loadFromFile("eutemia-i.italic.ttf"))
    {
        std::cout << "No font loaded" <<std::endl;
    }
    text.setFont(font);
    text.setString(*string);
    text.setCharacterSize(150); // in pixels, not points!
    //set colors
    sf::Color color(255,255,255,*fadeVal);
    text.setColor(color);
    //start timer
    sf::Time elapsed1 = smallClock->getElapsedTime();

    //fadeIn
    if (*fadeVal <= 255 && !*fadeOut && !*holdText){
        if (elapsed1.asMilliseconds() > 25){
            *fadeVal = *fadeVal + 5;
            color.a = *fadeVal;
            text.setColor(color);
            smallClock->restart();
        }
        if (*fadeVal >=255) {
            *holdText = true;
            smallClock->restart();
        }
    }
    if (*holdText){
        if (elapsed1.asSeconds() > 1.75) {
            *fadeOut = true;
            *holdText = false;
        }
    }
    //fadeOut
    if(*fadeOut){
        if (elapsed1.asMilliseconds() > 25){
            *fadeVal = *fadeVal - 5;
            color.a = *fadeVal;
            text.setColor(color);
            smallClock->restart();
        }
    }
    //display text
    text.setPosition(x, y);
    window->clear();
    window->draw(text);
    window->display();

}

void slideInSprites(sf::RenderWindow * window, const std::string * back, int * spritePosition, sf::Clock * smallClock, int * textBoxPos, const std::string * string1, const std::string * string2, const sf::IntRect * expression1, const sf::IntRect * expression2){
    sf::Time elapsed1 = smallClock->getElapsedTime();
    sf::RectangleShape background(sf::Vector2f(window->getSize().x,window->getSize().y));
    sf::RectangleShape textBox(sf::Vector2f(window->getSize().x, (window->getSize().y-380)));
    sf::Texture backgroundTexture;
    sf::Texture samuraiTexture;
    sf::Sprite samuraiSprite;
    sf::Texture brotherTexture;
    sf::Sprite brotherSprite;
    if (!backgroundTexture.loadFromFile(*back))
    {
        std::cout << "Cannot load forest background" << std::endl;
    }
    if (!samuraiTexture.loadFromFile(*string1, *expression1)){
        std::cout << "Cannot load samurai texture" << std::endl;
    }
    if (!brotherTexture.loadFromFile(*string2, *expression2)){
        std::cout << "Cannot load samurai texture" << std::endl;
    }

    background.setTexture(&backgroundTexture);

    samuraiSprite.setScale(sf::Vector2f(-2.f, 2.f));
    if(*spritePosition < 500){
        *spritePosition = *spritePosition + 50;
    }
    samuraiSprite.setPosition(sf::Vector2f(*spritePosition, 380));
    samuraiSprite.setTexture(samuraiTexture);

    brotherSprite.setScale(sf::Vector2f(2.f, 2.f));
    brotherSprite.setPosition(sf::Vector2f((1900-*spritePosition),380));
    brotherSprite.setTexture(brotherTexture);

    textBox.setFillColor(textBoxcolor);
    textBox.setPosition(sf::Vector2f(0,*textBoxPos));

    if(*textBoxPos > 880){
        *textBoxPos = *textBoxPos - 40;
    }
    //fade in the background by fading away black square


    window->clear();
    window->draw(background);
    window->draw(samuraiSprite);
    window->draw(brotherSprite);
    window->draw(textBox);
    window->display();
}
void slideSamurai(sf::RenderWindow * window, std::string * fileName, const sf::IntRect * expression, sf::Clock * smallClock, int * spritePosition, int * textBoxPos){
    sf::Time elapsed1 = smallClock->getElapsedTime();
    sf::RectangleShape background(sf::Vector2f(window->getSize().x,window->getSize().y));
    sf::RectangleShape textBox(sf::Vector2f(window->getSize().x, (window->getSize().y-380)));
    sf::Texture backgroundTexture;
    sf::Texture samuraiTexture;
    sf::Sprite samuraiSprite;
    if (!backgroundTexture.loadFromFile(*fileName))
    {
        std::cout << "Cannot load forest background" << std::endl;
    }
    if (!samuraiTexture.loadFromFile("samurai.png", *expression)){
        std::cout << "Cannot load samurai texture" << std::endl;
    }

    background.setTexture(&backgroundTexture);

    samuraiSprite.setScale(sf::Vector2f(-2.f, 2.f));
    if(*spritePosition < 500){
        *spritePosition = *spritePosition + 50;
    }
    samuraiSprite.setPosition(sf::Vector2f(*spritePosition, 380));
    samuraiSprite.setTexture(samuraiTexture);

    textBox.setFillColor(textBoxcolor);
    textBox.setPosition(sf::Vector2f(0,*textBoxPos));

    if(*textBoxPos > 880){
        *textBoxPos = *textBoxPos - 40;
    }
    //fade in the background by fading away black square


    window->clear();
    window->draw(background);
    window->draw(samuraiSprite);
    window->draw(textBox);
    window->display();
}
void slideSpriteRight(sf::RenderWindow * window, const std::string * back, int * spritePosition, sf::Clock * smallClock, int * textBoxPos, const std::string * string1, const std::string * string2, const sf::IntRect * expression1, const sf::IntRect * expression2){
    sf::Time elapsed1 = smallClock->getElapsedTime();
    sf::RectangleShape background(sf::Vector2f(window->getSize().x,window->getSize().y));
    sf::RectangleShape textBox(sf::Vector2f(window->getSize().x, (window->getSize().y-380)));
    sf::Texture backgroundTexture;
    sf::Texture samuraiTexture;
    sf::Sprite samuraiSprite;
    sf::Texture brotherTexture;
    sf::Sprite brotherSprite;
    if (!backgroundTexture.loadFromFile(*back))
    {
        std::cout << "Cannot load forest background" << std::endl;
    }
    if (!samuraiTexture.loadFromFile(*string1, *expression1)){
        std::cout << "Cannot load samurai texture" << std::endl;
    }
    if (!brotherTexture.loadFromFile(*string2, *expression2)){
        std::cout << "Cannot load texture" << std::endl;
    }

    background.setTexture(&backgroundTexture);

    samuraiSprite.setScale(sf::Vector2f(-2.f, 2.f));
    if(*spritePosition < 500){
        *spritePosition = *spritePosition + 50;
    }
    samuraiSprite.setPosition(sf::Vector2f(500, 380));
    samuraiSprite.setTexture(samuraiTexture);

    brotherSprite.setScale(sf::Vector2f(2.f, 2.f));
    brotherSprite.setPosition(sf::Vector2f((1900-*spritePosition),380));
    brotherSprite.setTexture(brotherTexture);

    textBox.setFillColor(textBoxcolor);
    textBox.setPosition(sf::Vector2f(0,*textBoxPos));

    *textBoxPos = 880;
    //fade in the background by fading away black square


    window->clear();
    window->draw(background);
    window->draw(samuraiSprite);
    window->draw(brotherSprite);
    window->draw(textBox);
    window->display();
}
void displayBlack(sf::RenderWindow * window){
    sf::RectangleShape fader(sf::Vector2f(window->getSize().x,window->getSize().y));
    sf::Color color(0,0,0,255);
    sf::View view1;
    view1 = window->getDefaultView();
    fader.setFillColor(color);
    window->clear();
    window->setView(view1);
    window->draw(fader);
    window->display();
}
void initSelect(){
    if (!selectSound.openFromFile("select1.wav"))
        std::cout << "cant play" << std::endl; // error
}
void playSelect(){
    selectSound.play();
    selectSound.setVolume(60);
}