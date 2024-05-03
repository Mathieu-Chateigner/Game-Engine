#include "SceneManager.h"

SceneManager::SceneManager() : activeScene(nullptr) {}

SceneManager::~SceneManager() {
    scenes.clear();  // Automatically deletes all managed scenes
}

void SceneManager::AddScene(const std::string& name, Scene* scene) {
    scenes[name] = std::unique_ptr<Scene>(scene);
}

bool SceneManager::SetActiveScene(const std::string& name) {
    auto it = scenes.find(name);
    if (it != scenes.end()) {
        activeScene = it->second.get();
        return true;
    }
    return false;
}

void SceneManager::UpdateActiveScene() {
    if (activeScene) {
        activeScene->Update();
    }
}

Scene* SceneManager::GetActiveScene() const {
    return activeScene;
}
