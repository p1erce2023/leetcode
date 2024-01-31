from utils import print_tree
# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def generateTrees(self, n):
        """
        :type n: int
        :rtype: List[TreeNode]
        Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.
        """
        def g(st, ed):  # really shocking to write recursive code accepted without debug
            if st == ed:
                return [None]
            res = []
            for i in xrange(st, ed):
                for l in g(st, i):
                    for r in g(i + 1, ed):
                        root = TreeNode(i)
                        root.left = l
                        root.right = r
                        res.append(root)
            return res
        if n < 1:
            return []
        return g(1, n + 1)

s = Solution()
for tn in s.generateTrees(3):
    print_tree(tn)
