from utils import print_tree
# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def flatten(self, root):
        """
        :type root: TreeNode
        :rtype: void Do not return anything, modify root in-place instead.
        """
        if not root:
            return root
        p, stack = root, [root.right, root.left]
        while stack:
            node = stack.pop()
            if node:
                p.right = node
                p.left = None
                p = node
                stack.append(node.right)
                stack.append(node.left)

s = Solution()
root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(5)
root.left.left = TreeNode(3)
root.left.right = TreeNode(4)
root.right.right = TreeNode(6)
s.flatten(root)
print_tree(root)
