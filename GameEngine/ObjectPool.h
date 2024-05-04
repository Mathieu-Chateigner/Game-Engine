#pragma once
#include <cstddef>

template <typename T, size_t Size>
class ObjectPool {
public:
    ObjectPool() : freeList(nullptr) {
        for (size_t i = 0; i < Size - 1; ++i) {
            elements[i].next = &elements[i + 1];
        }
        elements[Size - 1].next = nullptr;
        freeList = &elements[0];
    }

    T* Allocate() {
        if (freeList == nullptr) {
            return nullptr;
        }

        Element* head = freeList;
        freeList = head->next;
        return &(head->data);
    }

    void Deallocate(T* obj) {
        Element* elem = reinterpret_cast<Element*>(obj);
        elem->next = freeList;
        freeList = elem;
    }

private:
    union Element {
        T data;
        Element* next;
    };

    Element elements[Size];
    Element* freeList;
};
