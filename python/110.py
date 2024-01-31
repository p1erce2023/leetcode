# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        def dfs_height(node):  # O(n)
            if not node:
                return 0
            else:
                lh = dfs_height(node.left)
                if lh is False:
                    return False
                rh = dfs_height(node.right)
                if rh is False or abs(lh - rh) > 1:
                    return False
                return max(lh, rh) + 1
        return False if dfs_height(root) is False else True


s = Solution()
root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(2)
root.left.right = TreeNode(3)
root.left.left = TreeNode(3)
root.right.right = TreeNode(3)
root.right.left = TreeNode(3)
root.left.left.right = TreeNode(4)
root.left.left.left = TreeNode(4)
root.left.right.right = TreeNode(4)
root.left.right.left = TreeNode(4)
# root.right.left.right = TreeNode(4)
# root.right.left.left = TreeNode(4)
root.left.left.left.right = TreeNode(5)
root.left.left.left.left = TreeNode(5)
print s.isBalanced(root)
