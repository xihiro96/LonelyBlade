#include "character.h"
Character::Character(bool dead, sf::Texture *texture):
        animation(texture, sf::Vector2u(0,0),0.0f) {
    alive = selected = faceRight = faceTop = moving = isSelect = isSelected = false;
    skillExecuted = true;
    health = maxhealth = mana = maxmana = attackTimer = speed = 0.0f;
    x = y = row = 0;

}

Character::Character(int posx, int posy, float hp, float mp, std::vector<Move> dMoves, std::vector<Move> oMoves,
                     sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, Character* dummyChar) :
        animation(texture, imageCount, switchTime)
{
    alive = true;
    x = posx;
    y = posy;
    health = hp;
    maxhealth = hp;
    mana = mp;
    maxmana = mp;
    defenseMoves = dMoves;
    offenseMoves = oMoves;

    drawing.setPosition(x, y);
    drawing.setSize(sf::Vector2f(width, height));



    //additional variable settings from Player.cpp
    this->speed = speed;
    row = 0;
    faceRight = true;
    drawing.setTexture(texture);
    setOrigPos(sf::Vector2f((float)posx,(float)posy));

    //init battle targeting vars
    isSelect = false;
    isSelected = false;

    //set dummy target; DO NOT use setTarget() function -- see function implementation for details
    target = dummyChar;

    //default skillExecuted is true
    skillExecuted = true;
}

//For movement on a map; may not need
void Character::update(float deltaTime, sf::Vector2f enemyPos, sf::Vector2f origPos, bool isAttack){
    velocity.x = 0.0f;
    velocity.y = 0.0f;

    if(velocity.x == 0.0f){
        row = 0;
        moving = false;
    }
    else{
        moving = true;
        row = 2;
        if(velocity.x > 0.0f)
            faceRight = true;
        else
            faceRight = false;
    }

    //animation and movement
    animation.update(row, deltaTime, faceRight, faceTop, moving);
    drawing.setTextureRect(animation.uvRect);
    drawing.move(velocity*deltaTime);
}

//For movement and animation in battle

bool Character::updateAttack(float deltaTime, sf::Vector2f enemyPos, bool isAttack, float attackTimer, float moveTime, bool* battlePaused, float* frameCounter){   //total animation time ~ 25 deltaTimes
    bool skillDone = false;
    float xVel = (enemyPos.x - origPos.x)/(moveTime); //moving forward and back takes moveTime seconds
    bool needToMove = false;
    bool needToMove2 = false;
    if (xVel > 0 && enemyPos.x - 100 > getPosition().x) {
        needToMove = true;
    }
    if (xVel < 0 && enemyPos.x + 100 < getPosition().x) {
        needToMove = true;
    }
    if (xVel > 0 && getPosition().x > origPos.x) {
        needToMove2 = true;
    }
    if (xVel < 0 && getPosition().x < origPos.x) {
        needToMove2 = true;
    }
    if(needToMove && isAttack) {	//Char is moving to target
        moving = true;
        float slope = (enemyPos.y - getPosition().y) / (enemyPos.x - getPosition().x);
        velocity.x = xVel;
        velocity.y = slope * velocity.x;
        printf("\nMoving to target\n");
    }else if(isAttack){ //char attack animation; stays in front of enemy
        moving = false;
        velocity.x = 0.0f;
        velocity.y = 0.0f;
        printf("\nAttack Executing\n");
    }else if(needToMove2){	//char is finished attacking; moving back to original position
        moving = true;
        float slope = (enemyPos.y - getPosition().y) / (enemyPos.x - getPosition().x);
        velocity.x = -xVel;
        velocity.y = slope * velocity.x;
    }else{	//reset char to original position

        moving = false;
        velocity.x = 0.0f;
        velocity.y = 0.0f;
        drawing.setPosition(origPos);
        isSelect = false;   //finish updateAttacking
//        *battlePaused = true;   //complete battle animation
        if(*frameCounter >= attackTimer){
            *frameCounter -= attackTimer;
        }else if(*frameCounter >= attackTimer/2){
            *frameCounter -= attackTimer/2;
        }
        printf("\nBattle animation ended; reset\n");
        printf("\nisAttacking: %i\n",isAttacking);
        printf("\nframeCount: %f\n",*frameCounter);
        printf("\nattackTimer: %f\n", attackTimer);
        skillDone = true;
    }
    if(!isAttack && !skillExecuted){
        //Do whatever the skill does here
        skillExecuted = true;
        printf("\nSkill executed\n");
        switch (skill.damageType) {
            case 1:
                target->health += skill.damage;
                if (target->health >= target->maxhealth) {
                    target->health = target->maxhealth;
                }
                break;
            case 0:
                target->health -= skill.damage;
                if (target->health <= 0) {
                    target->alive = false;
                }
                break;
        }
    }
    moving = false;
    //animation and movement
    animation.updateAttack(deltaTime, isAttack, moving, attackTimer/2 - moveTime);
    drawing.setTextureRect(animation.uvRect);
    drawing.move(velocity*deltaTime);
    return skillDone;
}

//Draw char to window
void Character::draw(sf::RenderWindow& window){
    window.draw(drawing);
}


sf::Vector2f Character::getPosition(){
    return drawing.getPosition();
}


sf::Vector2f Character::getSize(){
    return drawing.getSize();
}


//Use on-click
void Character::setOrigPos(sf::Vector2f coords){
    origPos = coords;
}


sf::Vector2f Character::getOrigPos() {
    return origPos;
}

//Pushes animation sprites onto animation vector; see Animation.h
void Character::initAttack() {  //TO DO: Update to fill with move-specific animations

    animation.attackAnimationFill();
}

void Character::setPartyNumber(int num) {
    partyNum = num;
}

bool Character::movementUpdate(float deltaTime, float attackTimer, float* frameCounter, bool* battlePaused){    //TO DO: Update to check for move selected; change animation based on move
    bool skillDone = false;
    if(!*(battlePaused) && isSelect){
//        printf("\nDeltaTime: %f\n",deltaTime);
        if(target->isSelected) { //attack initiated
//            isSelect = false;
            target->isSelected = false;
            printf("\nAttack initiated\n");
            isAttacking = true;
        }
        if(*frameCounter < attackTimer && isAttacking){
            *frameCounter += deltaTime;
            printf("\nFrameCounter incremented\n");
            skillDone = updateAttack(deltaTime, target->getPosition(), *frameCounter < attackTimer / 2, attackTimer, 1, battlePaused, frameCounter);
            printf("\nAttack animation updated\n");
        }else if(isAttacking) {
            *frameCounter -= attackTimer;
            isAttacking = false;
            printf("\nMain attack animation ended\n");
        }
    }else {
        update(deltaTime, sf::Vector2f(0.0f, 0.0f), sf::Vector2f(0.0f, 0.0f), false);
    }
    return skillDone;
}

int Character::getPartyNum() {
    return partyNum;
}

void Character::setTarget(Character *target,int moveSelect, std::vector<Move>moves) {  //POSSIBLE TO DO: Update to handle move-specific animations
    this->target = target;
    target->isSelected = true;
    initAttack();
    skillExecuted = false;

    //set skill
    skill = moves[moveSelect];
}