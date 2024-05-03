#include "GameObject.h"

GameObject::GameObject(const std::string& tag) : tag(tag) {}

GameObject::~GameObject() {
    for (auto* comp : components) {
        delete comp;
    }
    components.clear();
}

void GameObject::AddComponent(Component* component) {
    components.push_back(component);
}

void GameObject::Update() {
    for (auto* comp : components) {
        comp->Update();
    }
}

const std::string& GameObject::GetTag() const {
    return tag;
}

void GameObject::SetTag(const std::string& tag) {
    this->tag = tag;
}

json GameObject::ToJson() const {
    json j;
    j["tag"] = tag;
    // Ajoutez plus de détails si nécessaire
    return j;
}

GameObject* GameObject::FromJson(const json& j) {
    std::string tag = j.value("tag", "");
    return new GameObject(tag);
}
