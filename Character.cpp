#include "Character.h"

float len2f(Vector2f v) {
    return sqrt(pow(v.x, 2) + pow(v.y, 2));
}

Vector2f normalized(Vector2f v) {
    return v / len2f(v);
}

Character::Character(Sprite sprite, float speed, Vector2f pos, Vector2f targ) {
    this->sprite = sprite;
    this->speed = speed;
    this->pos = pos;
    this->targ = targ;
}

void Character::correctPos() {
    if (pos.x < 0) {
        pos.x = 0;
    } else if (pos.x > SCREEN_SIZE_X) {
        pos.x = SCREEN_SIZE_X;
    }
    if (pos.y < 0) {
        pos.y = 0;
    } else if (pos.y > SCREEN_SIZE_Y) {
        pos.y = SCREEN_SIZE_Y;
    }
}

void Character::move() {
    pos += speed * normalized(targ - pos);
    correctPos();
}

Vector2f Character::getPos() {
    return pos;
}

void Character::setPos(Vector2f newPos) {
    pos = newPos;
    correctPos();
}

Vector2f Character::getTarg() {
    return targ;
}

void Character::setTarg(Vector2f newTarg) {
    targ = newTarg;
}

void Character::moveTarg(Vector2f offset) {
    targ += offset;
}

Sprite Character::getSprite() {
    return sprite;
}
