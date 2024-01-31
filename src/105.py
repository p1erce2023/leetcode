# Definition for a binary tree node.
from utils import print_tree
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        if not preorder:
            return None
        node = root = TreeNode('x')
        stack = []
        right_flag = False
        i, j, n = 0, 0, len(preorder)
        while i < n and j < n:
            # print preorder[i], inorder[j], 'stack:', ' '.join(str(item.val) for item in stack), right_flag, node.val
            tmp = TreeNode(preorder[i])
            if preorder[i] == inorder[j]:
                if right_flag:
                    node.right = tmp
                else:
                    node.left = tmp
                j += 1
                node = tmp
                while stack and stack[-1].val == inorder[j]:
                    node = stack.pop()
                    j += 1
                right_flag = True
            else:
                stack.append(tmp)
                if right_flag:
                    node.right = tmp
                else:
                    node.left = tmp
                node = tmp
                right_flag = False
            i += 1
        if root.left:
            return root.left
        else:
            return root.right

        # recursive memory limit exceeded
        if not preorder:
            return None
        root = TreeNode(preorder[0])
        if len(preorder) == 1:
            return root
        x = inorder.index(preorder[0])
        root.left = self.buildTree(preorder[1:x + 1], inorder[:x])
        root.right = self.buildTree(preorder[x + 1:], inorder[x + 1:])
        return root

s = Solution()
res = s.buildTree([6, 2, 1, 4, 3, 5, 7, 9, 8], [1, 2, 3, 4, 5, 6, 7, 8, 9])  # wiki example
# res = s.buildTree([1, 5, 2, 3, 4], [5, 1, 3, 2, 4])
# res = s.buildTree([1, 2, 3, 4], [1, 3, 2, 4])
print_tree(res)
