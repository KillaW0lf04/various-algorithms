#include "hashtable.h"

#include <stdlib.h>

#include <string>

// Hashtable implementation using Open Addressing

// TODOLIST(ma13673):
//  * Use Templates to alllow generic keys and values to be inserted
//  * proper hash function

Hashtable::Hashtable() {
    this->buffer = static_cast<HashObject*>(
                    malloc(sizeof(HashObject) * BUFFERSIZE));

    // Initialise the buffer space
    for (int i = 0; i < BUFFERSIZE; i++) {
        this->buffer[i].key = NULL;
        this->buffer[i].value = NULL;
    }
}

void Hashtable::add(std::string *key, int *value) {
    // Continue searching for an open space
    int i = 0;
    int hashKey = -1;
    do {
        hashKey = hash(key, i++);
    } while (this->buffer[hashKey].key != NULL);

    this->buffer[hashKey].key = key;
    this->buffer[hashKey].value = value;
}

int *Hashtable::get(std::string *key) {
    int i = 0;
    int hashKey = -1;
    do {
        hashKey = hash(key, i++);

        if (this->buffer[hashKey].key == NULL)
            return NULL;

    } while (key->compare(*(this->buffer[hashKey].key)) != 0);

    return this->buffer[hashKey].value;
}

bool Hashtable::remove(std::string *key) {
    int i = 0;
    int hashKey = -1;
    do {
        hashKey = hash(key, i++);

        // Item does not exist
        if (this->buffer[hashKey].key == NULL)
            return false;

    } while (key->compare(*(this->buffer[hashKey].key)) != 0);

    // Set the key to NULL to represent deletion
    this->buffer[hashKey].key = NULL;
    this->buffer[hashKey].value = NULL;

    return true;
}

// private function that hashes the input
int Hashtable::hash(std::string *key, int round) {
    int total = 0;
    for (uint i=0; i < key->size(); i++) {
        total += static_cast<int>((*key)[i]) * (round + 1);
    }

    return total % BUFFERSIZE;
}
