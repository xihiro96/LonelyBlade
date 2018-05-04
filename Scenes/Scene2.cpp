//
// Created by mhendrix on 4/26/18.
//
#include "Scene2.h"
sf::Uint8 fadeVal2 = 255;
sf::Clock smallClock2;
int spritePosition2 = 0;
int textBoxPos2 = 1080;
bool bringStranger = false;
bool enterBar = false;
bool newParty = false;
bool moveOn = false;
bool strangerRole = false;
bool bartenderStart = false;
bool nextScene = false;
bool showNewParty = false;
sf::Music chapter2Thud;
sf::Music barNoise;
sf::Music partyBaryNoise;
sf::Music breakIn;

void resetGlobalsScene2(){
    fadeVal2 = 255;
    spritePosition2 = 0;
    textBoxPos2 = 1080;
}


void inBarScript(sf::RenderWindow * window, int * enterPressed){
    sf::IntRect samuraiFace;
    sf::IntRect strangerFace;
    sf::Vector2f samuraiFacePos;
    sf::Vector2f strangerFacePos;
    //sf::View view1 = window->getDefaultView();
    std::vector<std::string> v = {"Silas: ...And that's the gist of it.",
                                  "Silas: It took some time to tell the story of my brother between bites of chicken\nand potatoes. The vegetables were stringy and kind of tasteless, but I finished that off, too.",
                                  "Silas: Bary was kind enough to pay for my food. Eating kept me from focusing too\nmuch on what I was saying.",
                                  "Bary: ...Wow. It's hard to believe Xander's really gone...He said he'd stop by again sometime, too...",
                                  "Silas: You knew my brother??",
                                  "Bary: Yeah. Actually, a lot of us here in Tanith know him... or, knew him. We had\na champion for this village, too. His name was Lincoln.",
                                  "Bary: Lincoln and Xander would duel from time to time. They were pretty equal in\nstrength and skill, see. And they always drew big crowds.",
                                  "Bary: Afterwards they'd come to this bar and throw a huge celebration. Everyone got in on it.",
                                  "Silas: So Xander was a big shot here, too...",
                                  "Bary: Yeah. But a few nights ago, Lincoln got done in. Someone from outside of\nthe village challenged him to a duel, and they killed him. And the challenger\njust got up and left. We were all too stunned to chase them.",
                                  "Silas: ...Wait, a few nights ago? Was the weapon something like this?",
                                  "Bary: Yeah! That looks so familiar! We should get to the bottom of this...",
                                  "Bary: ...You know what, Silas? I'm gonna stick with you for a bit. I want to know\nwho or what was after Lincoln, and I have a feeling Xander's involved somehow, as well.",
                                  "Silas: You mean you'll help me get clues on what happened with my brother?\n...But how do I know if I can trust you?",
                                  "Bary: I just bought you food, didn't I?? If I was really after you, you'd be dead\nafter the first few bites, wouldn't you think?",
                                  "Silas: ...I guess that's true.",
                                  "Silas: I hope I don't regret this.",
                                  "Silas: Welcome to the team."};
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
    if(*enterPressed == 3 || *enterPressed == 6 || *enterPressed == 7 || *enterPressed == 5 || *enterPressed == 9){
        strangerFace = brotherSmile;
        samuraiFace = samuraiConcern;
        strangerFacePos = brotherPos;
        samuraiFacePos = samuraiSmilePos;
    }else{
        strangerFace = brotherStern;
        samuraiFace = samuraiConcern;
        strangerFacePos = brotherPos;
        samuraiFacePos = samuraiSmilePos;
    }





    if (!backgroundTexture.loadFromFile("bar.png"))
    {
        std::cout << "Cannot load town background" << std::endl;
    }
    if (!samuraiTexture.loadFromFile("samurai.png", samuraiFace)){
        std::cout << "Cannot load samurai texture" << std::endl;
    }
    if (!strangerTexture.loadFromFile("barStranger.png", strangerFace)){
        std::cout << "Cannot load niles texture" << std::endl;
    }
    if (!mopTexture.loadFromFile("mop.png")){
        std::cout << "Can't load mop" << std::endl;
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

    if(*enterPressed == 1 || *enterPressed == 2 || *enterPressed == 16){
        text.setStyle(sf::Text::Italic);
    }else{
        text.setStyle(sf::Text::Regular);
    }

    if (!font.loadFromFile("HomePlanetBB-Bold.ttf"))
    {
        std::cout << "No font loaded" <<std::endl;
    }

    //create samurai nametag
    initNameTag(&samuraiText, &font, samuraiNamePos, samuraiName);
    initNameTag(&strangerText, &font, baryNamePos, barName);

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
    if(smallClock2.getElapsedTime().asSeconds() > 0 && smallClock2.getElapsedTime().asSeconds() < .7){
        triangle.move(cursorLow);
    }
    else if(smallClock2.getElapsedTime().asSeconds() >= .7 && smallClock2.getElapsedTime().asSeconds() < 1.4){
        triangle.move(cursorHigh);
    }
    else{
        triangle.move(cursorHigh);
        smallClock2.restart();
    }

    text.setString(string);
    window->clear();
    if(*enterPressed < 10 || *enterPressed > 11){
        window->draw(background);
        window->draw(samuraiSprite);
        window->draw(strangerSprite);
    }else{
        window->draw(mop);
    }

    window->draw(textBox);
    window->draw(text);
    window->draw(triangle);

    if(*enterPressed < 10 || *enterPressed > 11){
        window->draw(nameBox);
        window->draw(samuraiText);
        window->draw(nameBox);
        window->draw(samuraiText);
        window->draw(nameBox2);
        window->draw(strangerText);

    }
    window->display();
}

void afterPartyScript(sf::RenderWindow * window, int * enterPressed){
    sf::IntRect samuraiFace;
    sf::IntRect strangerFace;
    sf::Vector2f samuraiFacePos;
    sf::Vector2f strangerFacePos;
    //sf::View view1 = window->getDefaultView();
    std::vector<std::string> v = {"Bary: That weapon! It looks similar to the one you just showed!",
                                  "Silas: I think they're coming for us! Let's show them what we're made of."};
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
    samuraiFace = samuraiConcern;
    strangerFacePos = brotherPos;
    samuraiFacePos = samuraiSmilePos;






    if (!backgroundTexture.loadFromFile("bar.png"))
    {
        std::cout << "Cannot load town background" << std::endl;
    }
    if (!samuraiTexture.loadFromFile("samurai.png", samuraiFace)){
        std::cout << "Cannot load samurai texture" << std::endl;
    }
    if (!strangerTexture.loadFromFile("barStranger.png", strangerFace)){
        std::cout << "Cannot load niles texture" << std::endl;
    }
    if (!mopTexture.loadFromFile("mop.png")){
        std::cout << "Can't load mop" << std::endl;
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
    initNameTag(&strangerText, &font, baryNamePos, barName);

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
    if(smallClock2.getElapsedTime().asSeconds() > 0 && smallClock2.getElapsedTime().asSeconds() < .7){
        triangle.move(cursorLow);
    }
    else if(smallClock2.getElapsedTime().asSeconds() >= .7 && smallClock2.getElapsedTime().asSeconds() < 1.4){
        triangle.move(cursorHigh);
    }
    else{
        triangle.move(cursorHigh);
        smallClock2.restart();
    }

    text.setString(string);
    window->clear();
    if(*enterPressed < 10 || *enterPressed > 11){
        window->draw(background);
        window->draw(samuraiSprite);
        window->draw(strangerSprite);
    }else{
        window->draw(mop);
    }

    window->draw(textBox);
    window->draw(text);
    window->draw(triangle);

    if(*enterPressed < 10 || *enterPressed > 11){
        window->draw(nameBox);
        window->draw(samuraiText);
        window->draw(nameBox);
        window->draw(samuraiText);
        window->draw(nameBox2);
        window->draw(strangerText);

    }
    window->display();
}


void afterStranger(sf::RenderWindow * window, int * enterPressed){
    sf::IntRect samuraiFace;
    sf::IntRect strangerFace;
    sf::Vector2f samuraiFacePos;
    sf::Vector2f strangerFacePos;
    //sf::View view1 = window->getDefaultView();
    std::vector<std::string> v = {"???: You there, you look a little lost. You're not from these parts, are you?",
                                  "Silas: Uh, no I -",
                                  "Silas: I don't feel so good...",
                                  "???: Hey, I - Whoa, you don't look so good. Are you okay?",
                                  "Silas: Uh, umm, yeah, I'm fine-",
                                  "Silas: Just starving apparently...",
                                  "Bary: Let's go get something to eat! My treat. Name's Bary by the way.",
                                  "Silas: Nice to meet you Bary. Thanks",
                                  "Bary: No problem!"};
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
    if(*enterPressed == 3 || *enterPressed == 4){
        strangerFace = brotherSmile;
        samuraiFace = samuraiConcern;
        strangerFacePos = brotherPos;
        samuraiFacePos = samuraiSmilePos;
    }else if(*enterPressed == 5){
        strangerFace = brotherSmile;
        samuraiFace = samuraiGrimace;
        strangerFacePos = brotherPos;
        samuraiFacePos = samuraiSmilePos;
    }else if(*enterPressed == 7 || *enterPressed == 8){
        strangerFace = brotherStern;
        samuraiFace = samuraiSmile;
        strangerFacePos = brotherPos;
        samuraiFacePos = samuraiOtherPos;
    }else {
        strangerFace = brotherStern;
        samuraiFace = samuraiConcern;
        strangerFacePos = brotherPos;
        samuraiFacePos = samuraiSmilePos;
    }

    if (!backgroundTexture.loadFromFile("outsideBar.jpg"))
    {
        std::cout << "Cannot load town background" << std::endl;
    }
    if (!samuraiTexture.loadFromFile("samurai.png", samuraiFace)){
        std::cout << "Cannot load samurai texture" << std::endl;
    }
    if (!strangerTexture.loadFromFile("barStranger.png", strangerFace)){
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

    if(*enterPressed == 2 || *enterPressed == 5){
        text.setStyle(sf::Text::Italic);
    }else{
        text.setStyle(sf::Text::Regular);
    }

    //create samurai nametag
    initNameTag(&samuraiText, &font, samuraiNamePos, samuraiName);

    if(*enterPressed > 5) {
        initNameTag(&strangerText, &font, baryNamePos, barName);
    }else{
        initNameTag(&strangerText, &font, strangerNamePos, strangerName);
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
    if(smallClock2.getElapsedTime().asSeconds() > 0 && smallClock2.getElapsedTime().asSeconds() < .7){
        triangle.move(cursorLow);
    }
    else if(smallClock2.getElapsedTime().asSeconds() >= .7 && smallClock2.getElapsedTime().asSeconds() < 1.4){
        triangle.move(cursorHigh);
    }
    else{
        triangle.move(cursorHigh);
        smallClock2.restart();
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


void beforeStranger(sf::RenderWindow * window, int * enterPressed){
    sf::IntRect samuraiFace;
    sf::Vector2f samuraiFacePos;
    std::vector<std::string> v = {"Silas: It's only been a couple days since I've ventured out on my own.",
                                  "Silas: I've only ever been to one other village outside of ours...and this place\nTanith is not one of them.",
                                  "Silas: I don't know anyone, and I just realized I have no money. What do I do...?"};
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

    samuraiFace = samuraiCalm;
    samuraiFacePos = samuraiOtherPos;


    if (!backgroundTexture.loadFromFile("outsideBar.jpg"))
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
    if(smallClock2.getElapsedTime().asSeconds() > 0 && smallClock2.getElapsedTime().asSeconds() < .7){
        triangle.move(cursorLow);
    }
    else if(smallClock2.getElapsedTime().asSeconds() >= .7 && smallClock2.getElapsedTime().asSeconds() < 1.4){
        triangle.move(cursorHigh);
    }
    else{
        triangle.move(cursorHigh);
        smallClock2.restart();
    }


    text.setString(string);
    text.setStyle(sf::Text::Italic);
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

void bartenderIntro(sf::RenderWindow * window, int * enterPressed){
    sf::IntRect samuraiFace;
    sf::IntRect strangerFace;
    sf::Vector2f samuraiFacePos;
    sf::Vector2f strangerFacePos;
    //sf::View view1 = window->getDefaultView();
    std::vector<std::string> v = {"???: Hey! I'm one of the bartenders. I patched up your friend's wounds. Your friend\nis okay, but he needs to stay here and rest. He fell asleep pretty quickly while\nI patched him up.",
                                  "Silas: Does this mean I don't need to get a cure for a venom? Maybe I should go to Reni\nand return anyway...",
                                  "Silas: That's fine. I want him to rest.",
                                  "???: Who were those people anyway?? They just attacked you both!",
                                  "Silas: I wish I could tell you. Those people killed my brother and most likely Lincoln.",
                                  "???: Lincoln?! He was amazing! Who was your brother?",
                                  "Silas: Xander.",
                                  "???: Woah. I've heard of him! No wonder you look familiar! Does this mean you're the\nnext leader of your village??",
                                  "Silas: Unfortunately. But nothing will continue until I avenge my brother's death.",
                                  "???: Wow! So cool! Can I join you??",
                                  "Silas: ...What? This isn't a game - ",
                                  "???: You need help! If you didn't have that friend of yours you would be the one\ninjured right now. Let me help you out! Where are you going next?",
                                  "Silas: Would it be bad to go on with this young girl...can she even fight? Agh but\nshe seems stubborn. Maybe in Reni no harm will come and just answers. Besides, I still\nhave no money and need someone to rely on.",
                                  "Silas: Alright fine. You can join. My name is -",
                                  "Amy: Silas! ...Don't give me that face, you said your brother's name, I know yours.\nMy name is Amy by the way! Nice to meet you!",
                                  "Silas: This should be interesting."};
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
    if(*enterPressed == 1 || *enterPressed == 12 || *enterPressed == 15){
        strangerFace = bartenderSmile;
        samuraiFace = samuraiGrimace;
        strangerFacePos = brotherPos;
        samuraiFacePos = samuraiSmilePos;
    }else if(*enterPressed == 3 || *enterPressed == 4 || *enterPressed == 5 || *enterPressed == 6){
        strangerFace = bartenderFrown;
        samuraiFace = samuraiConcern;
        strangerFacePos = brotherPos;
        samuraiFacePos = samuraiSmilePos;
    }
    else{
        strangerFace = bartenderSmile;
        samuraiFace = samuraiConcern;
        strangerFacePos = brotherPos;
        samuraiFacePos = samuraiSmilePos;
    }





    if (!backgroundTexture.loadFromFile("bar.png"))
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

    //create samurai nametag
    initNameTag(&samuraiText, &font, samuraiNamePos, samuraiName);
    if(*enterPressed > 13){
        initNameTag(&strangerText, &font, amyNamePos, bartenderName);
    }else {
        initNameTag(&strangerText, &font, strangerNamePos, strangerName);
    }

    //intiate talking
    std::string string;
    createScript(&text, &font, string);

    if(*enterPressed == 1 || *enterPressed == 12 || *enterPressed == 15){
        text.setStyle(sf::Text::Italic);
    }else{
        text.setStyle(sf::Text::Regular);
    }


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
    if(smallClock2.getElapsedTime().asSeconds() > 0 && smallClock2.getElapsedTime().asSeconds() < .7){
        triangle.move(cursorLow);
    }
    else if(smallClock2.getElapsedTime().asSeconds() >= .7 && smallClock2.getElapsedTime().asSeconds() < 1.4){
        triangle.move(cursorHigh);
    }
    else{
        triangle.move(cursorHigh);
        smallClock2.restart();
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

void strangerTalk1(sf::RenderWindow * window, int * enterPressed){
    sf::IntRect samuraiFace;
    sf::IntRect strangerFace;
    sf::Vector2f samuraiFacePos;
    sf::Vector2f strangerFacePos;
    //sf::View view1 = window->getDefaultView();
    std::vector<std::string> v = {"???: No normal doctor will help your friend.",
                                  "Silas: You again? Wh - I thought you were from my village what are you - ",
                                  "???: That weapon delivers a harsh venom that can only be cured by one thing. You\ncan find it and more answers if you go to Reni next.",
                                  "Silas: We need to stop his bleeding now though - "};
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
    if(*enterPressed == 3){
        strangerFace = brotherStern;
        samuraiFace = samuraiYell;
        strangerFacePos = brotherPos;
        samuraiFacePos = samuraiSmilePos;
    }else {
        strangerFace = brotherStern;
        samuraiFace = samuraiConcern;
        strangerFacePos = brotherPos;
        samuraiFacePos = samuraiSmilePos;
    }




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
    if(smallClock2.getElapsedTime().asSeconds() > 0 && smallClock2.getElapsedTime().asSeconds() < .7){
        triangle.move(cursorLow);
    }
    else if(smallClock2.getElapsedTime().asSeconds() >= .7 && smallClock2.getElapsedTime().asSeconds() < 1.4){
        triangle.move(cursorHigh);
    }
    else{
        triangle.move(cursorHigh);
        smallClock2.restart();
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

void postBattle2Script(sf::RenderWindow * window, int * enterPressed){
    sf::IntRect samuraiFace;
    sf::IntRect strangerFace;
    sf::Vector2f samuraiFacePos;
    sf::Vector2f strangerFacePos;
    //sf::View view1 = window->getDefaultView();
    std::vector<std::string> v = {"Silas: I can't believe we made it out alive from that. They were tougher than I thought.",
                                  "Silas: No wonder Xander fell to their leader.",
                                  "Bary: *panting* You have skills Silas...I don't know if I can continue to keep up\nwith you. Haven't fought like that in years.",
                                  "Silas: Are you okay? Wait - is that blood? Did you get cut?",
                                  "Bary: Just a scratch I'll be fine.",
                                  "Silas: That's not just a scratch! We need to get you help!",
                                  "Bary: Okay...but after that, you should head out on your own...if his men are\nthis strong I can't imagine how strong he is.",
                                  "Silas: His wounds are too large. Will he even make it?",
                                  "Silas: Is anyone here a doctor?"};
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



    if(*enterPressed == 0 || *enterPressed == 1 || *enterPressed == 2){
        strangerFace = brotherSmile;
        samuraiFace = samuraiGrimace;
        strangerFacePos = brotherPos;
        samuraiFacePos = samuraiSmilePos;
    }else if(*enterPressed == 5 || *enterPressed == 8){
        strangerFace = brotherSmile;
        samuraiFace = samuraiYell;
        strangerFacePos = brotherPos;
        samuraiFacePos = samuraiSmilePos;
    }
    else{
        strangerFace = brotherSmile;
        samuraiFace = samuraiConcern;
        strangerFacePos = brotherPos;
        samuraiFacePos = samuraiSmilePos;
    }

    if (!backgroundTexture.loadFromFile("bar.png"))
    {
        std::cout << "Cannot load town background" << std::endl;
    }
    if (!samuraiTexture.loadFromFile("samurai.png", samuraiFace)){
        std::cout << "Cannot load samurai texture" << std::endl;
    }
    if (!strangerTexture.loadFromFile("barStranger.png", strangerFace)){
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

    if(*enterPressed == 1 || *enterPressed == 7){
        text.setStyle(sf::Text::Italic);
    }else{
        text.setStyle(sf::Text::Regular);
    }

    //create samurai nametag
    initNameTag(&samuraiText, &font, samuraiNamePos, samuraiName);
    initNameTag(&strangerText, &font, baryNamePos, barName);

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
    if(smallClock2.getElapsedTime().asSeconds() > 0 && smallClock2.getElapsedTime().asSeconds() < .7){
        triangle.move(cursorLow);
    }
    else if(smallClock2.getElapsedTime().asSeconds() >= .7 && smallClock2.getElapsedTime().asSeconds() < 1.4){
        triangle.move(cursorHigh);
    }
    else{
        triangle.move(cursorHigh);
        smallClock2.restart();
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

GameState runScene2B(sf::RenderWindow * window, sf::Clock * sceneClock){
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
        if (!strangerRole && !bartenderStart) {
            if (elapsedMain3.asSeconds() < .1) {
                displayBlack(window);
                resetGlobalsScene2();
            } else if (elapsedMain3.asSeconds() >= .1 && elapsedMain3.asSeconds() < 2.9) {
                string = "bar.png";
                fillBackground(window, &string, &fadeVal2, &smallClock2);
            } else if (elapsedMain3.asSeconds() >= 2.9 && elapsedMain3.asSeconds() < 4.4) {
                string = "samurai.png";
                string1 = "barStranger.png";
                string2 = "bar.png";
                enterPressed = 0;
                slideInSprites(window, &string2, &spritePosition2, &smallClock2, &textBoxPos2, &string, &string1,
                               &samuraiConcern, &brotherStern);
            } else if (elapsedMain3.asSeconds() >= 2.9 && elapsedMain3.asSeconds() < 3.0) {
                enterPressed = 0;
            } else if (elapsedMain3.asSeconds() >= 3.0) {
                postBattle2Script(window, &enterPressed);
            }
            if (enterPressed > 8) {
                strangerRole = true;
                sceneClock->restart();
                enterPressed = 0;
            }
        } else if (strangerRole && !bartenderStart) {

            if (elapsedMain3.asSeconds() < .1) {
                smallClock2.restart();
                spritePosition2 = 0;
            } else if (elapsedMain3.asSeconds() >= .1 && elapsedMain3.asSeconds() < 1.4) {
                string = "bar.png";
                string1 = "samurai.png";
                string2 = "niles.png";
                slideSpriteRight(window, &string, &spritePosition2, &smallClock2, &textBoxPos2, &string1, &string2,
                                 &samuraiConcern, &brotherStern);
            } else if (elapsedMain3.asSeconds() >= 1.4 && elapsedMain3.asSeconds() < 1.5) {
                enterPressed = 0;
            } else {
                strangerTalk1(window, &enterPressed);
            }
            if (enterPressed > 3) {
                bartenderStart = true;
                sceneClock->restart();
            }

        } else if (bartenderStart && !showNewParty) {
            if (elapsedMain3.asSeconds() < .1) {
                smallClock2.restart();
                spritePosition2 = 0;
            } else if (elapsedMain3.asSeconds() >= .1 && elapsedMain3.asSeconds() < 1.4) {
                string = "bar.png";
                string1 = "samurai.png";
                string2 = "bartender.png";
                slideSpriteRight(window, &string, &spritePosition2, &smallClock2, &textBoxPos2, &string1, &string2,
                                 &samuraiConcern, &bartenderSmile);
            } else if (elapsedMain3.asSeconds() >= 1.4 && elapsedMain3.asSeconds() < 1.5) {
                enterPressed = 0;
            } else {
                bartenderIntro(window, &enterPressed);
                if (enterPressed > 15) {
                    showNewParty = true;
                    sceneClock->restart();
                }
            }
        } else if (showNewParty && !nextScene) {
            if (elapsedMain3.asSeconds() < .1) {
                displayBlack(window);
                smallClock2.restart();
                spritePosition2 = 0;
                textBoxPos2 = 1080;
                fadeVal2 = 255;
            } else if (elapsedMain3.asSeconds() >= .1 && elapsedMain3.asSeconds() < 2.4) {
                string = "Amy has joined the party.";
                partyJoin(window, &string, &smallClock2);
            } else if (elapsedMain3.asSeconds() > 2.4) {
                nextScene = true;
            }
            //play bary party
            if (elapsedMain3.asSeconds() <.1){
                if (!partyBaryNoise.openFromFile("partyjoin.wav"))
                    std::cout << "cant play" << std::endl; // error
            }else if(elapsedMain3.asSeconds() >= .1 && elapsedMain3.asSeconds() < .2){
                partyBaryNoise.play();
            }
        }
        if (elapsedMain3.asSeconds() >= 2.4 && nextScene && showNewParty) {
            sceneClock->restart();
            barNoise.stop();
            return scene3A;
        }
        //play bar
        if (elapsedMain3.asSeconds() <.1 && !strangerRole && !bartenderStart){
            if (!barNoise.openFromFile("bar crowd.wav"))
                std::cout << "cant play" << std::endl; // error
        }else if(elapsedMain3.asSeconds() >= .1 && elapsedMain3.asSeconds() < .2 && !strangerRole && !bartenderStart){
            barNoise.play();
            barNoise.setVolume(5);
            barNoise.setLoop(1);
        }
    }
}

GameState runScene2A(sf::RenderWindow * window, sf::Clock * sceneClock){
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
        sf::Time elapsedMain2 = sceneClock->getElapsedTime();
        if (!bringStranger && !enterBar) {
            if (elapsedMain2.asSeconds() < .1) {
                displayBlack(window);
            } else if (elapsedMain2.asSeconds() >= .1 && elapsedMain2.asSeconds() < 3.5) {
                string = "Chapter 2: New Connection";
                introChapterNum(window, &string, &smallClock2);
            } else if (elapsedMain2.asSeconds() >= 3.5 && elapsedMain2.asSeconds() < 6.3) {
                chapter2Thud.stop();
                string = "outsideBar.jpg";
                fillBackground(window, &string, &fadeVal2, &smallClock2);
            } else if (elapsedMain2.asSeconds() >= 6.3 && elapsedMain2.asSeconds() < 7.6) {
                string = "outsideBar.jpg";
                slideSamurai(window, &string, &samuraiCalm, &smallClock2, &spritePosition2, &textBoxPos2);
            } else {
                beforeStranger(window, &enterPressed);
            }
            if (enterPressed > 2) {
                bringStranger = true;
                sceneClock->restart();
            }

            //play thud
            if (elapsedMain2.asSeconds() <.1){
                if (!chapter2Thud.openFromFile("thud1.wav"))
                    std::cout << "cant play" << std::endl; // error
            }else if(elapsedMain2.asSeconds() >= .1 && elapsedMain2.asSeconds() < .2){
                chapter2Thud.play();
            }

        } else if (bringStranger && !enterBar) {
            if (elapsedMain2.asSeconds() < .1) {
                smallClock2.restart();
                spritePosition2 = 0;
            } else if (elapsedMain2.asSeconds() >= .1 && elapsedMain2.asSeconds() < 1.4) {
                string = "outsideBar.jpg";
                string1 = "samurai.png";
                string2 = "barStranger.png";
                slideSpriteRight(window, &string, &spritePosition2, &smallClock2, &textBoxPos2, &string1, &string2,
                                 &samuraiCalm, &brotherStern);
            } else if (elapsedMain2.asSeconds() >= 1.4 && elapsedMain2.asSeconds() < 1.5) {
                enterPressed = 0;
            } else {
                afterStranger(window, &enterPressed);
            }
            if (enterPressed > 8) {
                enterBar = true;
                sceneClock->restart();
            }

        } else if (enterBar && !newParty) {
            if (elapsedMain2.asSeconds() < .1) {
                displayBlack(window);
                smallClock2.restart();
                spritePosition2 = 0;
                textBoxPos2 = 1080;
                fadeVal2 = 255;
            } else if (elapsedMain2.asSeconds() >= .1 && elapsedMain2.asSeconds() < 2.9) {
                string = "bar.png";
                fillBackground(window, &string, &fadeVal2, &smallClock2);
            } else if (elapsedMain2.asSeconds() >= 2.9 && elapsedMain2.asSeconds() < 3.0) {
                smallClock2.restart();
            } else if (elapsedMain2.asSeconds() >= 3.0 && elapsedMain2.asSeconds() < 4.3) {
                string = "samurai.png";
                string1 = "barStranger.png";
                string2 = "bar.png";
                enterPressed = 0;
                slideInSprites(window, &string2, &spritePosition2, &smallClock2, &textBoxPos2, &string, &string1,
                               &samuraiConcern, &brotherStern);
            } else {
                inBarScript(window, &enterPressed);
            }
            if (enterPressed > 17) {
                newParty = true;
                barNoise.stop();
                sceneClock->restart();
            }
            //play bar
            if (elapsedMain2.asSeconds() <.1){
                if (!barNoise.openFromFile("bar crowd.wav"))
                    std::cout << "cant play" << std::endl; // error
            }else if(elapsedMain2.asSeconds() >= .1 && elapsedMain2.asSeconds() < .2){
                barNoise.play();
                barNoise.setVolume(5);
            }

        } else {
            if (elapsedMain2.asSeconds() < .1) {
                displayBlack(window);
                smallClock2.restart();
                spritePosition2 = 0;
                textBoxPos2 = 1080;
                fadeVal2 = 255;
            } else if (elapsedMain2.asSeconds() >= .1 && elapsedMain2.asSeconds() < 2.5) {
                string = "Bary has joined the party.";
                partyJoin(window, &string, &smallClock2);
            } else if (elapsedMain2.asSeconds() >= 2.5 && elapsedMain2.asSeconds() < 2.6) {
                enterPressed = 0;
                partyBaryNoise.stop();
            } else if (elapsedMain2.asSeconds() >= 2.6) {
                afterPartyScript(window, &enterPressed);
                moveOn = true;
            }
            //play bary party
            if (elapsedMain2.asSeconds() <.1){
                if (!partyBaryNoise.openFromFile("partyjoin.wav"))
                    std::cout << "cant play" << std::endl; // error
            }else if(elapsedMain2.asSeconds() >= .1 && elapsedMain2.asSeconds() < .2){
                partyBaryNoise.play();
            }

            //play break in bar
            if (elapsedMain2.asSeconds() <.1){
                if (!breakIn.openFromFile("break in bar.wav"))
                    std::cout << "cant play" << std::endl; // error
            }else if(elapsedMain2.asSeconds() >= 2.6 && elapsedMain2.asSeconds() < 2.7){
                breakIn.play();
                breakIn.setVolume(5);
            }
        }
        if (enterPressed > 1 && elapsedMain2.asSeconds() >= 2.6 && newParty && moveOn) {
            sceneClock->restart();
            breakIn.stop();
            return battle2;
        }
    }

}
