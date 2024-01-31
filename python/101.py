# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        # iteratively, by node compare
        if not root:
            return True
        q = [(root.left, root.right)]
        while q:
            l, r = q.pop()
            if not l and not r:
                continue
            elif not l or not r or l.val != r.val:
                return False
            q.append((l.left, r.right))
            q.append((l.right, r.left))
        return True

        # recursively, by layer compare
        def isSym(lst):
            nxt_l, nxt_r = [], []
            for i in xrange(len(lst) / 2):
                if not lst[i] and not lst[-i - 1]:
                    continue
                elif not lst[i] or not lst[-i - 1] or lst[i].val != lst[-1 - i].val:
                    return False
                nxt_l.append(lst[i].left)
                nxt_l.append(lst[i].right)
                nxt_r.insert(0, lst[-1 - i].right)
                nxt_r.insert(0, lst[-1 - i].left)
            nxt = nxt_l + nxt_r
            if any(nxt):
                return isSym(nxt)
            return True
        if not root:
            return True
        return isSym([root.left, root.right])


s = Solution()
root = TreeNode(5)
root.left = TreeNode(4)
root.right = TreeNode(4)
root.left.left = TreeNode(2)
# root.left.right = TreeNode(1)
# root.right.left = TreeNode(1)
root.right.right = TreeNode(2)
print s.isSymmetric(root)
