#include "Scene.hpp"

void Scene::init() {
    disp.fillScreen(CYAN);
    disp.fillRect(0, hillY, Display::width + 2, Display::height - hillY + 1, GREEN);
    _hero.draw();

    pipes.emplace_back(new Pipe());
}

void Scene::update() {
    _hero.clear();
    _hero.update();
    _hero.draw();

    for (auto& pipe : pipes) {
        pipe->clear();
        pipe->update();
        pipe->draw();
    }

    remove_unvisible_pipes();
}

void Scene::remove_unvisible_pipes() {
    for (auto it = pipes.begin(); it != pipes.end();) {
        if (!(*it)->isVisible()) {
            delete *it;         // delete unvisible pipe
            it = pipes.erase(it);  // delete from vector
            Serial.println("Erased pipe");
            Serial.printf("Pipes length: %zu\n", pipes.size());  
        } else {
            ++it;
        }
    }
}

void Scene::draw() {
    _hero.draw();
    
    for (auto& pipe : pipes) {
        pipe->draw();
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