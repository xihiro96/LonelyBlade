//
// Created by mhendrix on 5/1/18.
//
#include "Credits.h"
bool postCredits = false;
bool continued = false;
sf::Clock smallClock5;
sf::Uint8 fadeVal5 = 255;
sf::Music creditThud;
void showCredits(sf::RenderWindow * window){
    sf::Text headlineText;
    sf::Text nameText1;
    sf::Text nameText2;
    sf::Text nameText3;
    sf::Text nameText4;
    sf::Text nameText5;
    sf::Font headlineFont;
    sf::Font nameFont;
    sf::RectangleShape background(sf::Vector2f(window->getSize().x,window->getSize().y));
    //load font
    if (!headlineFont.loadFromFile("made-in-china.regular.ttf"))
    {
        std::cout << "No font loaded" <<std::endl;
    }if (!nameFont.loadFromFile("HomePlanetBB-Bold.ttf"))
    {
        std::cout << "No font loaded" <<std::endl;
    }

    sf::Color backgroundColor(80,14,14,255);
    background.setFillColor(backgroundColor);


    headlineText.setFont(headlineFont);
    headlineText.setString("Lonely Blade IV");
    headlineText.setCharacterSize(175); // in pixels, not points!
    sf::Color colorHead(255,255,255,255);
    headlineText.setColor(colorHead);
    headlineText.setPosition(350,2);
    //Justin

    sf::Color color(224,189,15,255);
    nameText1.setFont(nameFont);
    nameText1.setString("Justin Cheung");
    nameText1.setCharacterSize(60); // in pixels, not points!
    nameText1.setPosition(770, 325);
    nameText1.setColor(color);

    //Augustine
    nameText2.setFont(nameFont);
    nameText2.setString("Augustine Ho");
    nameText2.setCharacterSize(60); // in pixels, not points!
    nameText2.setPosition(785, 420);
    nameText2.setColor(color);

    //Marites
    nameText3.setFont(nameFont);
    nameText3.setString("Marites Hendrix");
    nameText3.setCharacterSize(60); // in pixels, not points!
    nameText3.setPosition(750, 515);
    nameText3.setColor(color);

    //Kevin
    nameText4.setFont(nameFont);
    nameText4.setString("Kevin Jones");
    nameText4.setCharacterSize(60); // in pixels, not points!
    nameText4.setPosition(790, 610);
    nameText4.setColor(color);

    //Gio
    nameText5.setFont(nameFont);
    nameText5.setString("Gio Panlerkitsakul");
    nameText5.setCharacterSize(60); // in pixels, not points!
    nameText5.setPosition(730, 705);
    nameText5.setColor(color);

    window->clear();
    window->draw(background);
    window->draw(headlineText);
    window->draw(nameText1);
    window->draw(nameText2);
    window->draw(nameText3);
    window->draw(nameText4);
    window->draw(nameText5);

    window->display();
}

void secretEnding(sf::RenderWindow * window, int * enterPressed){
    std::vector<std::string> v = {"???: Silas? Are you awake?",
                                  "Silas: Agh...Where am I?"};
    //draw all the things

    sf::CircleShape triangle(25, 3);
    sf::RectangleShape background(sf::Vector2f(1300, 800));
    sf::RectangleShape mop(sf::Vector2f(window->getSize().x, window->getSize().y));
    sf::RectangleShape textBox(sf::Vector2f(window->getSize().x, (window->getSize().y-380)));
    sf::RectangleShape nameBox(nameBoxSize);
    sf::RectangleShape nameBox2(nameBoxSize);
    sf::Texture backgroundTexture;
    sf::Texture samuraiTexture;
    sf::Texture mopTexture;
    sf::Sprite samuraiSprite;
    sf::Texture strangerTexture;
    sf::Sprite strangerSprite;

    if (!backgroundTexture.loadFromFile("openeyes1.png"))
    {
        std::cout << "Cannot load background" << std::endl;
    }


    background.setTexture(&backgroundTexture);


    //TextBox
    textBox.setFillColor(textBoxcolor);
    textBox.setPosition(sf::Vector2f(0,880));
    //you've drawn all the things, now make it talk

    sf::Text text;
    sf::Text samuraiText;
    sf::Text strangerText;
    sf::Font font;
    //load font
    if (!font.loadFromFile("HomePlanetBB-Bold.ttf"))
    {
        std::cout << "No font loaded" <<std::endl;
    }
    //create samurai nametag
    initNameTag(&samuraiText, &font, samuraiNamePos, samuraiName);
    initNameTag(&strangerText, &font, strangerNamePos, strangerName);


    //intiate talking
    std::string string;
    createScript(&text, &font, string);


    if(*enterPressed < v.size()){
        string = v[*enterPressed];
    }
    else{
        std::cout << "Out of scope of script" << std::endl;
    }
    //be sure to add error case to going out of scope

    //triangle
    triangle.setFillColor(cursorColor);
    triangle.setScale(cursorFlip);
    if(smallClock5.getElapsedTime().asSeconds() > 0 && smallClock5.getElapsedTime().asSeconds() < .7){
        triangle.move(cursorLow);
    }
    else if(smallClock5.getElapsedTime().asSeconds() >= .7 && smallClock5.getElapsedTime().asSeconds() < 1.4){
        triangle.move(cursorHigh);
    }
    else{
        triangle.move(cursorHigh);
        smallClock5.restart();
    }


    background.move(sf::Vector2f(300,0));
    text.setString(string);
    window->clear();
    window->draw(background);
    window->draw(textBox);
    window->draw(text);
    window->draw(triangle);
    window->display();
}

GameState roleCredits(sf::RenderWindow * window, sf::Clock * sceneClock) {
    int enterPressed = 0;
    initSelect();
    while (window->isOpen()) {
        sf::Event event;
// while there are pending events...
        while (window->pollEvent(event)) //two sf::Events cannot happen at the same time, game will crash
        {
            // check the type of the event...
            switch (event.type) {
                // window closed
                case sf::Event::Closed: //if user closes game in any way shape or for
                    window->close();
                    break;

                    // key pressed
                case sf::Event::LostFocus: //user clicks out of the game window
                    //pause game;
                    break;
                case sf::Event::GainedFocus: //user goes back to game window
                    //unpause game;
                    break;
                case sf::Event::KeyReleased:
                    switch (event.key.code) {
                        case sf::Keyboard::Escape:
                            window->close();
                            break;
                        case sf::Keyboard::Return:
                            //incrementEnter(enterPressed);
                            enterPressed++;
                            playSelect();
                            //std::cout << *enterPressed << std::endl;
                            break;

                    }


            }

        }

        std::string string, string1, string2;
        sf::Time elapsedMain3 = sceneClock->getElapsedTime();
        if(!postCredits) {
            if (elapsedMain3.asSeconds() < 2) {
                displayBlack(window);
            } else if (elapsedMain3.asSeconds() >= .1) {
                showCredits(window);
                if (enterPressed > 0) {
                    sceneClock->restart();
                    postCredits = true;
                }
            }
        }else if (postCredits && !continued){
            if (elapsedMain3.asSeconds() < 2) {
                displayBlack(window);
                smallClock5.restart();
            }else if (elapsedMain3.asSeconds() >= 2 && elapsedMain3.asSeconds() < 4.9) {
                string = "openeyes1.png";
                fillImage(window, &string, &fadeVal5, &smallClock5);
            }else if (elapsedMain3.asSeconds() >= 4.9 && elapsedMain3.asSeconds() < 5.0) {
                enterPressed = 0;
            }
            else{
                secretEnding(window, &enterPressed);
                if (enterPressed > 1) {
                    sceneClock->restart();
                    continued = true;
                }
            }
        }else if(continued){
            if (elapsedMain3.asSeconds() < 1) {
                displayBlack(window);
                smallClock5.restart();
            }else if (elapsedMain3.asSeconds() >= 1 && elapsedMain3.asSeconds() < 4.5) {
                string = "TO BE CONTINUED";
                introChapterNum(window, &string, &smallClock5);
            }else{
                std::cout << "This ran" << std::endl;
                return mainMenu;
            }
            //play thud
            if (elapsedMain3.asSeconds() <.1){
                if (!creditThud.openFromFile("thud1.wav"))
                    std::cout << "cant play" << std::endl; // error
            }else if(elapsedMain3.asSeconds() >= 1.7 && elapsedMain3.asSeconds() < 1.8){
                creditThud.play();
            }

        }

    }
}
