#include "Counter.hpp"

void Counter::initCursor() {
    //set white text on background color
    _disp.setTextSize(2);
    _disp.setTextColor(WHITE, BG);
    _disp.setCursor(cntPosX, cntPosY);
}

void Counter::draw() {
    initCursor();
    _disp.print(currVal);
}

void Counter::increaseCounter() {
    currVal++;

    //set new counter position to make room for new digit
    if (currVal == 10) {
        const int digitSize = 12;
        cntPosX -= digitSize;
    }
}

int Counter::getScore()
{
    return currVal;
}
