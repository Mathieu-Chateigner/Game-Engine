#include "ComponentFactory.h"

ComponentFactory& ComponentFactory::GetInstance() {
    static ComponentFactory instance;
    return instance;
}

void ComponentFactory::RegisterComponent(const std::string& type, std::function<Component* ()> creator) {
    componentCreators[type] = creator;
}

Component* ComponentFactory::CreateComponent(const std::string& type) {
    auto it = componentCreators.find(type);
    if (it != componentCreators.end()) {
        return it->second();
    }
    return nullptr;
}
