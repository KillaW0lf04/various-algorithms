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
    EXPECT_EQ(age1, *((int *) table->get("michael")));
    EXPECT_EQ(age2, *((int *) table->get("christina")));
    EXPECT_EQ(age3, *((int *) table->get("lorraine")));
    EXPECT_EQ(age4, *((int *) table->get("stephanie")));
    EXPECT_EQ(age5, *((int *) table->get("bruce")));

    // Size check
    EXPECT_EQ(5, table->size());

    // Case Sensitive check
    EXPECT_EQ(nullptr, table->get("CHRISTINA"));

    // Non-Existant check
    EXPECT_EQ(nullptr, table->get("idontexist"));

    // Removal Test
    table->remove("michael");
    EXPECT_EQ(nullptr, table->get("michael"));
    EXPECT_EQ(4, table->size());

    // Remove non-existant field
    table->remove("idontexist");

    // Remove all
    table->remove("christina");
    table->remove("lorraine");
    table->remove("stephanie");
    table->remove("bruce");

    EXPECT_EQ(0, table->size());

    delete table;
}
