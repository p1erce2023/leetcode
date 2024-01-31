# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def rangeSumBST(self, root, L, R):
        """
        :type root: TreeNode
        :type L: int
        :type R: int
        :rtype: int
        """
        '''思路不够好，分成了两个过程，其实可以一个过程递归/迭代的'''
        q = []
        x = root
        while x.val != L:
            if L < x.val:
                if x.left:
                    q.append((0, x))
                    x = x.left
                else:
                    break
            elif x.right:
                q.append((1, x))
                x = x.right
            else:
                break
        if x.val < L:
            return 0
        s = 0
        while x.val <= R:
            s += x.val
            if x.right:
                q.append((1, x))
                x = x.right
                while x.left:
                    q.append((0, x))
                    x = x.left
            elif q:
                d, x = q.pop()
                while d and q:
                    d, x = q.pop()
                if d and not q:
                    break
        return s


s = Solution()
root = TreeNode(7)
root.left = TreeNode(5)
root.left.left = TreeNode(3)
root.right = TreeNode(15)
root.right.left = TreeNode(10)
root.right.right = TreeNode(18)
print(s.rangeSumBST(root, 7, 15))
print(s.rangeSumBST(root, 2, 7))
print(s.rangeSumBST(root, 2, 8))
print(s.rangeSumBST(root, 2, 10))

root = TreeNode(15)
root.left = TreeNode(7)
root.left.left = TreeNode(3)
root.left.right = TreeNode(10)
root.left.left.right = TreeNode(5)
root.right = TreeNode(18)
print(s.rangeSumBST(root, 7, 15))
print(s.rangeSumBST(root, 5, 20))
print(s.rangeSumBST(root, 2, 20))
print(s.rangeSumBST(root, 1, 2))
print(s.rangeSumBST(root, 100, 103))
print(s.rangeSumBST(root, 18, 18))
print(s.rangeSumBST(root, 10, 18))
