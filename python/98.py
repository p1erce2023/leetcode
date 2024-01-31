# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if not root:
            return True
        q = [(root, None, None)]
        while q:
            p, _min, _max = q.pop()
            if p.left:
                if p.left.val >= p.val or (_min and p.left.val <= _min):
                    return False
                else:
                    q.append((p.left, _min, p.val))
            if p.right:
                if p.val >= p.right.val or (_max and p.right.val >= _max):
                    return False
                else:
                    q.append((p.right, p.val, _max))
        return True

s = Solution()
root = TreeNode(5)
root.left = TreeNode(2)
root.left.left = TreeNode(-1)
root.left.right = TreeNode(4)
root.right = TreeNode(7)
root.right.left = TreeNode(6)
print s.isValidBST(root)
