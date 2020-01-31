#include <thread>
#include "Import.h"


bool leftKey(false), rightKey(false), upKey(false), downKey(false);
vector<Character> characters = {};
RenderWindow window(VideoMode(SCREEN_SIZE_X, SCREEN_SIZE_Y), "ThisGame");



void checkInput() {
    Event event;
    while (window.pollEvent(event)) {
        if (event.type == Event::Closed) {
            window.close();
        } else if (event.type == Event::KeyPressed) {
            switch (event.key.code) {
                case Keyboard::Escape:
                case Keyboard::Q:
                    window.close();
                    break;
                case Keyboard::W:
                case Keyboard::Up:
                    upKey = true;
                    break;
                case Keyboard::A:
                case Keyboard::Left:
                    leftKey = true;
                    break;
                case Keyboard::S:
                case Keyboard::Down:
                    downKey = true;
                    break;
                case Keyboard::D:
                case Keyboard::Right:
                    rightKey = true;
                    break;
                case Keyboard::Num1:
                    if (MAX_CHARS > 0) {
                        charControl = 0;
                    }
                    break;
                case Keyboard::Num2:
                    if (MAX_CHARS > 1) {
                        charControl = 1;
                    }
                    break;
                case Keyboard::Num3:
                    if (MAX_CHARS > 2) {
                        charControl = 2;
                    }
                    break;
                case Keyboard::Num4:
                    if (MAX_CHARS > 3) {
                        charControl = 3;
                    }
                    break;
            }
        } else if (event.type == Event::KeyReleased) {
            switch (event.key.code) {
                case Keyboard::W:
                case Keyboard::Up:
                    upKey = false;
                    break;
                case Keyboard::A:
                case Keyboard::Left:
                    leftKey = false;
                    break;
                case Keyboard::S:
                case Keyboard::Down:
                    downKey = false;
                    break;
                case Keyboard::D:
                case Keyboard::Right:
                    rightKey = false;
                    break;
            }
        }

    }
}

void update() {
    for (Character c : characters) {
        c.move();
    }
}

void doScreen() {
    window.display();
    update();
}

int main() {

    srand(time(NULL));


    int mouseX = SCREEN_SIZE_X / 2, mouseY = SCREEN_SIZE_Y / 2;

    window.requestFocus();
    window.setMouseCursorVisible(false);
    window.setFramerateLimit(60);

    while( window.isOpen() ) {
        checkInput();
        std::thread screenManager(doScreen);
//        Vector2i mouse = Mouse::getPosition(window);
//        if (0 < mouse.x and mouse.x < SCREEN_SIZE and 0 < mouse.y and mouse.y < SCREEN_SIZE) {
//            mouseX = mouse.x;
//            mouseY = mouse.y;
//        } else {
//            mouseX = SCREEN_SIZE / 2;
//            mouseY = SCREEN_SIZE / 2;
//        }

        window.clear(Color::Black);

//        RectangleShape rect;
//        rect.setPosition(0, 0);
//        rect.setSize(Vector2f(1, 1));
//        rect.setFillColor(Color::White);
//        window.draw(rect);
        if (leftKey) {
            cout << "left";
        }

        screenManager.join();

    }
    return 0;
}