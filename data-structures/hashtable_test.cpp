#include <iostream>
#include <stdio.h>

#include <gtest/gtest.h>

#include "hashtable.h"

using namespace std;

class HashtableTest  : public ::testing::Test {
protected:
    virtual void SetUp() {
        table = new Hashtable(6);

        table->set("michael", &age1);
        table->set("christina", &age2);
        table->set("lorraine", &age3);
        table->set("stephanie", &age4);
        table->set("bruce", &age5);
    }

    int age1 = 25;
    int age2 = 22;
    int age3 = 54;
    int age4 = 24;
    int age5 = 4;
    Hashtable *table;
};

TEST_F(HashtableTest, ClearTest) {
    table->clear();
    EXPECT_EQ(0, table->size());
    EXPECT_EQ(nullptr, table->get("michael"));
    EXPECT_EQ(nullptr, table->get("bruce"));
}

TEST_F(HashtableTest, SizeTest) {
    EXPECT_EQ(5, table->size());
    table->remove("michael");
    EXPECT_EQ(4, table->size());
}

TEST_F(HashtableTest, SetTest) {
    // Check that the expected initial value is correct
    EXPECT_EQ(age1, *((int *) table->get("michael")));

    // Re-set the value and see if it is updated
    int newage = 500;
    table->set("michael", &newage);
    EXPECT_EQ(newage, *((int *) table->get("michael")));
}

TEST_F(HashtableTest, GetTest) {
    // Ensure added items are found
    EXPECT_EQ(age1, *((int *) table->get("michael")));
    EXPECT_EQ(age2, *((int *) table->get("christina")));
    EXPECT_EQ(age3, *((int *) table->get("lorraine")));
    EXPECT_EQ(age4, *((int *) table->get("stephanie")));
    EXPECT_EQ(age5, *((int *) table->get("bruce")));
}

TEST_F(HashtableTest, DoesNotExistTest) {
    EXPECT_EQ(nullptr, table->get("idontexist"));
}

TEST_F(HashtableTest, CaseSensitiveTest) {
    EXPECT_EQ(nullptr, table->get("CHRISTINA"));
}

TEST_F(HashtableTest, RemoveTest) {
    EXPECT_NE(nullptr, table->get("michael"));
    table->remove("michael");
    EXPECT_EQ(nullptr, table->get("michael"));
}
