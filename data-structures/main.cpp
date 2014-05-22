#include <iostream>
#include <stdio.h>

#include <gtest/gtest.h>

#include "hashtable.h"

using namespace std;

TEST(hashtable_test, add_get_test) {
    Hashtable *table = new Hashtable(6);

    int age1 = 25;
    int age2 = 22;
    int age3 = 54;
    int age4 = 24;
    int age5 = 4;

    table->add("michael", &age1);
    table->add("christina", &age2);
    table->add("lorraine", &age3);
    table->add("stephanie", &age4);
    table->add("bruce", &age5);

    // Ensure added items are found
    EXPECT_EQ(*((int *) table->get("michael")), age1);
    EXPECT_EQ(*((int *) table->get("christina")), age2);
    EXPECT_EQ(*((int *) table->get("lorraine")), age3);
    EXPECT_EQ(*((int *) table->get("stephanie")), age4);
    EXPECT_EQ(*((int *) table->get("bruce")), age5);

    // Size check
    EXPECT_EQ(table->size(), 5);

    // Case Sensitive check
    EXPECT_EQ(table->get("CHRISTINA"), nullptr);

    // Non-Existant check
    EXPECT_EQ(table->get("idontexist"), nullptr);

    // Removal Test
    table->remove("michael");
    EXPECT_EQ(table->get("michael"), nullptr);
    EXPECT_EQ(table->size(), 4);

    // Remove non-existant field
    table->remove("idontexist");

    // Remove all
    table->remove("christina");
    table->remove("lorraine");
    table->remove("stephanie");
    table->remove("bruce");

    EXPECT_EQ(table->size(), 0);

    delete table;
}
