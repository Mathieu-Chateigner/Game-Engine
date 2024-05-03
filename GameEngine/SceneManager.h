#pragma once
#include <map>
#include <string>
#include <memory>
#include "Scene.h"

class SceneManager {
public:
    SceneManager();
    ~SceneManager();

    void AddScene(const std::string& name, Scene* scene);
    bool SetActiveScene(const std::string& name);
    void UpdateActiveScene();
    Scene* GetActiveScene() const;

private:
    std::map<std::string, std::unique_ptr<Scene>> scenes;
    Scene* activeScene;
};
