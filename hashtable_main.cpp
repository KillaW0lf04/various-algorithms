#include <iostream>

#include <stdlib.h>
#include <time.h>

#include "heapsort.h"
#include "quicksort.h"
#include "hashtable.h"

int main(int argc, char *argv[]) {

    Hashtable *table = new Hashtable();

    std::string *key1 = new std::string("michael");
    int value1 = 25;

    std::string *key2 = new std::string("christina");
    int value2 = 22;

    std::string *key3 = new std::string("century");
    int value3 = 100;

    std::string *key4 = new std::string("million");
    int value4 = 1000000;

    std::string *key5 = new std::string("middle");
    int value5 = 500;

    std::string *key6 = new std::string("teacher");
    int value6 = 23420;

    table->add(key1, &value1);
    table->add(key2, &value2);
    table->add(key3, &value3);
    table->add(key4, &value4);
    table->add(key5, &value5);
    table->add(key6, &value6);

    std::cout << *key4 << " is " << *table->get(key4) << std::endl;
    std::cout << *key2 << " is " << *table->get(key2) << std::endl;
    std::cout << *key1 << " is " << *table->get(key1) << std::endl;
    std::cout << *key3 << " is " << *table->get(key3) << std::endl;
    std::cout << *key5 << " is " << *table->get(key5) << std::endl;
    std::cout << *key6 << " is " << *table->get(key6) << std::endl;
}
