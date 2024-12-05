#ifndef __COUNTER_HPP
#define __COUNTER_HPP

#include "../Display/Display.hpp"
#include "../Utils/Colors.hpp"

class Counter {
    TFT_ILI9163C& _disp;
    int currVal;
    int cntPosX;
    const int cntPosY;
    void initCursor();
public:
    Counter() : _disp(Display::getInstance()), currVal(0), cntPosX(105), cntPosY(10)
        {}
    void draw();
    void increaseCounter();
    int getScore();
};

#endif