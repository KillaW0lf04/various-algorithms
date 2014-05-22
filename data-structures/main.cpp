#include <iostream>
#include <stdio.h>

#include "hashtable.h"

using namespace std;

int main()
{
    Hashtable *table = new Hashtable();

    int age1 = 25;
    int age2 = 22;

    table->add("michael", &age1);
    table->add("christina", &age2);

    printf("michael: %d\n", *((int *) table->get("michael")));
    printf("christina: %d\n", *((int *) table->get("christina")));

    cout << "Hashtable size: " << table->size() << endl;

    table->remove("michael");

    cout << "Hashtable size: " << table->size() << endl;
}

