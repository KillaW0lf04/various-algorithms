t = 2


def split_child(x, index, y):
    z = BNode()

    x.children.insert(index + 1, z)
    x.keys.insert(index, y.keys[t - 1])

    z.keys = y.keys[t:]
    y.keys = y.keys[:t - 1]

    if not y.is_leaf():
        z.children = y.children[t:]
        y.children = y.children[:t]


class BNode(object):

    def __init__(self):
        self.keys = []
        self.children = []

    def __repr__(self):
        return '<BNode: %d keys, %d children>' % (len(self.keys), len(self.children))

    def is_leaf(self):
        return len(self.children) == 0

    def add(self, value):
        if self.is_leaf():
            self.keys.append(value)
            self.keys.sort()
        else:
            # Find where to insert the new value
            index = 0
            for key in self.keys:
                if value < key:
                    break

                index += 1

            next_node = self.children[index]
            if len(next_node.keys) == 2 * t - 1:
                split_child(self, index, next_node)

                if value > self.keys[index]:
                    next_node = self.children[index + 1]

            next_node.add(value)


class BTree(object):

    def __init__(self):
        self.root = BNode()

    def __repr__(self):
        return '<BTree>'

    def add(self, value):
        if len(self.root.keys) == 2 * t - 1:
            new_root = BNode()
            new_root.children.append(self.root)

            split_child(new_root, 1, self.root)
            new_root.add(value)

            self.root = new_root
        else:
            self.root.add(value)
            
