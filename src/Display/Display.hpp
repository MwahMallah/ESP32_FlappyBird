#ifndef __DISPLAY_HPP
#define __DISPLAY_HPP

#include <Adafruit_GFX.h>
#include <TFT_ILI9163C.h>

// pin connections for ESP32
#define CS    5   // Chip Select pin
#define DC    2   // Data/Command pin
#define RESET 4   // Reset pin

//Singleton class for display
class Display {
    static TFT_ILI9163C* _instance;
    Display() {} // constructor is private

public:
    static TFT_ILI9163C& getInstance() {
        if (_instance == nullptr) {
            _instance = new TFT_ILI9163C(CS, DC, RESET); // init display
            _instance->begin();
        }
        return *_instance;
    }

    static const int height = 128;
    static const int width = 128;
};

#endif
