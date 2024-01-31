# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def sumNumbers(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        # dfs
        if not root:
            return 0
        q, p, s, f = [(root, str(root.val))], None, 0, True
        while q:
            p, t = q.pop()
            f = True
            if p.right:
                q.append((p.right, t + str(p.right.val)))
                f = False
            if p.left:
                q.append((p.left, t + str(p.left.val)))
                f = False
            if f:
                s += int(t)
        return s

s = Solution()
root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(4)
print s.sumNumbers(root)
