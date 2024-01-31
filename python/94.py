# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

    def __str__(self):
        return self.val

class Solution(object):
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        # iterative
        res, q, p, t = [], [], root, None
        while True:
            while p:
                q.append(p)
                p = p.left
            if not q:
                return res
            t = q.pop()
            res.append(t.val)
            p = t.right

        # recursive, trivial indeed
        if not root:
            return []
        if not root.left and not root.right:
            return [root.val]
        return self.inorderTraversal(root.left) + [root.val] + self.inorderTraversal(root.right)

# wiki example
root = TreeNode('F')
root.left = TreeNode('B')
root.right = TreeNode('G')
root.left.left = TreeNode('A')
root.left.right = TreeNode('D')
root.left.right.left = TreeNode('C')
root.left.right.right = TreeNode('E')
root.right.right = TreeNode('I')
root.right.right.left = TreeNode('H')
s = Solution()
print s.inorderTraversal(root)  # ABCDEFGHI
