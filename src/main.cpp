#include <Arduino.h>
#include <SPI.h>

#include "Display/Display.hpp"
#include "UserControl/UserControl.hpp"

#include "Scene/Scene.hpp"
#include "Hero/Hero.hpp"
#include "Counter/Counter.hpp"

const int ledPin = 16;

void update(Scene& scene, Hero& hero, UserControl& control, bool& gameRunning) {
    // check for data from Bluetooth 
    if (control.hasInput()) {
        PlayerAction action = control.getInput();
        
        // handle received action
        if (action == PlayerAction::JUMP) {
            hero.jump();
            Serial.println(hero.currSpeed());
        } 
    }

    scene.update();

    if (scene.heroScored()) {
        scene.increaseCounter();
    }

    if (scene.heroCollided()) {
        scene.showMessage("Scored: " + String(scene.getScore()));
        gameRunning = false;
    }

    delay(70);
}

void setup() {
    bool gameRunning = true;
    UserControl control;

    Hero hero;
    Counter counter;
    Scene scene(hero, counter);

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

    //wait until player connects via bluetooth serial
    control.waitPlayer();

    //initialize new scene without messages
    scene.init();
    scene.initCounter();

    //game loop
    while (gameRunning) {
        update(scene, hero, control, gameRunning);
    }
}

void loop()
{

}