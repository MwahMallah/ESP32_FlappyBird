#include "UserControl.hpp"

bool UserControl::playerConnected() {
    return serial.hasClient();
}

void UserControl::init() {
    serial.begin("ESP32_PLAYER");
    serial.setTimeout(bt_timeout);
}

bool UserControl::hasInput() {
    return serial.available();
}

PlayerAction UserControl::getInput() {
    String received = serial.readString(); 
    received.trim(); 

    if (received == "UP") {
        return PlayerAction::JUMP;
    } 

    return PlayerAction::UNKNOWN;
}

void UserControl::waitPlayer() {
    while (!playerConnected())
    {
        delay(100);
    }
}