#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct LinkedNode {
  void *value;
  LinkedNode *next;
};

class LinkedList
{
public:
    LinkedList();

    int size();

    void append(void *value);
    void *get(int index);
    void set(int index, void *value);
    void remove(int index);

private:
    LinkedNode *head;
    LinkedNode *tail;
    int count;
};

#endif // LINKEDLIST_H
