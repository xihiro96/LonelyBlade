//
// Created by mhendrix on 4/13/18.
//
#include "Scene1.h"
sf::Uint8 fadeVal = 0;
sf::Clock smallClock;
bool fadeOut = false;
bool holdText = false;
int spritePosition = 0;
int textBoxPos = 1080;
bool beforeDeath = true;
bool endDeath = false;
bool leave = false;
bool sceneDone = false;
int xVal = 1920;
int yVal = 1080;
sf::Music forestMusic;
sf::Music chapter1Thud;
sf::Music swordsClashing;
sf::Music crowdMurmur;

void resetFade(){
    fadeVal = 0;
    fadeOut = false;
    holdText = false;
}

void resetGlobalsScene1(){
    fadeVal = 255;
    spritePosition = 0;
    textBoxPos = 1080;
    fadeOut = false;
    holdText = false;
    xVal = 1920;
    yVal = 1080;
}


void beginScript(sf::RenderWindow * window, int * enterPressed){
    sf::IntRect samuraiFace;
    sf::IntRect brotherFace;
    sf::Vector2f samuraiFacePos;
    sf::Vector2f brotherFacePos;
    std::vector<std::string> v = {"Xander: Now that you've come of age, it is time for you to learn to hunt.",
                                  "Silas: Awesome! But...I already know how to hunt. We've always done it together, right?",
                                  "Xander: Yes, but you'll soon need to learn to handle your own battles as well. I may not always\nbe around -",
                                  "Silas: What are you talking about - you're indestructible!",
                                  "Xander: Nothing that lives and breathes is indestructible. That's why we have our family line.\nWhen our father dies, the title of Chieftain will be passed to me. And if anything happens to me,\nthe title will be passed to you.",
                                  "Silas: But, what are you talking about?? You're indestructible!!",
                                  "Xander: (He's still a kid...) *Sigh* Sure, alright. But for now, you're old enough where I don't need\nto hold your hand every time we go hunting. You see those pigs?",
                                  "Silas: Yea I think I do... I see them!",
                                  "Xander: If you do just as I told you, then you should be able to supply the village with tonight's dinner."};
    //draw all the things

    sf::CircleShape triangle(25, 3);
    sf::RectangleShape background(sf::Vector2f(window->getSize().x,window->getSize().y));
    sf::RectangleShape textBox(sf::Vector2f(window->getSize().x, (window->getSize().y-380)));
    sf::RectangleShape nameBox(nameBoxSize);
    sf::RectangleShape nameBox2(nameBoxSize);
    sf::Texture backgroundTexture;
    sf::Texture samuraiTexture;
    sf::Sprite samuraiSprite;
    sf::Texture brotherTexture;
    sf::Sprite brotherSprite;

    //change face expression with line
    if (*enterPressed == 3){
        brotherFace = brotherSmile;
        samuraiFace = samuraiConcern;
        brotherFacePos = brotherPos;
        samuraiFacePos = samuraiOtherPos;
    }else if(*enterPressed == 4){
        brotherFace = brotherStern;
        samuraiFace = samuraiConcern;
        brotherFacePos = brotherPos;
        samuraiFacePos = samuraiOtherPos;
    }else if(*enterPressed == 5){
        brotherFace = brotherStern;
        samuraiFace = samuraiConcern;
        brotherFacePos = brotherPos;
        samuraiFacePos = samuraiOtherPos;
    }else if(*enterPressed == 6){
        brotherFace = brotherAnnoyed;
        samuraiFace = samuraiConcern;
        brotherFacePos = brotherPos;
        samuraiFacePos = samuraiOtherPos;
    }else{
        brotherFace = brotherSmile;
        samuraiFace = samuraiSmile;
        brotherFacePos = brotherPos;
        samuraiFacePos = samuraiSmilePos;
    }


    if (!backgroundTexture.loadFromFile("forest.jpeg"))
    {
        std::cout << "Cannot load forest background" << std::endl;
    }
    if (!samuraiTexture.loadFromFile("samurai.png", samuraiFace)){
        std::cout << "Cannot load samurai texture" << std::endl;
    }
    if (!brotherTexture.loadFromFile("brother.png", brotherFace)){
        std::cout << "Cannot load samurai texture" << std::endl;
    }



    background.setTexture(&backgroundTexture);

    samuraiSprite.setScale(sf::Vector2f(-2.f, 2.f));
    samuraiSprite.setPosition(samuraiFacePos);
    samuraiSprite.setTexture(samuraiTexture);

    brotherSprite.setScale(sf::Vector2f(2.f, 2.f));
    brotherSprite.setPosition(brotherFacePos);
    brotherSprite.setTexture(brotherTexture);


    //nameBoxes
    initNameBox(&nameBox, samuraiNameBoxPos);
    initNameBox(&nameBox2, brotherNameBoxPos);

    //TextBox
    textBox.setFillColor(textBoxcolor);
    textBox.setPosition(sf::Vector2f(0,880));
    //you've drawn all the things, now make it talk




    sf::Text text;
    sf::Text samuraiText;
    sf::Text brotherText;
    sf::Font font;
    //load font
    if (!font.loadFromFile("HomePlanetBB-Bold.ttf"))
    {
        std::cout << "No font loaded" <<std::endl;
    }

    //create samurai nametag
    initNameTag(&samuraiText, &font, samuraiNamePos, samuraiName);
    initNameTag(&brotherText, &font, brotherNamePos, brotherName);

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
    if(smallClock.getElapsedTime().asSeconds() > 0 && smallClock.getElapsedTime().asSeconds() < .7){
        triangle.move(cursorLow);
    }
    else if(smallClock.getElapsedTime().asSeconds() >= .7 && smallClock.getElapsedTime().asSeconds() < 1.4){
        triangle.move(cursorHigh);
    }
    else{
        triangle.move(cursorHigh);
        smallClock.restart();
    }

    text.setString(string);
    window->clear();
    window->draw(background);
    window->draw(samuraiSprite);
    window->draw(brotherSprite);
    window->draw(textBox);
    window->draw(text);
    window->draw(triangle);
    window->draw(nameBox);
    window->draw(samuraiText);
    window->draw(nameBox2);
    window->draw(brotherText);
    window->display();

}


void playBlackCoatFight(sf::RenderWindow * window){
    sf::RectangleShape background(sf::Vector2f(window->getSize().x,window->getSize().y));
    sf::Texture backgroundTexture;

    sf::Texture blackCoatTexture;
    sf::Sprite blackCoatSprite;

    //view
    sf::View view1;
    view1.setCenter(sf::Vector2f(1100, 550));

    if (smallClock.getElapsedTime().asMilliseconds() > 20 && xVal > 1400) {
        xVal = xVal - 13;
        yVal = yVal - 7;
        view1.setSize(sf::Vector2f(xVal, yVal));
        smallClock.restart();
    } else {
        //view1.setSize(sf::Vector2f(1634, 926));
        view1.setSize(sf::Vector2f(1400, 800));

    }
    //view1.setSize(sf::Vector2f(1400, 800));
    if (!backgroundTexture.loadFromFile("deathForest.jpg"))
    {
        std::cout << "Cannot load forest background" << std::endl;
    }
    if (!blackCoatTexture.loadFromFile("BlackCoat.png")){
        std::cout << "Cannot load texture" << std::endl;
    }


    blackCoatSprite.setScale(sf::Vector2f(1.2f,1.2f));
    blackCoatSprite.setTexture(blackCoatTexture);
    blackCoatSprite.move(sf::Vector2f(800,100));

    background.setTexture(&backgroundTexture);
    window->clear();
    window->setView(view1);
    window->draw(background);
    window->draw(blackCoatSprite);
    window->display();
}

void playBrotherFight(sf::RenderWindow * window){
    sf::RectangleShape background(sf::Vector2f(window->getSize().x,window->getSize().y));
    sf::Texture backgroundTexture;

    sf::Texture brotherTexture;
    sf::Sprite brotherSprite;


    //view
    sf::View view1;
    view1.setCenter(sf::Vector2f(1000, 550));

    if (smallClock.getElapsedTime().asMilliseconds() > 10 && xVal > 1634) {
        xVal = xVal - 13;
        yVal = yVal - 7;
        view1.setSize(sf::Vector2f(xVal, yVal));
        smallClock.restart();
    } else {
        view1.setSize(sf::Vector2f(1634, 926));

    }
    //view1.setSize(sf::Vector2f(1920, 1080));
    if (!backgroundTexture.loadFromFile("deathForest.jpg"))
    {
        std::cout << "Cannot load forest background" << std::endl;
    }
    if (!brotherTexture.loadFromFile("Ryoma_Damaged.png")){
        std::cout << "Cannot load texture" << std::endl;
    }


    brotherSprite.setScale(sf::Vector2f(0.7f,0.7f));
    brotherSprite.setTexture(brotherTexture);
    brotherSprite.move(sf::Vector2f(500,0));

    background.setTexture(&backgroundTexture);
    window->clear();
    window->setView(view1);
    window->draw(background);
    window->draw(brotherSprite);
    window->display();
}

void beginScript1B(sf::RenderWindow * window, int * enterPressed){
    sf::IntRect samuraiFace;
    sf::Vector2f samuraiFacePos;
    std::vector<std::string> v = {"Silas: That was nothing like fighting with you. Easy! I bet we're going to have a feast tonight\nright, brother?",
                                  "...Brother?"};
    //draw all the things

    sf::CircleShape triangle(25, 3);
    sf::RectangleShape background(sf::Vector2f(window->getSize().x,window->getSize().y));
    sf::RectangleShape textBox(sf::Vector2f(window->getSize().x, (window->getSize().y-380)));
    sf::RectangleShape nameBox(nameBoxSize);
    sf::RectangleShape nameBox2(nameBoxSize);
    sf::Texture backgroundTexture;
    sf::Texture samuraiTexture;
    sf::Sprite samuraiSprite;

    //change face expression with line
    if (*enterPressed == 1){
        samuraiFace = samuraiConcern;
        samuraiFacePos = samuraiOtherPos;
    }
    else{
        samuraiFace = samuraiSmile;
        samuraiFacePos = samuraiSmilePos;
    }

    if (!backgroundTexture.loadFromFile("forest.jpeg"))
    {
        std::cout << "Cannot load forest background" << std::endl;
    }
    if (!samuraiTexture.loadFromFile("samurai.png", samuraiFace)){
        std::cout << "Cannot load samurai texture" << std::endl;
    }



    background.setTexture(&backgroundTexture);

    samuraiSprite.setScale(sf::Vector2f(-2.f, 2.f));
    samuraiSprite.setPosition(samuraiFacePos);
    samuraiSprite.setTexture(samuraiTexture);


    //nameBoxes
    initNameBox(&nameBox, samuraiNameBoxPos);

    //TextBox
    textBox.setFillColor(textBoxcolor);
    textBox.setPosition(sf::Vector2f(0,880));
    //you've drawn all the things, now make it talk




    sf::Text text;
    sf::Text samuraiText;
    sf::Text brotherText;
    sf::Font font;
    //load font
    if (!font.loadFromFile("HomePlanetBB-Bold.ttf"))
    {
        std::cout << "No font loaded" <<std::endl;
    }

    //create samurai nametag
    initNameTag(&samuraiText, &font, samuraiNamePos, samuraiName);

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
    if(smallClock.getElapsedTime().asSeconds() > 0 && smallClock.getElapsedTime().asSeconds() < .7){
        triangle.move(cursorLow);
    }
    else if(smallClock.getElapsedTime().asSeconds() >= .7 && smallClock.getElapsedTime().asSeconds() < 1.4){
        triangle.move(cursorHigh);
    }
    else{
        triangle.move(cursorHigh);
        smallClock.restart();
    }


    text.setString(string);
    window->clear();
    window->draw(background);
    window->draw(samuraiSprite);
    window->draw(textBox);
    window->draw(text);
    window->draw(triangle);
    window->draw(nameBox);
    window->draw(samuraiText);
    window->display();

}

void beginScript1B2(sf::RenderWindow * window, int * enterPressed){
    sf::IntRect samuraiFace;
    sf::IntRect brotherFace;
    sf::Vector2f samuraiFacePos;
    sf::Vector2f brotherFacePos;
    //sf::View view1 = window->getDefaultView();
    std::vector<std::string> v = {"Silas: BROTHER! WHAT HAPPENED??",
                                  "Xander: You *cough* stood there and watched that guy stab me that's what happened.",
                                  "Silas: I didn't - I was just - ",
                                  "Xander: You could have saved my life but you just watched *cough* instead.\n*cough* You better avenge my life dammit.",
                                  "Silas: Wh-what is this?",
                                  "Xander: The weapon that ended my life...",
                                  "Silar: Brother? BROTHER?!?! ....NOOOOO!!!"};
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
    sf::Texture brotherTexture;
    sf::Sprite brotherSprite;

    //change face expression with line
    if (*enterPressed == 0){
        brotherFace = brotherAnnoyed;
        samuraiFace = samuraiYell;
        brotherFacePos = brotherPos;
        samuraiFacePos = samuraiOtherPos;
    }else if(*enterPressed == 1){
        brotherFace = brotherYell;
        samuraiFace = samuraiConcern;
        brotherFacePos = brotherPos;
        samuraiFacePos = samuraiOtherPos;
    }else if(*enterPressed == 2){
        brotherFace = brotherAnnoyed;
        samuraiFace = samuraiConcern;
        brotherFacePos = brotherPos;
        samuraiFacePos = samuraiOtherPos;
    }else if(*enterPressed == 3){
        brotherFace = brotherYell;
        samuraiFace = samuraiConcern;
        brotherFacePos = brotherPos;
        samuraiFacePos = samuraiOtherPos;
    }else{
        brotherFace = brotherSmile;
        samuraiFace = samuraiSmile;
        brotherFacePos = brotherPos;
        samuraiFacePos = samuraiSmilePos;
    }



    if (!backgroundTexture.loadFromFile("forest.jpeg"))
    {
        std::cout << "Cannot load forest background" << std::endl;
    }
    if (!samuraiTexture.loadFromFile("samurai.png", samuraiFace)){
        std::cout << "Cannot load samurai texture" << std::endl;
    }
    if (!brotherTexture.loadFromFile("brother.png", brotherFace)){
        std::cout << "Cannot load samurai texture" << std::endl;
    }
    if (!mopTexture.loadFromFile("mop.png")){
        std::cout << "Can't load mop" << std::endl;
    }



    background.setTexture(&backgroundTexture);
    mop.setTexture(&mopTexture);

    samuraiSprite.setScale(sf::Vector2f(-2.f, 2.f));
    samuraiSprite.setPosition(samuraiFacePos);
    samuraiSprite.setTexture(samuraiTexture);

    brotherSprite.setScale(sf::Vector2f(2.f, 2.f));
    brotherSprite.setPosition(brotherFacePos);
    brotherSprite.setTexture(brotherTexture);


    //nameBoxes
    initNameBox(&nameBox, samuraiNameBoxPos);
    initNameBox(&nameBox2, brotherNameBoxPos);

    //TextBox
    textBox.setFillColor(textBoxcolor);
    textBox.setPosition(sf::Vector2f(0,880));
    //you've drawn all the things, now make it talk




    sf::Text text;
    sf::Text samuraiText;
    sf::Text brotherText;
    sf::Font font;
    //load font
    if (!font.loadFromFile("HomePlanetBB-Bold.ttf"))
    {
        std::cout << "No font loaded" <<std::endl;
    }

    //create samurai nametag
    initNameTag(&samuraiText, &font, samuraiNamePos, samuraiName);
    initNameTag(&brotherText, &font, brotherNamePos, brotherName);

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
    if(smallClock.getElapsedTime().asSeconds() > 0 && smallClock.getElapsedTime().asSeconds() < .7){
        triangle.move(cursorLow);
    }
    else if(smallClock.getElapsedTime().asSeconds() >= .7 && smallClock.getElapsedTime().asSeconds() < 1.4){
        triangle.move(cursorHigh);
    }
    else{
        triangle.move(cursorHigh);
        smallClock.restart();
    }


    text.setString(string);
    window->clear();
    if(*enterPressed <= 3){
        window->draw(background);
        window->draw(samuraiSprite);
        window->draw(brotherSprite);
    }else{
        window->draw(mop);
    }

    window->draw(textBox);
    window->draw(text);
    window->draw(triangle);

    if(*enterPressed <= 3){
        window->draw(nameBox);
        window->draw(samuraiText);
        window->draw(nameBox2);
        window->draw(brotherText);
    }
    //window->setView(view1);
    window->display();

}

void beginScript1B3(sf::RenderWindow * window, int * enterPressed){
    sf::IntRect samuraiFace;
    sf::Vector2f samuraiFacePos;
    std::vector<std::string> v = {"Silas: Everyone! Everyone listen! ...Xander is dead!",
                                  "Silas: I know it's hard to believe. We were in the forest hunting when a strange man attacked\nhim! Here's his weapon!",
                                  "Villager 1: Who would attack our village like this? What is this mysterious weapon?",
                                  "Villager 2: Impossible! We are a peaceful village - no one would attack us! Silas must have done it! He\nwanted to be the next heir to the throne!",
                                  "Silas: I was too slow. I was always hiding in his shadow.",
                                  "Villager3: I knew it! I never liked him!",
                                  "Silas: I have to be better.",
                                  "Silas: You've got it all wrong! I'll show you all and defeat the real murderer!",
                                  "Silas: I'll do it. I'll avenge him. Even if I have to do it alone."};
    //draw all the things

    sf::CircleShape triangle(25, 3);
    sf::RectangleShape background(sf::Vector2f(window->getSize().x,window->getSize().y));
    sf::RectangleShape textBox(sf::Vector2f(window->getSize().x, (window->getSize().y-380)));
    sf::RectangleShape mop(sf::Vector2f(window->getSize().x, window->getSize().y));
    sf::RectangleShape nameBox(nameBoxSize);
    sf::Texture backgroundTexture;
    sf::Texture mopTexture;
    sf::Texture samuraiTexture;
    sf::Sprite samuraiSprite;



    if(*enterPressed == 4 || *enterPressed == 5 || *enterPressed == 6 || *enterPressed == 8){
        samuraiFace = samuraiGrimace;
        samuraiFacePos = samuraiOtherPos;
    }
    else{
        samuraiFace = samuraiYell;
        samuraiFacePos = samuraiOtherPos;
    }

    if (!backgroundTexture.loadFromFile("town.jpg"))
    {
        std::cout << "Cannot load forest background" << std::endl;
    }
    if (!samuraiTexture.loadFromFile("samurai.png", samuraiFace)){
        std::cout << "Cannot load samurai texture" << std::endl;
    }
    if (!mopTexture.loadFromFile("mop.png")){
        std::cout << "Can't load mop" << std::endl;
    }


    background.setTexture(&backgroundTexture);
    mop.setTexture(&mopTexture);

    samuraiSprite.setScale(sf::Vector2f(-2.f, 2.f));
    samuraiSprite.setPosition(samuraiFacePos);
    samuraiSprite.setTexture(samuraiTexture);


    //nameBoxes
    initNameBox(&nameBox, samuraiNameBoxPos);

    //TextBox
    textBox.setFillColor(textBoxcolor);
    textBox.setPosition(sf::Vector2f(0,880));
    //you've drawn all the things, now make it talk




    sf::Text text;
    sf::Text samuraiText;
    sf::Text brotherText;
    sf::Font font;
    //load font
    if (!font.loadFromFile("HomePlanetBB-Bold.ttf"))
    {
        std::cout << "No font loaded" <<std::endl;
    }

    //create samurai nametag
    initNameTag(&samuraiText, &font, samuraiNamePos, samuraiName);

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
    if(smallClock.getElapsedTime().asSeconds() > 0 && smallClock.getElapsedTime().asSeconds() < .7){
        triangle.move(cursorLow);
    }
    else if(smallClock.getElapsedTime().asSeconds() >= .7 && smallClock.getElapsedTime().asSeconds() < 1.4){
        triangle.move(cursorHigh);
    }
    else{
        triangle.move(cursorHigh);
        smallClock.restart();
    }


    text.setString(string);
    if(*enterPressed == 4 || *enterPressed == 6 || *enterPressed == 8){
        text.setStyle(sf::Text::Italic);
    }else{
        text.setStyle(sf::Text::Regular);
    }

    window->clear();
    if(*enterPressed <= 1 || *enterPressed > 3){
        window->draw(background);
        window->draw(samuraiSprite);
    }else{
        window->draw(mop);
    }

    window->draw(textBox);
    window->draw(text);
    window->draw(triangle);

    if(*enterPressed <= 1 || *enterPressed > 3){
        window->draw(nameBox);
        window->draw(samuraiText);

    }
    window->display();

}

void beginScript1B4(sf::RenderWindow * window, int * enterPressed){
    sf::IntRect samuraiFace;
    sf::IntRect strangerFace;
    sf::Vector2f samuraiFacePos;
    sf::Vector2f strangerFacePos;
    //sf::View view1 = window->getDefaultView();
    std::vector<std::string> v = {"???: Psst. That weapon - it's familiar. Go north to Tarinth. You may find an answer there.",
                                  "Silas: Who are y...uh...Alright I guess. Will do."};
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
    strangerFace = brotherStern;
    samuraiFace = samuraiCalm;
    strangerFacePos = brotherPos;
    samuraiFacePos = samuraiSmilePos;




    if (!backgroundTexture.loadFromFile("town_side.png"))
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
    if(smallClock.getElapsedTime().asSeconds() > 0 && smallClock.getElapsedTime().asSeconds() < .7){
        triangle.move(cursorLow);
    }
    else if(smallClock.getElapsedTime().asSeconds() >= .7 && smallClock.getElapsedTime().asSeconds() < 1.4){
        triangle.move(cursorHigh);
    }
    else{
        triangle.move(cursorHigh);
        smallClock.restart();
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


GameState runScene1B(sf::RenderWindow * window, sf::Clock * sceneClock){
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
        sf::Time elapsedMain1 = sceneClock->getElapsedTime();
        if (beforeDeath && !endDeath) {
            if (elapsedMain1.asSeconds() <= .1) {
                displayBlack(window);
                resetGlobalsScene1();
            } else if (elapsedMain1.asSeconds() >= 0.1 && elapsedMain1.asSeconds() < 2.9) {
                smallClock.restart();
                string = "forest.jpeg";
                fillBackground(window, &string, &fadeVal, &smallClock);
            } else if (elapsedMain1.asSeconds() >= 2.9 && elapsedMain1.asSeconds() < 3.0) {
                fadeVal = 0;
            } else if (elapsedMain1.asSeconds() >= 3.0 && elapsedMain1.asSeconds() < 4.3) {
                string = "forest.jpeg";
                slideSamurai(window, &string, &samuraiSmile, &smallClock, &spritePosition, &textBoxPos);
            } else if (elapsedMain1.asSeconds() >= 4.3 && elapsedMain1.asSeconds() < 4.4) {
                enterPressed = 0;
            } else if (elapsedMain1.asSeconds() >= 4.4 && enterPressed < 2) {
                beginScript1B(window, &enterPressed);
            } else if (enterPressed == 1) {
                smallClock.restart();
            } else if (elapsedMain1.asSeconds() >= 4.4 && enterPressed >= 2) {
                displayBlack(window);
                if (smallClock.getElapsedTime().asSeconds() > 1.5) {
                    sceneClock->restart();
                    forestMusic.stop();
                    beforeDeath = false;
                    endDeath = true;
                }
            }
            //play forest sounds
            if (elapsedMain1.asSeconds() <= .1){
                if (!forestMusic.openFromFile("birds chirping.wav"))
                    std::cout << "cant play" << std::endl; // error
            }else if(elapsedMain1.asSeconds() >= .1 && elapsedMain1.asSeconds() < .2){
                forestMusic.play();
            }

        } else if (endDeath && !beforeDeath) {
            if (elapsedMain1.asSeconds() < 2) {
                playBrotherFight(window);
            } else if (elapsedMain1.asSeconds() >= 2 && elapsedMain1.asSeconds() < 2.1) {
                swordsClashing.stop();
                xVal = 1920;
                yVal = 1080;
            } else if (elapsedMain1.asSeconds() >= 2 && elapsedMain1.asSeconds() < 3.3) {
                playBlackCoatFight(window);
            } else if (elapsedMain1.asSeconds() >= 3.3 && elapsedMain1.asSeconds() < 4) {
                displayBlack(window);
            } else if (elapsedMain1.asSeconds() >= 4 && elapsedMain1.asSeconds() < 4.1) {
                enterPressed = 0;
                spritePosition = 0;
            } else if (elapsedMain1.asSeconds() >= 4.1 && elapsedMain1.asSeconds() < 5.4) {
                string = "samurai.png";
                string1 = "brother.png";
                string2 = "forest.jpeg";
                enterPressed = 0;
                slideInSprites(window, &string2, &spritePosition, &smallClock, &textBoxPos, &string, &string1,
                               &samuraiConcern, &brotherAnnoyed);
            } else {
                beginScript1B2(window, &enterPressed);
            }
            if (enterPressed > 6 && elapsedMain1.asSeconds() > 5.4) {
                endDeath = false;
                forestMusic.stop();
                sceneClock->restart();
            }

            //play swords
            if (elapsedMain1.asSeconds() <= .1){
                if (!swordsClashing.openFromFile("swords clashing.wav"))
                    std::cout << "cant play" << std::endl; // error
            }else if(elapsedMain1.asSeconds() >= .1 && elapsedMain1.asSeconds() < .2){
                swordsClashing.play();
            }

            //play forest sounds
            if (elapsedMain1.asSeconds() <= .1){
                if (!forestMusic.openFromFile("birds chirping.wav"))
                    std::cout << "cant play" << std::endl; // error
            }else if(elapsedMain1.asSeconds() >= 4.1 && elapsedMain1.asSeconds() < 4.2){
                forestMusic.play();
            }

        } else if (!leave) {
            if (elapsedMain1.asSeconds() < 5.1) {
                string = "Back in the village...";
                runText(window, &string, 275, 450, &fadeVal, &smallClock, &fadeOut, &holdText);
            } else if (elapsedMain1.asSeconds() >= 5.1 && elapsedMain1.asSeconds() < 5.2) {
                fadeVal = 255;
            } else if (elapsedMain1.asSeconds() >= 5.1 && elapsedMain1.asSeconds() < 7.9) {
                string = "town.jpg";
                fillBackground(window, &string, &fadeVal, &smallClock);
            } else if (elapsedMain1.asSeconds() >= 7.9 && elapsedMain1.asSeconds() < 8.0) {
                smallClock.restart();
                spritePosition = 0;
                textBoxPos = 1080;
            } else if (elapsedMain1.asSeconds() >= 8.0 && elapsedMain1.asSeconds() < 9.3) {
                string = "town.jpg";
                slideSamurai(window, &string, &samuraiConcern, &smallClock, &spritePosition, &textBoxPos);
            } else if (elapsedMain1.asSeconds() >= 9.3 && elapsedMain1.asSeconds() < 9.4) {
                enterPressed = 0;
            } else {
                beginScript1B3(window, &enterPressed);
            }
            if (enterPressed > 8 && elapsedMain1.asSeconds() > 9.4) {
                leave = true;
                crowdMurmur.stop();
                sceneClock->restart();
            }
            if (elapsedMain1.asSeconds() <= .1){
                if (!crowdMurmur.openFromFile("crowd murmur.wav"))
                    std::cout << "cant play" << std::endl; // error
            }else if(elapsedMain1.asSeconds() >= 5.1 && elapsedMain1.asSeconds() < 5.2){
                crowdMurmur.play();
            }

        } else {
            if (elapsedMain1.asSeconds() <= .1) {
                displayBlack(window);
                fadeVal = 0;
                holdText = false;
                fadeOut = false;
                smallClock.restart();
            } else if (elapsedMain1.asSeconds() >= .1 && elapsedMain1.asSeconds() < 5.1) {
                string = "As Silas leaves the village...";
                runText(window, &string, 275, 450, &fadeVal, &smallClock, &fadeOut, &holdText);
            } else if (elapsedMain1.asSeconds() >= 5.1 && elapsedMain1.asSeconds() < 5.2) {
                fadeVal = 255;
            } else if (elapsedMain1.asSeconds() >= 5.1 && elapsedMain1.asSeconds() < 7.9) {
                string = "town_side.png";
                fillBackground(window, &string, &fadeVal, &smallClock);
            } else if (elapsedMain1.asSeconds() >= 7.9 && elapsedMain1.asSeconds() < 8.0) {
                smallClock.restart();
                spritePosition = 0;
                textBoxPos = 1080;
            } else if (elapsedMain1.asSeconds() >= 8.0 && elapsedMain1.asSeconds() < 9.3) {
                string = "samurai.png";
                string1 = "niles.png";
                string2 = "town_side.png";
                enterPressed = 0;
                slideInSprites(window, &string2, &spritePosition, &smallClock, &textBoxPos, &string, &string1,
                               &samuraiCalm, &brotherStern);
            } else if (elapsedMain1.asSeconds() >= 9.3 && elapsedMain1.asSeconds() < 9.4) {
                enterPressed = 0;
            } else {
                beginScript1B4(window, &enterPressed);
                sceneDone = true;

            }
        }
        //end scene
        if (enterPressed > 1 && elapsedMain1.asSeconds() >= 9.4 && leave && sceneDone) {
            sceneClock->restart();
            return scene2A;
        }
    }
}
GameState runScene1(sf::RenderWindow * window, sf::Clock * sceneClock){
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
                    switch(event.key.code) {
                        case sf::Keyboard::Escape:
                            window->close();
                            break;
                        case sf::Keyboard::Return:
                            //incrementEnter(enterPressed);
                            enterPressed++;
                            playSelect();
                            //oceanSound.setVolume(10);
                        //std::cout << *enterPressed << std::endl;
                            break;

                    }


            }

        }
        std::string string;
        std::string string1, string2;
        sf::Time elapsedMain = sceneClock->getElapsedTime();
        //line1
        if (elapsedMain.asSeconds() <= 5) {
            string = "Off the coast of the Andriac Sea...";
            runText(window, &string, 200, 450, &fadeVal, &smallClock, &fadeOut, &holdText);
        } else if (elapsedMain.asSeconds() > 5 && elapsedMain.asSeconds() < 5.1) {
            resetFade();
        }//line 2
        else if (elapsedMain.asSeconds() >= 5.1 && elapsedMain.asSeconds() < 10.1) {
            string = "A powerful village is hidden in the\n depths of the forest...";
            runText(window, &string, 100, 400, &fadeVal, &smallClock, &fadeOut, &holdText);
        } else if (elapsedMain.asSeconds() > 10.1 && elapsedMain.asSeconds() < 10.2) {
            resetFade();
        }//line 3
        else if (elapsedMain.asSeconds() >= 10.2 && elapsedMain.asSeconds() < 14.8) {
            string = "Where two brothers are heir to the throne...";
            runText(window, &string, 10, 450, &fadeVal, &smallClock, &fadeOut, &holdText);
        } else if (elapsedMain.asSeconds() >= 14.8 && elapsedMain.asSeconds() < 18.2) {
            string = "Chapter 1: Early Departure";
            introChapterNum(window, &string, &smallClock);
        } else if (elapsedMain.asSeconds() >= 18.2 && elapsedMain.asSeconds() < 18.3) {
            fadeVal = 255;
        } else if (elapsedMain.asSeconds() >= 18.3 && elapsedMain.asSeconds() < 21.1) {
            smallClock.restart();
            string = "forest.jpeg";
            fillBackground(window, &string, &fadeVal, &smallClock);
        } else if (elapsedMain.asSeconds() >= 21.1 && elapsedMain.asSeconds() < 21.2) {
            fadeVal = 0;
        } else if (elapsedMain.asSeconds() >= 21.2 && elapsedMain.asSeconds() < 22.5) {
            string = "samurai.png";
            string1 = "brother.png";
            string2 = "forest.jpeg";
            slideInSprites(window, &string2, &spritePosition, &smallClock, &textBoxPos, &string, &string1,
                           &samuraiSmile, &brotherSmile);
        } else if (elapsedMain.asSeconds() >= 22.5 && elapsedMain.asSeconds() < 22.6) {
            enterPressed = 0;
        } else {
            beginScript(window, &enterPressed);
        }

        //play forest audio
        if (elapsedMain.asSeconds() >= 18.3 && elapsedMain.asSeconds() < 18.4){
            if (!forestMusic.openFromFile("birds chirping.wav"))
                std::cout << "cant play" << std::endl; // error
        }else if(elapsedMain.asSeconds() >= 18.4 && elapsedMain.asSeconds() < 18.5){
            forestMusic.play();
        }

        //play chpater audio
        if (elapsedMain.asSeconds() >= 14.4 && elapsedMain.asSeconds() < 14.5){
            if (!chapter1Thud.openFromFile("thud1.wav"))
                std::cout << "cant play" << std::endl; // error
        }else if(elapsedMain.asSeconds() >= 15.7 && elapsedMain.asSeconds() < 15.8){
            chapter1Thud.play();
        }

        //play chapter intro audio

        if (enterPressed > 8 && elapsedMain.asSeconds() >= 22.6) {
            sceneClock->restart();
            forestMusic.stop();
            return scene1B;
        }

    }


}


