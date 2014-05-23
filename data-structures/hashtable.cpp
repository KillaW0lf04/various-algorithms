#include "hashtable.h"

#include <string>

Hashtable::Hashtable(int capacity) {
    this->buffer = static_cast<HashKey*>(calloc(capacity, sizeof(HashKey)));
    this->capacity = capacity;

    clear();
}

Hashtable::~Hashtable() {
    free(this->buffer);
}

void Hashtable::clear() {
    for (int i = 0; i < capacity; i++) {
        this->buffer[i].key = nullptr;
        this->buffer[i].value = nullptr;
    }

    this->count = 0;
}

uint Hashtable::size() {
    return this->count;
}

void Hashtable::set(const std::string &key, void *value) {
    int index;
    int seed = 0;

    // NOTE ABOUT SEARCH:
    // Use the value not the key as a terminator
    // this is because once keys are added they are left there even
    // when removed due to potential collided keys depending on it
    // an unset value means that the block is empty.

    do {
        index = hash(key, seed++);

        // Continue searching until a free spot is found or a spot which already
        // contains the key is found (in which case it's value will be overwritten)
    } while (this->buffer[index].value != nullptr
             && key.compare(*this->buffer[index].key) != 0);

    // Ensure that keys passed over parameters are copied to their own memory
    this->buffer[index].key = new std::string(key);
    this->buffer[index].value = value;
    this->count++;
}

void *Hashtable::get(const std::string &key) {
    int index;
    int seed = 0;

    do {
        index = hash(key, seed++);
        if (this->buffer[index].key == nullptr)
            return nullptr;
    } while (key.compare(*this->buffer[index].key) != 0);

    return this->buffer[index].value;
}

void Hashtable::remove(const std::string &key) {
    int index;
    int seed = 0;

    do {
        index = hash(key, seed++);
        if (this->buffer[index].key == nullptr)
            return;
    } while (key.compare(*this->buffer[index].key) != 0);

    // Free and dereference the block of memory
    // NOTE: Do not dereference the key as this is needed for
    // any potential collided keys that may have been previously
    // added
    free(this->buffer[index].key);
    this->buffer[index].value = nullptr;

    this->count--;
}

uint Hashtable::hash(const std::string &key, uint seed) {
    int total = 0;
    int index = 0;
    char value;

    while ((value = key[index++]) != '\0')
        total += static_cast<uint>(value * (seed + 1));

    return total % capacity;
}
