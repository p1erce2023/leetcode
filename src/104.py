# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        ans, layer, nxt = 0, [root] if root else [], []
        while layer:
            for node in layer:
                if node.left:
                    nxt.append(node.left)
                if node.right:
                    nxt.append(node.right)
            ans += 1
            nxt, layer = [], nxt
        return ans

s = Solution()
root = TreeNode(3)
root.left = TreeNode(9)
root.right = TreeNode(20)
root.right.left = TreeNode(15)
root.right.left.right = TreeNode(7)
print s.maxDepth(root)
