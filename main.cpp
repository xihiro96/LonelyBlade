#include "Scenes/Scene1.h"
#include "Scenes/Scene2.h"
#include "Scenes/Scene3.h"
#include "Scenes/Scene4.h"
#include "Menus/Menu.h"
#include "Menus/Credits.h"
int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Lonely Blade IV", sf::Style::Default); //create 1080p window with close button
    window.setVerticalSyncEnabled(true); //game will update according to graphics card settings
    GameState gameState = mainMenu;
    sf::Clock sceneClock;
    Menu menu(window.getSize().x, window.getSize().y);
    bool runningGame = true;

    while(runningGame) {

        switch (gameState) {
            case mainMenu:
                gameState = menu.runMenu(menu, &window);
                break;
            case scene1A:
                sceneClock.restart();
                gameState = runScene1(&window, &sceneClock);
                break;
            case scene1B:
                sceneClock.restart();
                gameState = runScene1B(&window, &sceneClock);
                break;
            case scene2A:
                sceneClock.restart();
                gameState = runScene2A(&window, &sceneClock);
                break;
            case scene2B:
                sceneClock.restart();
                gameState = runScene2B(&window, &sceneClock);
                break;
            case scene3A:
                sceneClock.restart();
                gameState = runScene3A(&window, &sceneClock);
                break;
            case scene3B:
                sceneClock.restart();
                gameState = runScene3B(&window, &sceneClock);
                break;
            case scene4A:
                sceneClock.restart();
                gameState = runScene4A(&window, &sceneClock);
                break;
            case scene4B:
                sceneClock.restart();
                gameState = runScene4B(&window,&sceneClock);
                break;
            case credits:
                sceneClock.restart();
                gameState = roleCredits(&window,&sceneClock);
                std::cout << gameState << std::endl;
                break;
            default:
                std::cout << "No existing Gamestate reached" << std::endl;
                runningGame = false;
                break;
        }

    }
    return 0;

}