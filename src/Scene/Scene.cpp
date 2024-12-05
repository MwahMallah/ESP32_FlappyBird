#include "Scene.hpp"

void Scene::init() {
    disp.fillScreen(CYAN);
    disp.fillRect(0, hillY, Display::width, Display::height - hillY, GREEN);
    _hero.draw();

    pipes.push_back(Pipe());
}

void Scene::update() {
    _hero.clear();
    _hero.update();
    _hero.draw();

    for (auto& pipe : pipes) {
        pipe.clear();
        pipe.update();
        pipe.draw();
    }
}

void Scene::draw() {
    _hero.draw();
    
    for (auto& pipe : pipes) {
        pipe.update();
        pipe.draw();
    }
}

void Scene::showMessage(String msg) {
    int charPixelWidth = 6;
    int size = 1;
    disp.setCursor(Display::width / 2 - (msg.length() / 2) * charPixelWidth * size, Display::height / 2); 
    disp.setTextSize(size); 
    disp.setTextColor(WHITE); 
    disp.print(msg); 
}