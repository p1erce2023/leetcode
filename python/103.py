# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def zigzagLevelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        ans, layer, s, nxt, direction = [], [root] if root else [], [], [], 0
        while layer:
            for node in layer:
                s.append(node.val)
                if node.left:
                    nxt.append(node.left)
                if node.right:
                    nxt.append(node.right)
            if direction:
                s.reverse()
            direction = 1 - direction
            ans.append(s)
            nxt, layer, s = [], nxt, []
        return ans

s = Solution()
root = TreeNode(3)
root.left = TreeNode(9)
root.right = TreeNode(20)
root.right.left = TreeNode(15)
root.right.right = TreeNode(7)
print s.zigzagLevelOrder(root)
