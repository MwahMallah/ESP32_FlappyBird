#ifndef __SCENE_HPP
#define __SCENE_HPP

#include "../Hero/Hero.hpp"
#include "../Pipe/Pipe.hpp"
#include "../Counter/Counter.hpp"

#include "../Display/Display.hpp" 

#include "../Utils/Colors.hpp"
#include "../Utils/Layout.hpp"

#include <vector>

//Scene class, that represent current scene
class Scene {
    TFT_ILI9163C& disp;
    Hero& _hero;
    Counter& _counter;
    std::vector<Pipe*> pipes;
    void removeUnvisiblePipes();
    void spawnPipe();

    int frameCounter;
    //spawn rate in frames per spawn
    const int spawnRate;
public:
    //initialize tft display in constructor
    Scene(Hero& hero, Counter& counter) : disp(Display::getInstance()), _hero(hero), _counter(counter), frameCounter(0), spawnRate(40)
        {}
    void init();
    void initCounter();
    void update();
    void draw();
    void showMessage(String msg);
    bool heroScored();
    bool heroCollided();
    void increaseCounter();
    int getScore();
};

#endif