#include "move.h"

Move::Move() {
    exists = false;
}
// Unused
// Move Name
// Damage Value
// Cooldown Value
// Damage Type
// Animation to use
Move::Move(std::string movename, int dmgVal, int cdVal, int dmgType, std::string anim) {
    name = movename;
    damage = dmgVal;
    damageType = dmgType;
    cooldown = cdVal;
    currentCooldown = 0;
    isReady = true;
    moveUsed = false;
    exists = true;
    textured = false;
}
Move::Move(std::string movename, int dmgVal, int cdVal, int dmgType, std::string anim, sf::Texture *tex1, sf::Texture *tex2) {
    name = movename;
    damage = dmgVal;
    damageType = dmgType;
    cooldown = cdVal;
    currentCooldown = 0;
    isReady = true;
    moveUsed = false;
    exists = true;
    texture = tex1;
    texture2 = tex2;
    textured = true;
}
void Move::update() {
    if (!isReady && currentCooldown > 0) {
        currentCooldown--;
    }
    if (moveUsed) {
        isReady = false;
        currentCooldown = cooldown;
    }
    if (currentCooldown == 0) {
        isReady = true;
    }
}
