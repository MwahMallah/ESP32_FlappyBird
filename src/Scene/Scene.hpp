#ifndef __SCENE_HPP
#define __SCENE_HPP

#include "../Hero/Hero.hpp"
#include "../Pipe/Pipe.hpp"

#include "../Display/Display.hpp" 

#include "../Utils/Colors.hpp"
#include "../Utils/Layout.hpp"

#include <vector>

//Scene class, that represent current scene
class Scene {
    TFT_ILI9163C& disp;
    Hero& _hero;
    std::vector<Pipe*> pipes;
    void remove_unvisible_pipes();
public:
    //initialize tft display in constructor
    Scene(Hero& hero) : disp(Display::getInstance()), _hero(hero)
        {}
    void init();
    void update();
    void draw();
    void showMessage(String msg);
};

#endif