#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>

typedef struct {
    std::string key;
    int value;
} KeyValuePair;

class Hashtable
{
public:
    Hashtable();

    void add(std::string key, int value);
    int get(std::string key);
    void remove(std::string key);
private:
    int hash(std::string key);

    KeyValuePair *buffer;
};

#endif // HASHTABLE_H
