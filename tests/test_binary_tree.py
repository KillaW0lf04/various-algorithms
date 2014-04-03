from binary_tree import BinaryNode, build_binary_tree


def test_build_binary_tree():

    tree = build_binary_tree(range(10))

    q = [tree]

    while q:
        current = q[0]
        q = q[1:]

        left = current.left
        right = current.right

        if left:
            assert current.value > left.value
            q.append(left)

        if right:
            assert current.value <= right.value
            q.append(right)
