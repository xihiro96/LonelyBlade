//
// Created by mhendrix on 4/30/18.
//
#include "Scene4.h"
sf::Clock smallClock4;
sf::Uint8 fadeVal4 = 255;
int spritePosition4 = 0;
int textBoxPos4 = 1080;
bool goBar = false;
bool showPresident = false;
bool showDeath = false;
sf::Music chapter4Thud;
sf::Music drinking;
sf::Music stab;

void resetGlobalsScene4(){
    fadeVal4 = 255;
    spritePosition4 = 0;
    textBoxPos4 = 1080;
}

void beforeFinalBoss(sf::RenderWindow * window, int * enterPressed){
    sf::IntRect samuraiFace;
    sf::IntRect strangerFace;
    sf::Vector2f samuraiFacePos;
    sf::Vector2f strangerFacePos;
    std::vector<std::string> v = {"Silas: Bary? Bary are you here?",
                                  "Amy: Baarryyyyyyy? We have bleach for yooouuu!",
                                  "Silas: It's you again! I don't know who you are, but thank you for sending me to Reni. I - ",
                                  "???: Do you have the antidote?",
                                  "Silas: Yes, I - ",
                                  "???: Hand it over. We need to rush to your friend.",
                                  "Silas: What - What are you doing?! Why are you drinking?? Bary needs that to li-",
                                  "???: Ahhh how refreshing...Bary is dead. I killed him.",
                                  "Silas: ...wha -",
                                  "???: Bleach is a hard to obtain substance. Both an antidote and a power enhancer\nto those of the Shadow Samurai Government.",
                                  "Silas: No. You! You killed my brother?! Why would - ",
                                  "???: Your brother was a remarkable samurai. He would have been a wonderful\naddition to the group. But he wanted to stay out. Take care of his brother, he said.\nAnd I can't let such talent stay alive outside the government.",
                                  "Silas: Take care of his brother...take care of me...",
                                  "Amy: You kill people with mops! That should be for floor use only! Silas will kill\nyou easily, right Silas!?",
                                  "Silas: That's right. Prepare to see the next world.",
                                  "???: It's not too late to join the Shadows. I have seen your skills through your\njourney. And mind you, your brother lost to me as well. Are you really willing\nto throw away your life?",
                                  "Silas: You're wrong! I will be glorifying my brother and my family name with your death.",
                                  "???: So be it."};
    //draw all the things

    sf::CircleShape triangle(25, 3);
    sf::RectangleShape background(sf::Vector2f(window->getSize().x,window->getSize().y));
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

    //change face expression with line
    if(*enterPressed < 2) {
        strangerFace = bartenderSmile;
        samuraiFace = samuraiConcern;
        strangerFacePos = brotherPos;
        samuraiFacePos = samuraiSmilePos;
    }else if(*enterPressed == 6 || *enterPressed == 8 || *enterPressed == 10){
        strangerFace = brotherSmile;
        samuraiFace = samuraiYell;
        strangerFacePos = brotherPos;
        samuraiFacePos = samuraiSmilePos;
    }else if(*enterPressed == 7 || *enterPressed == 9 || *enterPressed == 11){
        strangerFace = brotherSmile;
        samuraiFace = samuraiConcern;
        strangerFacePos = brotherPos;
        samuraiFacePos = samuraiSmilePos;
    }else if(*enterPressed == 15 || *enterPressed == 17){
        strangerFace = brotherStern;
        samuraiFace = samuraiConcern;
        strangerFacePos = brotherPos;
        samuraiFacePos = samuraiSmilePos;
    }else if(*enterPressed == 12){
        strangerFace = brotherSmile;
        samuraiFace = samuraiGrimace;
        strangerFacePos = brotherPos;
        samuraiFacePos = samuraiSmilePos;
    }else if(*enterPressed == 13){
        strangerFace = bartenderFrown;
        samuraiFace = samuraiGrimace;
        strangerFacePos = brotherPos;
        samuraiFacePos = samuraiSmilePos;
    }else if(*enterPressed == 14){
        strangerFace = brotherSmile;
        samuraiFace = samuraiExtremeYell;
        strangerFacePos = brotherPos;
        samuraiFacePos = samuraiSmilePos;
    }else if(*enterPressed == 16){
        strangerFace = brotherStern;
        samuraiFace = samuraiExtremeYell;
        strangerFacePos = brotherPos;
        samuraiFacePos = samuraiSmilePos;
    }
    else{
        strangerFace = brotherStern;
        samuraiFace = samuraiSmile;
        strangerFacePos = brotherPos;
        samuraiFacePos = samuraiSmilePos;
    }


    showPresident = *enterPressed > 1 && *enterPressed != 13;

    if (!backgroundTexture.loadFromFile("bar.png"))
    {
        std::cout << "Cannot load town background" << std::endl;
    }
    if (!samuraiTexture.loadFromFile("samurai.png", samuraiFace)){
        std::cout << "Cannot load samurai texture" << std::endl;
    }
    if(showPresident){
        if (!strangerTexture.loadFromFile("niles.png", strangerFace)){
            std::cout << "Cannot load niles texture" << std::endl;
        }
    }else {
        if (!strangerTexture.loadFromFile("bartender.png", strangerFace)) {
            std::cout << "Cannot load niles texture" << std::endl;
        }
    }


    //drinking sound
    if (*enterPressed == 5){
        if (!drinking.openFromFile("drinking.wav")) {
            std::cout << "cant play" << std::endl; // error
        }
        smallClock4.restart();
    }else if(smallClock4.getElapsedTime().asSeconds() >= .1 && smallClock4.getElapsedTime().asSeconds() < .2 && *enterPressed == 6) {
            drinking.play();
            drinking.setVolume(50);
    }

    background.setTexture(&backgroundTexture);
    mop.setTexture(&mopTexture);

    samuraiSprite.setScale(sf::Vector2f(-2.f, 2.f));
    samuraiSprite.setPosition(samuraiFacePos);
    samuraiSprite.setTexture(samuraiTexture);

    strangerSprite.setScale(sf::Vector2f(2.f, 2.f));
    strangerSprite.setPosition(strangerFacePos);
    strangerSprite.setTexture(strangerTexture);


    //nameBoxes
    initNameBox(&nameBox, samuraiNameBoxPos);
    initNameBox(&nameBox2, brotherNameBoxPos);

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
    if(showPresident){
        initNameTag(&strangerText, &font, strangerNamePos, strangerName);
    }else {
        initNameTag(&strangerText, &font, amyNamePos, bartenderName);
    }


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
    if(smallClock4.getElapsedTime().asSeconds() > 0 && smallClock4.getElapsedTime().asSeconds() < .7){
        triangle.move(cursorLow);
    }
    else if(smallClock4.getElapsedTime().asSeconds() >= .7 && smallClock4.getElapsedTime().asSeconds() < 1.4){
        triangle.move(cursorHigh);
    }
    else{
        triangle.move(cursorHigh);
        smallClock4.restart();
    }


    text.setString(string);
    window->clear();
    window->draw(background);
    window->draw(samuraiSprite);
    window->draw(strangerSprite);
    window->draw(textBox);
    window->draw(text);
    window->draw(triangle);
    window->draw(nameBox);
    window->draw(samuraiText);
    window->draw(nameBox2);
    window->draw(strangerText);
    window->display();
}

void beforeBar(sf::RenderWindow * window, int * enterPressed){
    sf::IntRect samuraiFace;
    sf::IntRect strangerFace;
    sf::Vector2f samuraiFacePos;
    sf::Vector2f strangerFacePos;
    std::vector<std::string> v = {"Silas: Made it back in two days time.",
                                  "Amy: Yay! I missed home! I'm so glad to be back.",
                                  "Silas: I'm glad you're back home and here to stay too...",
                                  "Silas: Yes. Now let's go find Bary. You think he's still in the back of the bar?",
                                  "Amy: Maybe. I don't know him so that's the best place to start."};
    //draw all the things

    sf::CircleShape triangle(25, 3);
    sf::RectangleShape background(sf::Vector2f(window->getSize().x,window->getSize().y));
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

    //change face expression with line
    strangerFace = bartenderBigSmile;
    samuraiFace = samuraiCalm;
    strangerFacePos = brotherPos;
    samuraiFacePos = samuraiSmilePos;



    if (!backgroundTexture.loadFromFile("outsideBar.jpg"))
    {
        std::cout << "Cannot load town background" << std::endl;
    }
    if (!samuraiTexture.loadFromFile("samurai.png", samuraiFace)){
        std::cout << "Cannot load samurai texture" << std::endl;
    }
    if (!strangerTexture.loadFromFile("bartender.png", strangerFace)){
        std::cout << "Cannot load niles texture" << std::endl;
    }


    background.setTexture(&backgroundTexture);
    mop.setTexture(&mopTexture);

    samuraiSprite.setScale(sf::Vector2f(-2.f, 2.f));
    samuraiSprite.setPosition(samuraiFacePos);
    samuraiSprite.setTexture(samuraiTexture);

    strangerSprite.setScale(sf::Vector2f(2.f, 2.f));
    strangerSprite.setPosition(strangerFacePos);
    strangerSprite.setTexture(strangerTexture);


    //nameBoxes
    initNameBox(&nameBox, samuraiNameBoxPos);
    initNameBox(&nameBox2, brotherNameBoxPos);

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

    if(*enterPressed == 2){
        text.setStyle(sf::Text::Italic);
    }else{
        text.setStyle(sf::Text::Regular);
    }
    //create samurai nametag
    initNameTag(&samuraiText, &font, samuraiNamePos, samuraiName);
    initNameTag(&strangerText, &font, amyNamePos, bartenderName);


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
    if(smallClock4.getElapsedTime().asSeconds() > 0 && smallClock4.getElapsedTime().asSeconds() < .7){
        triangle.move(cursorLow);
    }
    else if(smallClock4.getElapsedTime().asSeconds() >= .7 && smallClock4.getElapsedTime().asSeconds() < 1.4){
        triangle.move(cursorHigh);
    }
    else{
        triangle.move(cursorHigh);
        smallClock4.restart();
    }


    text.setString(string);
    window->clear();
    window->draw(background);
    window->draw(samuraiSprite);
    window->draw(strangerSprite);
    window->draw(textBox);
    window->draw(text);
    window->draw(triangle);
    window->draw(nameBox);
    window->draw(samuraiText);
    window->draw(nameBox2);
    window->draw(strangerText);
    window->display();
}

void lastWords(sf::RenderWindow * window, int * enterPressed){
    std::vector<std::string> v = {"???: What a shame to waste such talent...",
                                  "Amy: SILAS!!!"};
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

    if (!backgroundTexture.loadFromFile("TakumiDeath.png"))
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
    if(smallClock4.getElapsedTime().asSeconds() > 0 && smallClock4.getElapsedTime().asSeconds() < .7){
        triangle.move(cursorLow);
    }
    else if(smallClock4.getElapsedTime().asSeconds() >= .7 && smallClock4.getElapsedTime().asSeconds() < 1.4){
        triangle.move(cursorHigh);
    }
    else{
        triangle.move(cursorHigh);
        smallClock4.restart();
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

void almostDoneScript(sf::RenderWindow * window, int * enterPressed){
    sf::IntRect samuraiFace;
    sf::IntRect strangerFace;
    sf::Vector2f samuraiFacePos;
    sf::Vector2f strangerFacePos;
    std::vector<std::string> v = {"???: You fight honorably...",
                                  "Silas: Any last words?",
                                  "???: I've got too many."};
    //draw all the things

    sf::CircleShape triangle(25, 3);
    sf::RectangleShape background(sf::Vector2f(window->getSize().x,window->getSize().y));
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

    //change face expression with line
    strangerFace = bartenderSmile;
    samuraiFace = samuraiGrimace;
    strangerFacePos = brotherPos;
    samuraiFacePos = samuraiSmilePos;



    if (!backgroundTexture.loadFromFile("bar.png"))
    {
        std::cout << "Cannot load town background" << std::endl;
    }
    if (!samuraiTexture.loadFromFile("samurai.png", samuraiFace)){
        std::cout << "Cannot load samurai texture" << std::endl;
    }
    if (!strangerTexture.loadFromFile("niles.png", strangerFace)){
        std::cout << "Cannot load niles texture" << std::endl;
    }


    background.setTexture(&backgroundTexture);
    mop.setTexture(&mopTexture);

    samuraiSprite.setScale(sf::Vector2f(-2.f, 2.f));
    samuraiSprite.setPosition(samuraiFacePos);
    samuraiSprite.setTexture(samuraiTexture);

    strangerSprite.setScale(sf::Vector2f(2.f, 2.f));
    strangerSprite.setPosition(strangerFacePos);
    strangerSprite.setTexture(strangerTexture);


    //nameBoxes
    initNameBox(&nameBox, samuraiNameBoxPos);
    initNameBox(&nameBox2, brotherNameBoxPos);

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
    if(smallClock4.getElapsedTime().asSeconds() > 0 && smallClock4.getElapsedTime().asSeconds() < .7){
        triangle.move(cursorLow);
    }
    else if(smallClock4.getElapsedTime().asSeconds() >= .7 && smallClock4.getElapsedTime().asSeconds() < 1.4){
        triangle.move(cursorHigh);
    }
    else{
        triangle.move(cursorHigh);
        smallClock4.restart();
    }


    text.setString(string);
    window->clear();
    window->draw(background);
    window->draw(samuraiSprite);
    window->draw(strangerSprite);
    window->draw(textBox);
    window->draw(text);
    window->draw(triangle);
    window->draw(nameBox);
    window->draw(samuraiText);
    window->draw(nameBox2);
    window->draw(strangerText);
    window->display();
}

GameState runScene4B(sf::RenderWindow * window, sf::Clock * sceneClock){
    int enterPressed = 0;
    initSelect();
    while(window->isOpen()) {
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
        if(!showDeath) {
            if (elapsedMain3.asSeconds() < .1) {
                displayBlack(window);
                resetGlobalsScene4();
            } else if (elapsedMain3.asSeconds() >= .1 && elapsedMain3.asSeconds() < 2.9) {
                string = "bar.png";
                fillBackground(window, &string, &fadeVal4, &smallClock4);
            } else if (elapsedMain3.asSeconds() >= 2.8 && elapsedMain3.asSeconds() < 4.3) {
                string = "samurai.png";
                string1 = "niles.png";
                string2 = "bar.png";
                enterPressed = 0;
                slideInSprites(window, &string2, &spritePosition4, &smallClock4, &textBoxPos4, &string, &string1,
                               &samuraiConcern, &bartenderSmile);
            } else {
                almostDoneScript(window, &enterPressed);
                if (enterPressed > 2) {
                    showDeath = true;
                    sceneClock->restart();
                }
            }
        }
        else{
            if (elapsedMain3.asSeconds() < 2) {
                displayBlack(window);
                if (elapsedMain3.asSeconds() <.1){
                    if (!stab.openFromFile("knife stab.wav"))
                        std::cout << "cant play" << std::endl; // error
                }else if(elapsedMain3.asSeconds() >= .1 && elapsedMain3.asSeconds() < .2){
                    stab.play();
                    stab.setVolume(70);
                }
            }else if (elapsedMain3.asSeconds() >= 2 && elapsedMain3.asSeconds() < 4.9) {
                string = "TakumiDeath.png";
                fillImage(window, &string, &fadeVal4, &smallClock4);
            }else if (elapsedMain3.asSeconds() >= 4.9 && elapsedMain3.asSeconds() < 5.0) {
                enterPressed = 0;
            }else{
                lastWords(window,&enterPressed);
                if (enterPressed > 1) {
                    std::cout << "Returns credits" << std::endl;
                    sceneClock->restart();
                    return credits;
                }
            }

        }
    }
}

GameState runScene4A(sf::RenderWindow * window, sf::Clock * sceneClock){
    int enterPressed = 0;
    initSelect();
    while(window->isOpen()) {
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
        if (!goBar) {
            if (elapsedMain3.asSeconds() < 1) {
                displayBlack(window);
            } else if (elapsedMain3.asSeconds() >= 1 && elapsedMain3.asSeconds() < 4.5) {
                string = "Chapter 4: The Truth";
                introChapterNum(window, &string, &smallClock4);
            } else if (elapsedMain3.asSeconds() >= 4.5 && elapsedMain3.asSeconds() < 7.3) {
                string = "outsideBar.jpg";
                fillBackground(window, &string, &fadeVal4, &smallClock4);
            } else if (elapsedMain3.asSeconds() >= 7.3 && elapsedMain3.asSeconds() < 8.8) {
                string = "samurai.png";
                string1 = "bartender.png";
                string2 = "outsideBar.jpg";
                enterPressed = 0;
                slideInSprites(window, &string2, &spritePosition4, &smallClock4, &textBoxPos4, &string, &string1,
                               &samuraiCalm, &bartenderBigSmile);
            } else {
                beforeBar(window, &enterPressed);
                if (enterPressed > 4) {
                    goBar = true;
                    sceneClock->restart();
                }
            }
            //play thud
            if (elapsedMain3.asSeconds() <.1){
                if (!chapter4Thud.openFromFile("thud1.wav"))
                    std::cout << "cant play" << std::endl; // error
            }else if(elapsedMain3.asSeconds() >= .7 && elapsedMain3.asSeconds() < .8){
                chapter4Thud.play();
            }
        } else if (goBar) {
            if (elapsedMain3.asSeconds() < .1) {
                smallClock4.restart();
                spritePosition4 = 0;
                textBoxPos4 = 1080;
                fadeVal4 = 255;
            } else if (elapsedMain3.asSeconds() >= .1 && elapsedMain3.asSeconds() < 2.8) {
                string = "bar.png";
                fillBackground(window, &string, &fadeVal4, &smallClock4);
            } else if (elapsedMain3.asSeconds() >= 2.8 && elapsedMain3.asSeconds() < 4.3) {
                string = "samurai.png";
                string1 = "bartender.png";
                string2 = "bar.png";
                enterPressed = 0;
                slideInSprites(window, &string2, &spritePosition4, &smallClock4, &textBoxPos4, &string, &string1,
                               &samuraiCalm, &bartenderSmile);
            } else {
                beforeFinalBoss(window, &enterPressed);
            }
        }
        if (enterPressed > 17) {
            sceneClock->restart();
            return battle4;
        }
    }
}
