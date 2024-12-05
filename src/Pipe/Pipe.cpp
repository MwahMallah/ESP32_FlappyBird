#include "Pipe.hpp"

void Pipe::update() {
    x -= pipeSpeed;
}

void Pipe::clear() {
    if (x - width / 2 >= Display::width)
        return;

    //fill upper part
    const int upperSize = y - size / 2;
    disp.fillRect(x - width / 2, 0, width, upperSize, BG);

    //fill down part
    const int downY = y + size / 2;
    const int downSize = downY - Display::height;

    int16_t aboveHillHeight = hillY - downY; //hero height above the hill
    int16_t belowHillHeight = Display::height - hillY; //hero height below the hill

    disp.fillRect(x, downY, width, aboveHillHeight, BG);
    disp.fillRect(x, hillY, width, belowHillHeight, GREEN);
}

void Pipe::draw() {
    if (x - width / 2 >= Display::width)
        return;

    //fill upper part
    const int upperSize = y - size / 2;
    disp.fillRect(x - width / 2, 0, width, upperSize, PIPE);

    //fill down part
    const int downY = y + size / 2;
    const int downSize = Display::height - downY;
    disp.fillRect(x - width / 2, downY, width, downSize, PIPE);
}