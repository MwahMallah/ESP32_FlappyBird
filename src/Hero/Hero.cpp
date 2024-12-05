#include "Hero.hpp"

void Hero::update() {
    // update y and velocity
    y += velocity;
    velocity += g;

    // check for collision at the bottom
    if (y >= Display::width - heroBitmapHeight) {
        y = Display::width - heroBitmapHeight; 
        velocity = 0;                      
    }

    // check for collision at upper bound
    if (y < 0) {
        y = 0;          
        velocity = 0;   
    }
}

void Hero::draw() {
    for (int i = 0; i < heroBitmapHeight; i++) {
        for (int j = 0; j < heroBitmapWidth; j++) {
            uint16_t pixelColor = heroBitmaps[animationNum][i][j];
            if (pixelColor != BG)
                _disp.drawPixel(x + j, y + i, pixelColor);
        }
    }

    animationNum = (animationNum + 1) % 2;
}

void Hero::clear() {
    if (y + heroBitmapHeight < hillY) {
        //if hero is above hill clear with background color
        _disp.fillRect(x, y, heroBitmapWidth, heroBitmapHeight, BG);
    } else if (y >= hillY) {
        //if hero is below hill clear with green color
        _disp.fillRect(x, y, heroBitmapWidth, heroBitmapHeight, GREEN);
    } else {
        //if hero is partially below and above hill
        int16_t aboveHillHeight = hillY - y; //hero height above the hill
        int16_t belowHillHeight = y + heroBitmapHeight - hillY; //hero height below the hill

        _disp.fillRect(x, y, heroBitmapWidth, aboveHillHeight, BG);
        _disp.fillRect(x, hillY, heroBitmapWidth, belowHillHeight, GREEN);
    }
}

void Hero::jump() {
    velocity -= jmpVelocity;
}

int Hero::getCenterX()
{
    return x + heroBitmapWidth / 2;
}

int Hero::getCenterY()
{
    return y + heroBitmapHeight / 2;
}