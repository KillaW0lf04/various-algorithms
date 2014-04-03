
class BinaryNode(object):

    def __init__(self, value):
        self.value = value  # Store some arbitrary value
        self.left = None
        self.right = None

    def add_child(self, value):
        if value < self.value:
            if self.left is None:
                self.left = BinaryNode(value)
            else:
                self.left.add_child(value)
        else:
            if self.right is None:
                self.right = BinaryNode(value)
            else:
                self.right.add_child(value)

    def depth(self):
        children = [0]
        if self.left is not None:
            children.append(self.left.depth())
        if self.right is not None:
            children.append(self.right.depth())

        return 1 + max(children)

    def __str__(self):
        return '%s -> (%s, %s)' % (self.value, self.left, self.right)


def build_binary_tree(nlist):
    if nlist:
        tree = BinaryNode(nlist[0])

        for i in range(1, len(nlist)):
            tree.add_child(nlist[i])

        return tree
    else:
        return None


def inorder(tree, result):
    if tree.left:
        inorder(tree.left, result)

    result.append(tree.value)

    if tree.right:
        inorder(tree.right, result)


def postorder(tree, result):
    if tree.left:
        postorder(tree.left, result)

    if tree.right:
        postorder(tree.right, result)

    result.append(tree.value)


def preorder(tree, result):
    result.append(tree.value)

    if tree.left:
        preorder(tree.left, result)

    if tree.right:
        preorder(tree.right, result)


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
