#ifndef SFML_TEMPLATE_CHARACTER_H
#define SFML_TEMPLATE_CHARACTER_H

#include "Shared.h"

class Character {
private:
    Vector2f pos, targ;
    float speed;
    Sprite sprite;
public:
    Character(Sprite sprite, float speed, Vector2f pos=Vector2f(0, 0), Vector2f targ=Vector2f(0, 0));

    void correctPos();
    void move();

    Vector2f getPos();
    void setPos(Vector2f newPos);
    Vector2f getTarg();
    void setTarg(Vector2f newTarg);
    void moveTarg(Vector2f offset);
    Sprite getSprite();
};


#endif
