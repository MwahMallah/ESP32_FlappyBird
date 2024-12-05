#ifndef __PIPE_HPP
#define __PIPE_HPP

#include <Arduino.h>
#include "../Display/Display.hpp"

#include "../Utils/Layout.hpp"
#include "../Utils/Colors.hpp"

#define PIPE 0xECF7

class Pipe {
    int x, y;
    const int width;
    int size;
    int pipeSpeed;
    TFT_ILI9163C& disp;
    bool heroScored;

    //checks if other's object x is in pipes area
    bool inHorizontalArea(int x);
    //checks if other's object y is in pipes score area
    bool inVerticalScoreArea(int y);
public:
    Pipe() : disp(Display::getInstance()), width(10), heroScored(false) {
        const int minDeltaY = 40;
        const int maxDeltaY = 40; 

        const int minSize = 45;
        const int maxSize = 90;

        pipeSpeed = 2;

        y = random(0 + minDeltaY, Display::height - maxDeltaY);

        x = Display::width + 20;
        size = random(minSize, maxSize);
    }
    void update();
    void draw();
    void clear();
    bool isVisible();
    bool scored(int x, int y);
    bool collided(int x, int y);
};

#endif