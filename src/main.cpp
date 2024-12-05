#include <Arduino.h>
#include <SPI.h>

#include "Scene/Scene.hpp"
#include "Hero/Hero.hpp"
#include "Display/Display.hpp"
#include "UserControl/UserControl.hpp"

const int ledPin = 16;

void update(Scene& scene, Hero& hero, UserControl& control) {
    // check for data from Bluetooth 
    if (control.hasInput()) {
        PlayerAction action = control.getInput();
        
        // handle received action
        if (action == PlayerAction::JUMP) {
            hero.jump();
            Serial.println(hero.currSpeed());
        } 
        // else if (received == "ON") {
        //     digitalWrite(ledPin, HIGH); // turn led on
        // } 
    }

    scene.update();
    delay(70);
}

void setup() {
    Hero hero;
    Scene scene(hero);
    UserControl control;

    Serial.begin(9600);
    Serial.println("ESP32 Initialized");
    pinMode(ledPin, OUTPUT);

    // Bluetooth initialization
    control.init();
    Serial.println("Bluetooth Initialized");

    //initialize scene with message "Connect player"
    scene.init();
    Serial.println("Scene Initialized");
    scene.showMessage("Connect Player");

    control.waitPlayer();

    //initialize new scene without messages
    scene.init();

    //game loop
    while (true) {
        update(scene, hero, control);
    }
}

void loop()
{

}