#include "linkedlist.h"

#include <stdlib.h>

LinkedList::LinkedList()
{
    this->count = 0;
    this->head = nullptr;
    this->tail = nullptr;
}

int LinkedList::size() {
    return this->count;
}

void LinkedList::append(void *value) {
    LinkedNode *node = static_cast<LinkedNode*>(malloc(sizeof(LinkedNode)));
    node->value = value;
    node->next = nullptr;

    if (this->head == nullptr) {
        this->head = node;
        this->tail = this->head;
    } else {
        this->tail->next = node;
        this->tail = node;
    }

    this->count++;
}

void *LinkedList::get(int index) {
    if (this->head == nullptr)
        return nullptr;

    LinkedNode *current = this->head;

    while (index > 0) {
        if (current == nullptr)
            return nullptr;

        current = current->next;
        index--;
    }

    return current->value;
}

void LinkedList::set(int index, void *value) {
    LinkedNode *current = this->head;

    while (index > 0) {
        current = current->next;
        index--;
    }

    current->value = value;
}

void LinkedList::remove(int index) {
    LinkedNode *prev = nullptr;
    LinkedNode *current = this->head;

    while (index > 0) {
        prev = current;
        current = current->next;
        index--;
    }

    if (prev != nullptr) {
        prev->next = current->next;
    } else {
        this->head = current->next;
    }

    if (current->next == nullptr)
        this->tail = prev;

    free(current);
    this->count--;
}
