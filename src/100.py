# -*- coding: utf-8 -*-
# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def isSameTree(self, p, q):
        """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """
        # slower than recursive? 中序遍历
        if p and q:
            stack = [(p, q)]
            while stack:
                tp, tq = stack.pop()
                if tp and tq:
                    if tp.val == tq.val:
                        stack.append((tp.right, tq.right))
                        stack.append((tp.left, tq.left))
                    else:
                        return False
                elif not tp and not tq:
                    continue
                else:
                    return False
            return True
        elif not p and not q:
            return True
        else:
            return False

        # recursive
        if p and q:
            if p.val == q.val:
                return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)
            else:
                return False
        elif not p and not q:
            return True
        else:
            return False

a = TreeNode(1)
a.left = TreeNode(None)
a.right = TreeNode(2)
b = TreeNode(1)
b.left = TreeNode(None)
b.right = TreeNode(2)
s = Solution()
print s.isSameTree(a, b)
