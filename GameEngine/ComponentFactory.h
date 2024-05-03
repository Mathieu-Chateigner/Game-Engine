#pragma once
#include <string>
#include <unordered_map>
#include <functional>
#include "Component.h"

class ComponentFactory {
public:
    static ComponentFactory& GetInstance();

    void RegisterComponent(const std::string& type, std::function<Component* ()> creator);
    Component* CreateComponent(const std::string& type);

private:
    ComponentFactory() {}  // Private constructor for singleton
    std::unordered_map<std::string, std::function<Component* ()>> componentCreators;
};
