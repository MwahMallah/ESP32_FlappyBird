#ifndef __USER_CONTROL_HPP
#define __USER_CONTROL_HPP

#include <BluetoothSerial.h>

enum PlayerAction {
    JUMP, UNKNOWN
};

class UserControl {
    BluetoothSerial serial;
    const int bt_timeout;
public:
    UserControl() : bt_timeout(50)
        {}
    void init();
    bool playerConnected(); 
    bool hasInput();
    void waitPlayer();
    PlayerAction getInput();
};


#endif