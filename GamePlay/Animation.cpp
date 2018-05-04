//
// Created by justi_000 on 4/28/2018.
//

#include "Animation.h"


Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime) {
    this->imageCount = imageCount;
    this->switchTime = switchTime;
    totalTime = 0.0f;
    currentImage.x = 0;
//
    //set sprite box sizes
    uvRect.width = texture->getSize().x/float(imageCount.x);
    uvRect.height = texture->getSize().y/float(imageCount.y);
}
//
//void Animation::initSize(sf::Texture *texture){
//    //set sprite box sizes
//    uvRect.width = texture->getSize().x/float(imageCount.x);
//    uvRect.height = texture->getSize().y/float(imageCount.y);
//}

Animation::~Animation() {}

void Animation::update(int row, float deltaTime, bool faceRight, bool faceTop, bool moving) {
    currentImage.y = row;   //set y-coordinate on spritesheet
    totalTime += deltaTime;

    if(totalTime >= switchTime){
        totalTime -= switchTime;
        currentImage.x++;   //switch to next image in row on spritesheet

        if(currentImage.x >= imageCount.x){ //hit end of row; go to next row
            currentImage.x = 0;
//            currentImage.y++;
        }
    }

    uvRect.top = currentImage.y * uvRect.height;    //uvrect top offset; row * height

    if(faceRight && moving){
        uvRect.left = currentImage.x * uvRect.width;    //uvrect left offset; col * width
        uvRect.width = abs(uvRect.width);
    }
    else{
        uvRect.left = (currentImage.x + 1) * abs(uvRect.width);
        uvRect.width = -abs(uvRect.width);
    }
//    else if(faceTop && moving){
////        uvRect.
//    }
}

void Animation::attackAnimationFill(){  //fill after selecting enemy
    attackAnimation.clear();
    attackAnimation.push_back(sf::Vector2u(2,0));
    attackAnimation.push_back(sf::Vector2u(2,1));
    attackAnimation.push_back(sf::Vector2u(2,3));
    attackAnimation.push_back(sf::Vector2u(2,2));
    attackAnimation.push_back(sf::Vector2u(2,0));
//    attackAnimation.push_back(sf::Vector2u(1,2));
//    attackAnimation.push_back(sf::Vector2u(2,2));
//    attackAnimation.push_back(sf::Vector2u(4,2));
//    attackAnimation.push_back(sf::Vector2u(3,2));
//    attackAnimation.push_back(sf::Vector2u(1,2));
}

bool Animation::attackAnimationExecute(){
    if(attackAnimation.empty())
        return false;
    else{
        sf::Vector2u currentAnimation = attackAnimation.back();
        uvRect.top = currentAnimation.y * uvRect.height;
        uvRect.left = currentAnimation.x * abs(uvRect.width);
        attackAnimation.pop_back();
        return true;
    }
}

void Animation::updateAttack(float deltaTime, bool isAttack, bool moving, float attackSwitchTime){
    totalTime += deltaTime;

    //Determine animation based on part of animation
    if(moving){ //Character is moving to attack, or Character is moving back to original spot
        uvRect.top = 1*uvRect.height;
        uvRect.left = 2*abs(uvRect.width);
    }else if(isAttack) { //Character is in front of enemy, attacking
        if(totalTime >= attackSwitchTime/5){
            totalTime -= attackSwitchTime/5;
            attackAnimationExecute();
            printf("Attack animation executed");
        }
    }else{  //Idling
        uvRect.top = 1 * uvRect.height;
        uvRect.left = 2 * abs(uvRect.width);
    }

}