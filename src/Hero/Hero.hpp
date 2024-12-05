#ifndef __HERO_HPP
#define __HERO_HPP

#include <Adafruit_GFX.h>
#include <TFT_ILI9163C.h>
#include "Display/Display.hpp"

#include "../Utils/Colors.hpp"
#include "../Utils/Layout.hpp"

#define BODY RED
#define WING 0x9806
#define BEAK 0xFF01

//three images of hero that changes from frame to frame 
const uint16_t heroBitmaps[][12][18] = 
{
    //first hero bitmap
    {
        {BG, BG, BG, BG, BG, BG, BG, BG, BG, BG, BG, BLACK, BLACK, BLACK, BLACK, BG, BG, BG},
        {BG, BLACK, BLACK, BLACK, BLACK, BG, BG, BG, BG, BG, BLACK, BODY, BODY, BODY, BODY, BLACK, BG, BG},
        {BLACK, WING, WING, WING, WING, BLACK, BLACK, BLACK, BLACK, BLACK, BODY, BODY, WHITE, BLACK, BEAK, BEAK, BLACK, BG},
        {BLACK, BLACK, WING, WING, WING, WING, WING, BLACK, BODY, BODY, BODY, BODY, BODY, BEAK, BEAK, BEAK, BEAK, BLACK},
        {BG, BLACK, WING, WING, WING, WING, BLACK, BODY, BODY, BODY, BODY, BODY, WHITE, WHITE, BLACK, BLACK, BLACK, BG},
        {BG, BG, BLACK, BLACK, BLACK, BLACK, BODY, BODY, BODY, BODY, BLACK, WHITE, WHITE, WHITE, BLACK, BG, BG, BG},
        {BG, BG, BG, BG, BLACK, BODY, BODY, BODY, BODY, BLACK, WHITE, WHITE, WHITE, BLACK, WING, BG, BG, BG},
        {BG, BG, BG, BG, BLACK, BODY, BODY, BODY, BLACK, WHITE, WHITE, BLACK, BLACK, WING, WING, BLACK, BG, BG},
        {BG, BG, BG, BG, BLACK, BODY, BODY, BODY, BLACK, BLACK, BLACK, WHITE, BLACK, WING, WING, BLACK, BG, BG},
        {BG, BG, BG, BG, BG, BLACK, BODY, BODY, BLACK, BG, BG, BG, BG, BLACK, BLACK, BG, BG, BG},
        {BG, BG, BG, BG, BG, BLACK, BODY, BODY, BLACK, BG, BG, BG, BG, BG, BG, BG, BG, BG},
        {BG, BG, BG, BG, BG, BG, BLACK, BLACK, BG, BG, BG, BG, BG, BG, BG, BG, BG, BG},
    },
    //second hero bitmap
    {
        {BG, BG, BG, BG, BG, BG, BG, BG, BG, BG, BG, BLACK, BLACK, BLACK, BLACK, BG, BG, BG},
        {BG, BLACK, BLACK, BLACK, BLACK, BG, BG, BG, BG, BG, BLACK, BODY, BODY, BODY, BODY, BLACK, BG, BG},
        {BLACK, WING, WING, WING, WING, BLACK, BLACK, BLACK, BLACK, BLACK, BODY, BODY, WHITE, BLACK, BEAK, BEAK, BLACK, BG},
        {BLACK, BLACK, WING, WING, WING, WING, WING, BLACK, BODY, BODY, BODY, BODY, BODY, BEAK, BEAK, BEAK, BEAK, BLACK},
        {BG, BLACK, WING, BLACK, BLACK, BLACK, BLACK, BODY, BODY, BODY, BODY, BODY, WHITE, WHITE, BLACK, BLACK, BLACK, BG},
        {BG, BG, BLACK, BODY, BODY, BODY, BODY, BODY, BODY, BODY, BLACK, WHITE, WHITE, WHITE, BLACK, BG, BG, BG},
        {BG, BLACK, BODY, BODY, BODY, BODY, BODY, BODY, BLACK, BLACK, WHITE, WHITE, WHITE, BLACK, BLACK, BG, BG, BG},
        {BG, BLACK, BLACK, BODY, BODY, BODY, BODY, BLACK, WHITE, WHITE, WHITE, BLACK, BLACK, BG, BG, BG, BG, BG},
        {BG, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BG, BG, BG, BG, BG, BG, BG},
        {BG, BG, BG, BG, BG, BG, BG, BG, BG, BG, BG, BG, BG, BG, BG, BG, BG, BG},
        {BG, BG, BG, BG, BG, BG, BG, BG, BG, BG, BG, BG, BG, BG, BG, BG, BG, BG},
        {BG, BG, BG, BG, BG, BG, BG, BG, BG, BG, BG, BG, BG, BG, BG, BG, BG, BG},
    }    
};

class Hero {
    int x;
    int y;
    int animationNum;
    double g;
    TFT_ILI9163C& _disp;
    const int heroBitmapHeight = 12;
    const int heroBitmapWidth = 18;
    const double jmpVelocity = 1.5;
    double velocity;
public:
    Hero() : x(10), y(50), _disp(Display::getInstance()), velocity(0), g(0.3), animationNum(0)
        {}
    void update();
    void draw();
    void clear();
    void jump();
    double currSpeed() {return velocity;}
}; 

#endif