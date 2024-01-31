from utils import print_tree
import random
# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def sortedArrayToBST(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        # recursive
        if not nums:
            return None
        n = len(nums)
        if n == 1:  # add these 2 line will speed up, of course
            return TreeNode(nums[0])
        i = int(n / 2)
        node = TreeNode(nums[i])
        node.left = self.sortedArrayToBST(nums[:i])
        node.right = self.sortedArrayToBST(nums[i + 1:])
        return node

s = Solution()
for _ in range(5):
    st = random.randint(1, 100)
    gap = random.randint(1, 1000)
    lst = sorted(random.sample(range(st, st + gap), min(random.randint(1, 20), gap)))
    print lst
    res = s.sortedArrayToBST(lst)
    print_tree(res)
