//#include "move.h"
#include "MoveMenu.h"
#include <vector>
#include "Animation.h"

class Character {
public:
    bool alive;
    bool selected;	//Indicates selection for movement
    float attackTimer;	//Time for attack animation in seconds. MoveTime variable in updateAttack() should be less than attackTimer/2
    int x;
    int y;
    static constexpr float width = 100.0f;
    static constexpr float height = 100.0f;
    float health;
    float maxhealth;
    float mana;
    float maxmana;

    sf::RectangleShape drawing;

    std::vector<Move> defenseMoves;
    std::vector<Move> offenseMoves;
    Character(bool dead, sf::Texture* texture);


    //Updated Character constructor, added new public functions and private vars
    Character(int posx, int posy, float hp, float mp, std::vector<Move> dMoves, std::vector<Move> oMoves, sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, Character* dummyChar);	//new args:
    //texture = spritesheet.png, imageCount = # images on sheet in (cols, rows), switchTime = time before switching to next frame in idle animation, speed = char speed for walking (might not be necessary)
    //void initTexture(sf::Texture* texture);	//initializes texture after reading it in main
//    ~Character();
    void update(float deltaTime, sf::Vector2f enemyPos, sf::Vector2f origPos, bool isAttack);    //may not need; mostly for idle animation
    void draw(sf::RenderWindow& window);	//draws char to window
    bool updateAttack(float deltaTime, sf::Vector2f enemyPos, bool isAttack, float attackTimer, float moveTime, bool* battlePaused, float* frameCounter);	//returns true when char skill execute animation finishes
    //animation updates to attack; isAttack = char attacking? or retreating (T/F); attackTimer = attack animation total time, seconds; moveTime = amt of time character takes to move to target
    sf::Vector2f getPosition();
    sf::Vector2f getSize();
    void setOrigPos(sf::Vector2f coords);	//for x-distance calculations in updateAttack()
    sf::Vector2f getOrigPos();	//may be unnecessary
    void initAttack();	//fills animation vector of sprites for attack animation
    void setPartyNumber(int num);
    bool movementUpdate(float deltaTime, float attackTimer, float* frameCounter, bool* battlePaused);	//returns when skill animation finishes; increment turn and pause battle in main


private:
    //sf::RectangleShape body;
    Animation animation;
    unsigned int row;
    float speed;
    bool faceRight;	//for map movement only; may not need
    bool faceTop;	//for map movement only; may not need
    bool moving;	//indicates if char is moving across battle during an attack animation
    std::string nameOfSpriteSheet;	//holds name of texture file to be read in main.cpp

    sf::Vector2f velocity;		//for map movement only; may not need
    sf::Vector2f origPos;	//for battle: calculations for moving char to enemy
    int partyNum;   //char position in vector

    //vars for updating battle animations
public:
    bool isSelect;      //is char targeting another char?
    bool isAttacking;   //is char executing attack animation?
    bool isSelected;    //is char target of another char?
    int getPartyNum();
    void setTarget(Character* target,int moveSelect, std::vector<Move>move);
private:
    Character* target;  //target
    bool skillExecuted; //determines whether char has used skill on target
    Move skill;         //skill to be used on target
};