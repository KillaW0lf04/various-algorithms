#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>

#define BUFFERSIZE 10

typedef struct {
    std::string* key;
    int value;
} HashObject;

class Hashtable
{
public:
    Hashtable();

    void add(std::string *key, int value);
    int get(std::string *key);
    bool remove(std::string *key);
private:
    int hash(std::string *key, int round);

    HashObject *buffer;
};

#endif // HASHTABLE_H
