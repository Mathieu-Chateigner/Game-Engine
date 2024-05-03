#include "Scene.h"

Scene::Scene() {}

Scene::~Scene() {
    for (auto* obj : gameObjects) {
        delete obj;
    }
    gameObjects.clear();
}

void Scene::AddGameObject(GameObject* gameObject) {
    gameObjects.push_back(gameObject);
}

void Scene::Update() {
    for (auto* obj : gameObjects) {
        obj->Update();
    }
}

json Scene::ToJson() const {
    json j = json::array();
    for (const auto& obj : gameObjects) {
        j.push_back(obj->ToJson());
    }
    return j;
}

Scene Scene::FromJson(const json& j) {
    Scene scene;
    for (const auto& item : j) {
        scene.AddGameObject(GameObject::FromJson(item));
    }
    return scene;
}
