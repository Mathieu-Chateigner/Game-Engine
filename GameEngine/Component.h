#pragma once

class GameObject;

class Component {
public:
    virtual ~Component() {}  // Assure un destructeur virtuel pour une destruction propre des composants d�riv�s

    // Pure virtual functions defining the interface that all derived components must implement
    virtual void Update() = 0;  // Met � jour le composant � chaque frame

    // Pointer to the GameObject this component is attached to
    GameObject* GetOwner() const { return owner; }

    // Set the owner GameObject of this component
    void SetOwner(GameObject* gameObject) { owner = gameObject; }

protected:
    GameObject* owner;  // R�f�rence au GameObject contenant ce composant
};
