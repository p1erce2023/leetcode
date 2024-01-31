# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def levelOrderBottom(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        ans, layer, s, nxt = [], [root] if root else [], [], []
        while layer:
            for node in layer:
                s.append(node.val)
                if node.left:
                    nxt.append(node.left)
                if node.right:
                    nxt.append(node.right)
            ans.append(s)
            nxt, layer, s = [], nxt, []
        return list(reversed(ans))  # faster than `ans.insert(0, s); return ans`

s = Solution()
root = TreeNode(3)
root.left = TreeNode(9)
root.right = TreeNode(20)
root.right.left = TreeNode(15)
root.right.right = TreeNode(7)
print s.levelOrderBottom(root)
