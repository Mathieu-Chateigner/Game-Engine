#pragma once
#include <vector>
#include <string>
#include "Component.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class GameObject {
public:
    GameObject(const std::string& tag = "");
    ~GameObject();

    template<typename T>
    T* GetComponent() const;

    void AddComponent(Component* component);
    void Update();

    const std::string& GetTag() const;
    void SetTag(const std::string& tag);

    json ToJson() const;  // Convertir GameObject en JSON
    static GameObject* FromJson(const json& j);  // Construire GameObject à partir de JSON

private:
    std::vector<Component*> components;
    std::string tag;
};
