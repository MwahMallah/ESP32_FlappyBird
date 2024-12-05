#include "Pipe.hpp"

void Pipe::update() {
    x -= pipeSpeed;
}

void Pipe::clear() {
    if (x - width / 2 >= Display::width)
        return;

    int leftPipeWallX = x - width / 2;
    int visiblePipeWidth = leftPipeWallX > 0 ? width : width + leftPipeWallX;
    int startX = leftPipeWallX > 0 ? leftPipeWallX : 0;

    if (visiblePipeWidth <= 0) 
        return;

    //fill upper part
    const int upperSize = y - size / 2;
    disp.fillRect(startX, 0, visiblePipeWidth, upperSize, BG);

    //fill down part
    const int downY = y + size / 2;
    const int downSize = downY - Display::height;

    //pipe height above the hill
    int16_t aboveHillHeight = hillY - downY; 
    //pipe height below the hill
    int16_t belowHillHeight = Display::height - hillY + 1; 

    disp.fillRect(startX, downY, visiblePipeWidth, aboveHillHeight, BG);
    disp.fillRect(startX, hillY, visiblePipeWidth, belowHillHeight, GREEN);
}

void Pipe::draw() {
    if (x - width / 2 >= Display::width)
        return;

    //fill upper part
    int leftPipeWallX = x - width / 2;
    int visiblePipeWidth = leftPipeWallX > 0 ? width : width + leftPipeWallX;
    int startX = leftPipeWallX > 0 ? leftPipeWallX : 0;

    if (visiblePipeWidth <= 0) 
        return;

    const int upperSize = y - size / 2;
    disp.fillRect(startX, 0, visiblePipeWidth, upperSize, PIPE);

    //fill down part
    const int downY = y + size / 2;
    const int downSize = Display::height - downY;
    disp.fillRect(startX, downY, visiblePipeWidth, downSize, PIPE);
}

bool Pipe::isVisible() {
    int rightPipeWallX = x + width / 2;
    return rightPipeWallX > 0;
}
