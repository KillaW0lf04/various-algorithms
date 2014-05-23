#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <string.h>
#include <stdlib.h>

typedef struct {
    std::string *key;
    void *value;
} HashKey;

class Hashtable
{
public:
    Hashtable(int capacity=100);
    ~Hashtable();

    void clear();
    uint size();
    void add(const std::string &key, void *value);
    void *get(const std::string &key);
    void remove(const std::string &key);

private:
    HashKey *buffer;
    int count;
    int capacity;

    uint hash(const std::string &key, uint seed);
};

#endif // HASHTABLE_H
