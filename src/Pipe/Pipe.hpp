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
public:
    Pipe() : disp(Display::getInstance()), width(10) {
        const int minDeltaY = 30;
        const int maxDeltaY = 30; 

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
};

#endif