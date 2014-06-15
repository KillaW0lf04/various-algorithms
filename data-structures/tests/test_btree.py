import unittest

from btree import BTree


class BTreeTest(unittest.TestCase):

    def setUp(self):
        self.btree = BTree()
        self.btree.add(10)
        self.btree.add(20)
        self.btree.add(40)
        self.btree.add(50)

    def test_contains(self):
        assert 10 in self.btree
        assert 20 in self.btree
        assert 40 in self.btree
        assert 50 in self.btree

    def test_does_not_contain(self):
        assert 100 not in self.btree
        assert 23423 not in self.btree
