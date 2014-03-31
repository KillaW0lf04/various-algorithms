
class BinaryNode(object):

    def __init__(self, value):
        self.value = value  # Store some arbitrary value
        self._left = None
        self._right = None

    def get_left(self):
        return self._left

    def get_right(self):
        return self._right

    def add_child(self, value):
        if value < self.value:
            if self._left is None:
                self._left = BinaryNode(value)
            else:
                self._left.add_child(value)
        else:
            if self._right is None:
                self._right = BinaryNode(value)
            else:
                self._right.add_child(value)

    def depth(self):
        children = [0]
        if self._left is not None:
            children.append(self._left.depth())
        if self._right is not None:
            children.append(self._right.depth())

        return 1 + max(children)

    def __str__(self):
        return '%s -> (%s, %s)' % (self.value, self._left, self._right)


def build_binary_tree(nlist):
    if nlist:
        tree = BinaryNode(nlist[0])

        for i in range(1, len(nlist)):
            tree.add_child(nlist[i])

        return tree
    else:
        return None


def inorder(tree, result):
    if tree.get_left():
        inorder(tree.get_left(), result)

    result.append(tree.value)

    if tree.get_right():
        inorder(tree.get_right(), result)


def postorder(tree, result):
    if tree.get_left():
        postorder(tree.get_left(), result)

    if tree.get_right():
        postorder(tree.get_right(), result)

    result.append(tree.value)


def preorder(tree, result):
    result.append(tree.value)

    if tree.get_left():
        preorder(tree.get_left(), result)

    if tree.get_right():
        preorder(tree.get_right(), result)


# Drawing the tree should be performed using preorder

if __name__ == '__main__':
    import random

    n = 10
    data = random.sample(range(n), n)

    print('Generating Binary Tree from: %s' % data)

    btree = build_binary_tree(data)

    print('Binary Tree: %s' % btree)
    print('Depth = %d' % btree.depth())

    data = []
    postorder(btree, data)
    print('Postorder: %s' % data)

    data = []
    inorder(btree, data)
    print('Inorder: %s' % data)

    data = []
    preorder(btree, data)
    print('Preorder: %s' % data)
