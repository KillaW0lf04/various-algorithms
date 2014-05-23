#ifndef DATA_STRUCTURES_HASHTABLE_H_
#define DATA_STRUCTURES_HASHTABLE_H_

#include <stdlib.h>

#include <string>

typedef struct {
    std::string *key;
    void *value;
} HashKey;

class Hashtable {
 public:
    Hashtable(int capacity = 100);
    ~Hashtable();

    void clear();
    uint size();
    void set(const std::string &key, void *value);
    void *get(const std::string &key);
    void remove(const std::string &key);

 private:
    HashKey *buffer;
    int count;
    int capacity;

    uint hash(const std::string &key, uint seed);
};

#endif  // DATA_STRUCTURES_HASHTABLE_H_
