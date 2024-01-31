from utils import print_tree
# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def hasPathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: bool
        """
        # dfs
        if not root:
            return False
        stack, node = [(root, root.val)], None
        while stack:
            node, s = stack.pop()
            if not node.left and not node.right and s == sum:
                return True
            if node.left:
                stack.append((node.left, s + node.left.val))
            if node.right:
                stack.append((node.right, s + node.right.val))
        return False

s = Solution()
root = TreeNode(5)
root.left = TreeNode(4)
root.right = TreeNode(8)
root.left.left = TreeNode(11)
root.left.left.left = TreeNode(7)
root.left.left.right = TreeNode(2)
root.right.left = TreeNode(13)
root.right.right = TreeNode(4)
root.right.right.right = TreeNode(1)
print_tree(root)
print s.hasPathSum(root, 22)
