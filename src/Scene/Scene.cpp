#include "Scene.hpp"

void Scene::init() {
    disp.fillScreen(CYAN);
    disp.fillRect(0, hillY, Display::width + 2, Display::height - hillY + 1, GREEN);
    _hero.draw();
}

void Scene::initCounter() {
    _counter.draw();
}

void Scene::showMessage(String msg) {
    int charPixelWidth = 6;
    int size = 1;
    disp.setCursor(Display::width / 2 - (msg.length() / 2) * charPixelWidth * size, Display::height / 2); 
    disp.setTextSize(size); 
    disp.setTextColor(WHITE); 
    disp.print(msg); 
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

    _counter.draw();
    removeUnvisiblePipes();

    frameCounter++;
    if (frameCounter >= spawnRate) {
        frameCounter = 0;
        spawnPipe();
    }
}

void Scene::draw() {
    _hero.draw();
    
    for (auto& pipe : pipes) {
        pipe->draw();
    }
}

void Scene::removeUnvisiblePipes() {
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

void Scene::spawnPipe() {
    pipes.push_back(new Pipe());
}

bool Scene::heroScored() {
    for (auto& pipe : pipes) {
        if (pipe->scored(_hero.getCenterX(), _hero.getCenterY())) {
            return true;
        }
    }

    return false;
}

bool Scene::heroCollided() {
    for (auto& pipe : pipes) {
        if (pipe->collided(_hero.getCenterX(), _hero.getCenterY())) {
            return true;
        }
    }

    return false;
}

void Scene::increaseCounter() {
    _counter.increaseCounter();
}

int Scene::getScore()
{
    return _counter.getScore();
}
