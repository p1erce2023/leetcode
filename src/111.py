# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def minDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        # speed up, no use of list assignment
        if not root:
            return 0
        stack = [(root, 1)]
        while stack:
            node, depth = stack.pop()
            if not node.left and not node.right:
                return depth
            if node.left:
                stack.insert(0, (node.left, depth + 1))
            if node.right:
                stack.insert(0, (node.right, depth + 1))

        # level order
        # if not root:
        #     return 0
        # depth, layer, nextlayer = 1, [root], []
        # while layer:
        #     for node in layer:
        #         if not node.left and not node.right:
        #             return depth
        #         if node.left:
        #             nextlayer.append(node.left)
        #         if node.right:
        #             nextlayer.append(node.right)
        #     depth += 1
        #     layer, nextlayer = nextlayer, []

s = Solution()
root = TreeNode(5)
root.left = TreeNode(3)
root.right = TreeNode(1)
root.right.left = TreeNode(4)
print s.minDepth(root)
