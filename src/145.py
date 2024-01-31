from utils import print_tree


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def postorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        Note: Recursive solution is trivial, could you do it iteratively?
        """
        if not root:
            return []
        '''
        # trivial recursive
        if not root.left and not root.right:
            return [root.val]
        return self.postorderTraversal(root.left) + self.postorderTraversal(root.right) + [root.val]
        '''
        # iterative
        if not root:
            return []
        x, res = [root], []
        while x:
            t = x.pop()
            res.append(t.val)
            if t.left:
                x.append(t.left)
            if t.right:
                x.append(t.right)
        return res[::-1]


root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)
root.left.left = TreeNode(4)
root.left.right = TreeNode(5)
print_tree(root)
s = Solution()
print(s.postorderTraversal(root))
