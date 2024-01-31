from utils import print_tree
# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def buildTree(self, inorder, postorder):
        """
        :type inorder: List[int]
        :type postorder: List[int]
        :rtype: TreeNode
        """
        # reverse postorder, inorder. it is symmetric to the last problem.
        if not postorder:
            return None
        node = root = TreeNode('x')
        stack = []
        left_flag = False
        i, j, n = -1, -1, len(postorder)
        while i >= -n and j >= -n:
            tmp = TreeNode(postorder[i])
            if postorder[i] == inorder[j]:
                if left_flag:
                    node.left = tmp
                else:
                    node.right = tmp
                j -= 1
                node = tmp
                while stack and stack[-1].val == inorder[j]:
                    node = stack.pop()
                    j -= 1
                left_flag = True
            else:
                stack.append(tmp)
                if left_flag:
                    node.left = tmp
                else:
                    node.right = tmp
                node = tmp
                left_flag = False
            i -= 1
        if root.right:
            return root.right
        else:
            return root.left


s = Solution()
res = s.buildTree([1, 2, 3, 4, 5, 6, 7, 8, 9], [1, 3, 5, 4, 2, 8, 9, 7, 6])  # wiki example
print_tree(res)
