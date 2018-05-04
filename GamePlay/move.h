#include <string>
#include <SFML/Graphics.hpp>

class Move {
public:
    std::string name;
    int damage;
    int damageType;
    int cost;
    int cooldown;
    int currentCooldown;
    bool isReady;
    bool moveUsed;
    bool exists;
    sf::Texture *texture;
    sf::Texture *texture2;
    bool textured;
    Move();
    Move(std::string, int, int, int, std::string);
    Move(std::string, int, int, int, std::string, sf::Texture *, sf::Texture *);
    void update();
};