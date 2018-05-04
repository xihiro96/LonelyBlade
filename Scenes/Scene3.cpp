//
// Created by mhendrix on 4/28/18.
//
#include "Scene3.h"
sf::Clock smallClock3;
sf::Uint8 fadeVal3 = 255;
int spritePosition3 = 0;
int textBoxPos3 = 1080;
bool enterIslandMan = false;
bool nextScene3 = false;
sf::Music chapter3Thud;
sf::Music oceanSound;

void resetGlobalsScene3(){
    fadeVal3 = 255;
    spritePosition3 = 0;
    textBoxPos3 = 1080;
}

void enterIslandScript(sf::RenderWindow * window, int * enterPressed){
    sf::IntRect samuraiFace;
    sf::IntRect strangerFace;
    sf::Vector2f samuraiFacePos;
    sf::Vector2f strangerFacePos;
    //sf::View view1 = window->getDefaultView();
    std::vector<std::string> v = {"Silas: This place looks...",
                                  "Amy: Gross! I can't believe we came all the way here for this!",
                                  "Silas: Did you expect this to be a luxury vacation...",
                                  "Silas: I was going to say abandoned, but gross works too I guess.",
                                  "Amy: This is really where that guy told you to go?",
                                  "Silas: Several days of traveling with this annoying as hell girl. Over and over again\nshe asked where we were going, why we were going there and who that guy was.",
                                  "Silas: YES. I already told you that a million times.",
                                  "Silas: I'm so glad I never had a sister.",
                                  "Amy: I just don't get it though. There's nothing here. And your friend seemed fine\nwhen we left him.",
                                  "Silas: Why am I trusting a total stranger anyway? What if that guy is just sending\nme into a trap? There's nothing here..."};
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
    if(*enterPressed == 0 || *enterPressed == 8 || *enterPressed == 9){
        strangerFace = bartenderFrown;
        samuraiFace = samuraiConcern;
        strangerFacePos = brotherPos;
        samuraiFacePos = samuraiSmilePos;
    }else if (*enterPressed == 2 || *enterPressed == 5 || *enterPressed == 7){
        strangerFace = bartenderUpset;
        samuraiFace = samuraiGrimace;
        strangerFacePos = brotherPos;
        samuraiFacePos = samuraiSmilePos;
    }
    else{
        strangerFace = bartenderUpset;
        samuraiFace = samuraiConcern;
        strangerFacePos = brotherPos;
        samuraiFacePos = samuraiSmilePos;
    }






    if (!backgroundTexture.loadFromFile("island.png"))
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

    if (*enterPressed == 2 || *enterPressed == 5 || *enterPressed == 7 || *enterPressed == 9){
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
    if(smallClock3.getElapsedTime().asSeconds() > 0 && smallClock3.getElapsedTime().asSeconds() < .7){
        triangle.move(cursorLow);
    }
    else if(smallClock3.getElapsedTime().asSeconds() >= .7 && smallClock3.getElapsedTime().asSeconds() < 1.4){
        triangle.move(cursorHigh);
    }
    else{
        triangle.move(cursorHigh);
        smallClock3.restart();
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

void enterDangerScript(sf::RenderWindow * window, int * enterPressed){
    sf::IntRect samuraiFace;
    sf::IntRect strangerFace;
    sf::Vector2f samuraiFacePos;
    sf::Vector2f strangerFacePos;
    //sf::View view1 = window->getDefaultView();
    std::vector<std::string> v = {"???: Who dares enter my city without permission!?",
                                  "Silas: Huh? Whoa - we mean no harm we -",
                                  "???: Anyone who enters without permission means harm! Prepare to die!"};
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
        samuraiFace = samuraiConcern;
        strangerFacePos = brotherPos;
        samuraiFacePos = samuraiSmilePos;







    if (!backgroundTexture.loadFromFile("island.png"))
    {
        std::cout << "Cannot load town background" << std::endl;
    }
    if (!samuraiTexture.loadFromFile("samurai.png", samuraiFace)){
        std::cout << "Cannot load samurai texture" << std::endl;
    }
    if (!strangerTexture.loadFromFile("islandMan.png", strangerFace)){
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
    if(smallClock3.getElapsedTime().asSeconds() > 0 && smallClock3.getElapsedTime().asSeconds() < .7){
        triangle.move(cursorLow);
    }
    else if(smallClock3.getElapsedTime().asSeconds() >= .7 && smallClock3.getElapsedTime().asSeconds() < 1.4){
        triangle.move(cursorHigh);
    }
    else{
        triangle.move(cursorHigh);
        smallClock3.restart();
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

void postIslandFight(sf::RenderWindow * window, int * enterPressed){
    sf::IntRect samuraiFace;
    sf::IntRect strangerFace;
    sf::Vector2f samuraiFacePos;
    sf::Vector2f strangerFacePos;
    std::vector<std::string> v = {"???: *panting* Who are you people?",
                                  "Silas: You could have just asked us that in the first place. My name is Silas, I came\nhere searching for answers to avenge my brother Xander's death.",
                                  "Kato: Well Silas. You have earned my respect. My name is Kato. How may I help you?",
                                  "Silas: I don't know if you can, but...do you happen to know what weapon this is? It's\nwhat was used to kill my brother, and what has recently wounded a...friend of mine.",
                                  "Silas: If I can even call that stranger a friend.",
                                  "Kato: Oh no. This is the weapon of the Shadow Samurai Government.",
                                  "Silas: Them? I thought they were a myth. An underground society of samurais\ngone rogue...dangerous and unruly. They love disorder and chaos.",
                                  "Silas: Pretty stupid and ironic for a group of disorder and chaos to form their\nown government but whatever.",
                                  "Silas: I thought they were fake. Does this mean this weapon - ",
                                  "Kato: Yes. It's a mop.",
                                  "Amy: You're kidding. Your brother died from a mop?",
                                  "Silas: Will you shut up.",
                                  "Amy: Sorry sorry...",
                                  "Kato: This does mean that your friend struck by one needs an antidote. Luckily, I have some.",
                                  "Silas: Bleach...what is this?",
                                  "Kato: Make him drink it. He's got five days from the inflicted wound until he dies.",
                                  "Silas: It's been about two days of travel...if we head back now, we can save him.",
                                  "Silas: Alright. Amy, let's head back. Thank you for your help Kato.",
                                  "Silas: I guess that stranger's advice worked out after all. Perhaps I can trust him.",
                                  "Kato: Anytime."};
    //draw all the things

    sf::CircleShape triangle(25, 3);
    sf::RectangleShape background(sf::Vector2f(window->getSize().x,window->getSize().y));
    sf::RectangleShape black(sf::Vector2f(window->getSize().x,window->getSize().y));
    sf::RectangleShape mop(sf::Vector2f(window->getSize().x, window->getSize().y));
    sf::RectangleShape bleach(sf::Vector2f(1300, 800));
    sf::RectangleShape textBox(sf::Vector2f(window->getSize().x, (window->getSize().y-380)));
    sf::RectangleShape nameBox(nameBoxSize);
    sf::RectangleShape nameBox2(nameBoxSize);
    sf::Texture backgroundTexture;
    sf::Texture samuraiTexture;
    sf::Texture mopTexture;
    sf::Texture bleachTexture;
    sf::Sprite samuraiSprite;
    sf::Texture strangerTexture;
    sf::Sprite strangerSprite;

    //change face expression with line
    if(*enterPressed == 0 || *enterPressed == 1){
        strangerFace = bartenderUpset;
        samuraiFace = samuraiCalm;
        strangerFacePos = brotherPos;
        samuraiFacePos = samuraiSmilePos;
    }else if(*enterPressed == 3 || *enterPressed == 4 || *enterPressed == 2){
        strangerFace = bartenderBigSmile;
        samuraiFace = samuraiConcern;
        strangerFacePos = brotherPos;
        samuraiFacePos = samuraiSmilePos;
    }else if(*enterPressed == 7){
        strangerFace = bartenderUpset;
        samuraiFace = samuraiGrimace;
        strangerFacePos = brotherPos;
        samuraiFacePos = samuraiSmilePos;
    }
    else{
        strangerFace = bartenderUpset;
        samuraiFace = samuraiConcern;
        strangerFacePos = brotherPos;
        samuraiFacePos = samuraiSmilePos;
    }


    if (!backgroundTexture.loadFromFile("island.png"))
    {
        std::cout << "Cannot load town background" << std::endl;
    }
    if (!samuraiTexture.loadFromFile("samurai.png", samuraiFace)){
        std::cout << "Cannot load samurai texture" << std::endl;
    }
    if(*enterPressed >= 10 && *enterPressed <=12){
        if (!strangerTexture.loadFromFile("bartender.png", strangerFace)){
            std::cout << "Cannot load niles texture" << std::endl;
        }
    }else {
        if (!strangerTexture.loadFromFile("islandMan.png", strangerFace)) {
            std::cout << "Cannot load niles texture" << std::endl;
        }
    }


    if (!mopTexture.loadFromFile("mop.png")){
        std::cout << "Can't load mop" << std::endl;
    }if (!bleachTexture.loadFromFile("bleach.jpeg")){
        std::cout << "Can't load mop" << std::endl;
    }


    background.setTexture(&backgroundTexture);
    mop.setTexture(&mopTexture);
    bleach.setTexture(&bleachTexture);
    bleach.move(sf::Vector2f(300,0));
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
    if(*enterPressed < 2) {
        initNameTag(&strangerText, &font, strangerNamePos, strangerName);
    }else if(*enterPressed == 10 || *enterPressed == 12 || *enterPressed == 11){
        initNameTag(&strangerText, &font, amyNamePos, bartenderName);
    }else{
        initNameTag(&strangerText, &font, baryNamePos, islandManName);
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

    black.setFillColor(sf::Color(0,0,0,255));
    //triangle
    triangle.setFillColor(cursorColor);
    triangle.setScale(cursorFlip);
    if(smallClock3.getElapsedTime().asSeconds() > 0 && smallClock3.getElapsedTime().asSeconds() < .7){
        triangle.move(cursorLow);
    }
    else if(smallClock3.getElapsedTime().asSeconds() >= .7 && smallClock3.getElapsedTime().asSeconds() < 1.4){
        triangle.move(cursorHigh);
    }
    else{
        triangle.move(cursorHigh);
        smallClock3.restart();
    }

    if(*enterPressed == 4 || *enterPressed == 6 || *enterPressed == 7 || *enterPressed == 16 || *enterPressed == 18){
        text.setStyle(sf::Text::Italic);
    }else{
        text.setStyle(sf::Text::Regular);
    }


    text.setString(string);
    window->clear();
    if(*enterPressed < 3 || *enterPressed > 5){
        window->draw(background);
        window->draw(samuraiSprite);
        window->draw(strangerSprite);
    }
    if(*enterPressed >= 3 && *enterPressed <= 5){
        window->draw(mop);
    }
    if(*enterPressed >= 14 && *enterPressed <= 15){
        window->draw(black);
        window->draw(bleach);

    }

    window->draw(textBox);
    window->draw(text);
    window->draw(triangle);

    if((*enterPressed < 3 || *enterPressed > 5) || (*enterPressed < 14 || *enterPressed > 15)){
        window->draw(nameBox);
        window->draw(samuraiText);
        window->draw(nameBox);
        window->draw(samuraiText);
        window->draw(nameBox2);
        window->draw(strangerText);

    }
    window->display();
}

GameState runScene3B(sf::RenderWindow * window, sf::Clock * sceneClock){
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
        if (elapsedMain3.asSeconds() < .1) {
            displayBlack(window);
            resetGlobalsScene3();
        } else if (elapsedMain3.asSeconds() >= .1 && elapsedMain3.asSeconds() < 2.9) {
            string = "island.png";
            fillBackground(window, &string, &fadeVal3, &smallClock3);
        } else if (elapsedMain3.asSeconds() >= 2.9 && elapsedMain3.asSeconds() < 4.4) {
            string = "samurai.png";
            string1 = "islandMan.png";
            string2 = "island.png";
            enterPressed = 0;
            slideInSprites(window, &string2, &spritePosition3, &smallClock3, &textBoxPos3, &string, &string1,
                           &samuraiConcern, &bartenderUpset);
        } else {
            postIslandFight(window, &enterPressed);
        }
        if (enterPressed > 19) {
            oceanSound.stop();
            sceneClock->restart();
            return scene4A;
        }
        //play ocean
        if (elapsedMain3.asSeconds() <.1){
            if (!oceanSound.openFromFile("ocean.wav"))
                std::cout << "cant play" << std::endl; // error
        }else if(elapsedMain3.asSeconds() >= .1 && elapsedMain3.asSeconds() < .2){
            oceanSound.play();
            oceanSound.setVolume(10);
        }

    }
}

GameState runScene3A(sf::RenderWindow * window, sf::Clock * sceneClock){
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
        if (!enterIslandMan) {
            if (elapsedMain3.asSeconds() < 1) {
                displayBlack(window);
            } else if (elapsedMain3.asSeconds() >= 1 && elapsedMain3.asSeconds() < 4.5) {
                string = "Chapter 3: The Cure";
                introChapterNum(window, &string, &smallClock3);
            } else if (elapsedMain3.asSeconds() >= 4.5 && elapsedMain3.asSeconds() < 7.3) {
                string = "island.png";
                fillBackground(window, &string, &fadeVal3, &smallClock3);
            } else if (elapsedMain3.asSeconds() >= 7.3 && elapsedMain3.asSeconds() < 8.8) {
                string = "samurai.png";
                string1 = "bartender.png";
                string2 = "island.png";
                enterPressed = 0;
                slideInSprites(window, &string2, &spritePosition3, &smallClock3, &textBoxPos3, &string, &string1,
                               &samuraiConcern, &bartenderUpset);
            } else {
                enterIslandScript(window, &enterPressed);
                if (enterPressed > 9) {
                    enterIslandMan = true;
                    sceneClock->restart();
                }
            }
            //play thud
            if (elapsedMain3.asSeconds() <.1){
                if (!chapter3Thud.openFromFile("thud1.wav"))
                    std::cout << "cant play" << std::endl; // error
            }else if(elapsedMain3.asSeconds() >= .7 && elapsedMain3.asSeconds() < .8){
                chapter3Thud.play();
            }
            if (elapsedMain3.asSeconds() <.1){
                if (!oceanSound.openFromFile("ocean.wav"))
                    std::cout << "cant play" << std::endl; // error
            }


        } else if (enterIslandMan) {
            if (elapsedMain3.asSeconds() < .1) {
                smallClock3.restart();
                spritePosition3 = 0;
            } else if (elapsedMain3.asSeconds() >= .1 && elapsedMain3.asSeconds() < 1.4) {
                string = "island.png";
                string1 = "samurai.png";
                string2 = "islandMan.png";
                slideSpriteRight(window, &string, &spritePosition3, &smallClock3, &textBoxPos3, &string1, &string2,
                                 &samuraiConcern, &bartenderSmile);
            } else if (elapsedMain3.asSeconds() >= 1.4 && elapsedMain3.asSeconds() < 1.5) {
                enterPressed = 0;
            } else {
                enterDangerScript(window, &enterPressed);
                if (enterPressed > 2) {
                    nextScene3 = true;
                }
            }
        }
        //play ocean
        if(elapsedMain3.asSeconds() >= 4.5 && elapsedMain3.asSeconds() < 4.6){
            oceanSound.play();
            oceanSound.setVolume(10);
        }

        if (elapsedMain3.asSeconds() >= 1.5 && nextScene3 && enterIslandMan) {
            sceneClock->restart();
            oceanSound.stop();
            return battle3;
        }
    }
}

