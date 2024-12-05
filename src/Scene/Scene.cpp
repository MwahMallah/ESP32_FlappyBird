#include "Scene.hpp"

void Scene::init() {
    disp.fillScreen(CYAN);
    disp.fillRect(0, hillY, dispWidth, dispHeight - hillY, GREEN);
    _hero.draw();
}

void Scene::update() {
    _hero.clear();
    _hero.update();
    _hero.draw();
}

void Scene::draw() {
    _hero.draw();
}

void Scene::showMessage(String msg) {
    int charPixelWidth = 6;
    int size = 1;
    disp.setCursor(dispWidth / 2 - (msg.length() / 2) * charPixelWidth * size, dispHeight / 2); 
    disp.setTextSize(size); 
    disp.setTextColor(WHITE); 
    disp.print(msg); 
}