//
// Created by justi_000 on 4/28/2018.
//

#ifndef SFMLDEMO_ANIMATION_H
#define SFMLDEMO_ANIMATION_H
#include <SFML/Graphics.hpp>
#include <vector>

class Animation {
public:
    Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
    ~Animation();
//    void initSize(sf::Texture* texture);

    void update(int row, float deltaTime, bool faceRight, bool faceTop, bool moving);
    void attackAnimationFill();
    bool attackAnimationExecute();
    void updateAttack(float deltaTime, bool isAttack, bool moving, float attackSwitchTime);
public:
    sf::IntRect uvRect;

private:
    sf::Vector2u imageCount;
    sf::Vector2u currentImage;

    float totalTime;
    float switchTime;

    //vector holding dummy attack animation (spin)
    std::vector<sf::Vector2u> attackAnimation;
};


#endif //SFMLDEMO_ANIMATION_H
