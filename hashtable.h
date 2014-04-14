#include <stdlib.h>
#include <string>

// Hashtable implementation using Open Addressing

template<class T>
struct HashObject {
    std::string* key;
    T* value;
};

template<class T>
class Hashtable
{
public:
    Hashtable(int size);

    void add(std::string *key, T* value);
    T* get(std::string *key);
    bool remove(std::string *key);
private:
    int hash(std::string *key, int round);

    int size;
    struct HashObject<T> *buffer;
};


template<class T>
Hashtable<T>::Hashtable(int size) {
    this->buffer = static_cast<HashObject<T>*>(
                    malloc(sizeof(HashObject<T>) * size));
    this->size = size;

    // Initialise the buffer space
    for (int i = 0; i < size; i++) {
        this->buffer[i].key = NULL;
        this->buffer[i].value = NULL;
    }
}

template<class T>
void Hashtable<T>::add(std::string *key, T *value) {
    // Continue searching for an open space
    int i = 0;
    int hashKey = -1;
    do {
        hashKey = hash(key, i++);
    } while (this->buffer[hashKey].key != NULL);

    this->buffer[hashKey].key = key;
    this->buffer[hashKey].value = value;
}

template<class T>
T *Hashtable<T>::get(std::string *key) {
    int i = 0;
    int hashKey = -1;
    do {
        hashKey = hash(key, i++);

        if (this->buffer[hashKey].key == NULL)
            return NULL;

    } while (key->compare(*(this->buffer[hashKey].key)) != 0);

    return this->buffer[hashKey].value;
}

template<class T>
bool Hashtable<T>::remove(std::string *key) {
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
template<class T>
int Hashtable<T>::hash(std::string *key, int round) {
    int total = 0;
    for (uint i=0; i < key->size(); i++) {
        total += static_cast<int>((*key)[i]) * (round + 1);
    }

    return total % this->size;
}
