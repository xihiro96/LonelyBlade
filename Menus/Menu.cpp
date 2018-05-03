//
// Created by Kevin Jones
//

#include <SFML/Audio/Music.hpp>
#include "Menu.h"

Menu::Menu(float width, float height) {
    if(!menu_font.loadFromFile("advanced_pixel_lcd-7.ttf")) {
        //handle error
        std::cout << "Error: Font can't be loaded" << std::endl;
    }
    if(!title_image.loadFromFile("lonely blade IV.jpg", sf::IntRect(0, 0, 640, 87))) {
        //handle error
        std::cout << "Error: Image can't be loaded" << std::endl;
    }

    sprite_title.setTexture(title_image);
    sprite_title.setPosition(sf::Vector2f((width/2)-(width/4), height/(MAX_ITEMS + 2) * .5));
    menu_text[0].setFont(menu_font);
    menu_text[0].setColor(sf::Color::Red);
    menu_text[0].setString("Play");
    menu_text[0].setPosition(sf::Vector2f((width/2)-(width/4)+(width/8)+80, height/(MAX_ITEMS + 2) * 2));

    menu_text[1].setFont(menu_font);
    menu_text[1].setColor(sf::Color::Black);
    menu_text[1].setString("Options");
    menu_text[1].setPosition(sf::Vector2f((width/2)-(width/4)+(width/8)+40, height/(MAX_ITEMS + 2) * 3));

    menu_text[2].setFont(menu_font);
    menu_text[2].setColor(sf::Color::Black);
    menu_text[2].setString("Exit");
    menu_text[2].setPosition(sf::Vector2f((width/2)-(width/4)+(width/8)+80, height/(MAX_ITEMS + 2) * 4));


    selectedItemIndex = 0;
}

Menu::~Menu() {

}

void Menu::MoveUp() {
    if (selectedItemIndex - 1 >= 0) {
        menu_text[selectedItemIndex].setColor(sf::Color::Black);
        selectedItemIndex--;
        menu_text[selectedItemIndex].setColor(sf::Color::Red);
    }
}
void Menu::MoveDown() {
    if (selectedItemIndex + 1 < MAX_ITEMS) {
        menu_text[selectedItemIndex].setColor(sf::Color::Black);
        selectedItemIndex++;
        menu_text[selectedItemIndex].setColor(sf::Color::Red);
    }
}

void Menu::draw(sf::RenderWindow &window) {
    for(int i = 0; i < MAX_ITEMS; i++){
        window.draw(sprite_title);
        window.draw(menu_text[i]);
    }
}

GameState Menu::runMenu(Menu input_menu, sf::RenderWindow * window){
    //play forest sounds
    sf::Music mainMenuMusic;
    if (!mainMenuMusic.openFromFile("mainMenu.wav")) {
        std::cout << "cant play" << std::endl; // error
    }
    mainMenuMusic.play();
    mainMenuMusic.setLoop(1);

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
                        case sf::Keyboard::Up:
                            input_menu.MoveUp();
                            break;
                        case sf::Keyboard::Down:
                            input_menu.MoveDown();
                            break;
                        case sf::Keyboard::Return:
                            switch (input_menu.GetPressedItem()) {
                                case 0:
                                    std::cout << "Play button has been pressed" << std::endl;
                                    return scene1A;

                                    break;
                                case 1:
                                    std::cout << "Option button has been pressed" << std::endl;
                                    break;
                                case 2:
                                    window->close();
                                    break;

                            }
                            // we don't process other types of events
                    }


            }

        }

        window->clear(sf::Color::White);
        input_menu.draw(*window);
        window->display();

    }
}