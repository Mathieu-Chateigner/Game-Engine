#include "Factory.h"

void Factory::Register(const std::string& type, std::function<GameObject* ()> creator) {
    creators[type] = creator;
}

GameObject* Factory::Create(const std::string& type) {
    if (creators.find(type) != creators.end()) {
        return creators[type]();
    }
    return nullptr;
}
