#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string.h>
#include <stdlib.h>

typedef struct {
    char *key;
    void *value;
} HashKey;

class Hashtable
{
public:
    Hashtable(int capacity=100);
    ~Hashtable();

    uint size();
    void add(char *key, void *value);
    void *get(char *key);
    void remove(char *key);

private:
    HashKey *buffer;
    int count;
    int capacity;

    uint hash(char *key, uint seed);
};

#endif // HASHTABLE_H
