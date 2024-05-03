#pragma once
#include <vector>
#include <memory>
#include "GameObject.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class Scene {
public:
    Scene();
    ~Scene();

    void AddGameObject(GameObject* gameObject);
    void Update();
    std::vector<GameObject*> FindObjectsWithTag(const std::string& tag);

    json ToJson() const;  // Convertir Scene en JSON
    static Scene FromJson(const json& j);  // Construire Scene à partir de JSON

private:
    std::vector<GameObject*> gameObjects;
};
