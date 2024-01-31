# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def maxPathSum(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        # 后序遍历 递归倒是很好写
        self.ss = []
        self.func(root)
        return max(self.ss)

    def func(self, node):
        ls, rs = 0, 0
        if node.left:
            self.func(node.left)
            ls = node.left.s
        if node.right:
            self.func(node.right)
            rs = node.right.s
        node.s = max([ls, rs, 0]) + node.val
        self.ss.append(max(node.s, ls + rs + node.val))

    def maxPathSumNonRecursive(self, root):
        # 后续遍历的非递归
        stack = [(0, root)]
        last_flag = 1
        node = root
        maxs = node.val
        while node.left or node.right:
            if node.left:
                stack.append((0, node.left))
                node = node.left
            elif node.right:
                stack.append((1, node.right))
                node = node.right
        while stack:
            flag, node = stack[-1]
            if node.right and not last_flag:
                x = node.right
                stack.append((1, x))
                while x.left or x.right:
                    if x.left:
                        stack.append((0, x.left))
                        x = x.left
                    elif x.right:
                        stack.append((1, x.right))
                        x = x.right
            else:
                stack.pop()
                last_flag = flag
                # print(node.val)
                ls = 0 if not node.left else node.left.s
                rs = 0 if not node.right else node.right.s
                node.s = max(ls, rs, 0) + node.val
                maxs = max(maxs, node.s, ls + rs + node.val)
        return maxs


s = Solution()
root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)
print(s.maxPathSum(root))
print(s.maxPathSumNonRecursive(root))

root = TreeNode(-10)
root.left = TreeNode(9)
root.right = TreeNode(20)
root.right.left = TreeNode(15)
root.right.right = TreeNode(7)
print(s.maxPathSum(root))
print(s.maxPathSumNonRecursive(root))

root = TreeNode(2)
root.left = TreeNode(-1)
root.right = TreeNode(-2)
print(s.maxPathSum(root))
print(s.maxPathSumNonRecursive(root))
