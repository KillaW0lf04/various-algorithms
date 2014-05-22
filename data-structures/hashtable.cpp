#include "hashtable.h"

Hashtable::Hashtable(int capacity)
{
    this->buffer = static_cast<HashKey*>(calloc(capacity, sizeof(HashKey)));
    this->count = 0;
    this->capacity = capacity;
}

Hashtable::~Hashtable() {
    free(this->buffer);
}

uint Hashtable::size() {
    return this->count;
}

void Hashtable::add(char *key, void *value) {
    int index;
    int seed = 0;

    // NOTE ABOUT SEARCH:
    // Use the value not the key as a terminator
    // this is because once keys are added they are left there even
    // when removed due to potential collided keys depending on it
    // an unset value means that the block is empty.

    do {
        index = hash(key, seed++);
    } while(this->buffer[index].value != nullptr);

    // Ensure that keys passed over parameters are copied to their own memory
    this->buffer[index].key = static_cast<char*>(calloc(strlen(key), sizeof(char)));
    strcpy(this->buffer[index].key, key);

    this->buffer[index].value = value;
    this->count++;
}

void *Hashtable::get(char *key) {
    int index;
    int seed = 0;

    do {
        index = hash(key, seed++);
        if (this->buffer[index].key == nullptr)
            return nullptr;

    } while(strcmp(key, this->buffer[index].key) != 0);

    return this->buffer[index].value;
}

void Hashtable::remove(char *key) {
    int index;
    int seed = 0;

    do {
        index = hash(key, seed++);
        if (this->buffer[index].key == nullptr)
            return;

    } while (strcmp(key, buffer[index].key) != 0);

    // Free and dereference the block of memory
    // NOTE: Do not dereference the key as this is needed for
    // any potential collided keys that may have been previously
    // added
    free(this->buffer[index].key);
    this->buffer[index].value = nullptr;

    this->count--;
}

uint Hashtable::hash(char *key, uint seed) {
    int total = 0;
    int index = 0;
    char value;

    while ((value = key[index++]) != '\0')
        total += static_cast<uint>(value * (seed + 1));

    return total % capacity;
}
