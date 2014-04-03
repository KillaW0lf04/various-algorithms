from binary_tree import BinaryNode, build_binary_tree, postorder, inorder, preorder


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


def test_order():

    tree = build_binary_tree([6, 7, 8, 1, 2, 3, 9, 0, 4, 5])

    result = []
    inorder(tree, result)
    assert result == [0, 1, 2, 3, 4, 5, 6, 7, 8, 9], 'Inorder failed'

    result = []
    postorder(tree, result)
    assert result == [0, 5, 4, 3, 2, 1, 9, 8, 7, 6], 'Postorder failed'

    result = []
    preorder(tree, result)
    assert result == [6, 1, 0, 2, 3, 4, 5, 7, 8, 9], 'Preorder failed'
