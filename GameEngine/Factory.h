#pragma once
#include <map>
#include <string>
#include <functional>
#include "GameObject.h"

class Factory {
public:
    void Register(const std::string& type, std::function<GameObject* ()> creator);
    GameObject* Create(const std::string& type);

private:
    std::map<std::string, std::function<GameObject* ()>> creators;
};
