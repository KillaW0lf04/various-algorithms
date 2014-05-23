#include <gtest/gtest.h>

#include "linkedlist.h"

class LinkedListTest : public ::testing::Test {
protected:
    virtual void SetUp() {
        list = new LinkedList();

        list->append(name1);
        list->append(name2);
    }

    char *name1 = "michael";
    char *name2 = "john";
    char *name3 = "matthew";
    LinkedList *list;
};

TEST_F(LinkedListTest, GetTest) {
    EXPECT_STREQ("michael", (char *) list->get(0));
    EXPECT_STREQ("john", (char *) list->get(1));
}

TEST_F(LinkedListTest, AppendTest) {
    list->append(name3);

    EXPECT_STREQ("matthew", (char *) list->get(2));
}

TEST_F(LinkedListTest, SizeTest) {
    EXPECT_EQ(2, list->size());
    list->append(name3);
    EXPECT_EQ(3, list->size());
    list->remove(0);
    EXPECT_EQ(2, list->size());
}

TEST_F(LinkedListTest, RemoveTest) {
    list->append(name3);

    list->remove(0);
    EXPECT_STREQ("john", (char *) list->get(0));

    list->remove(1);
    EXPECT_STREQ("john", (char *) list->get(0));
}

TEST_F(LinkedListTest, SetTest) {
    list->set(0, name3);
    EXPECT_STREQ("matthew", (char *) list->get(0));
    list->set(1, name3);
    EXPECT_STREQ("matthew", (char *) list->get(1));
}
