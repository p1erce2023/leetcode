from utils import print_tree, listToLinkedlist
import random
# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def sortedListToBST(self, head):
        """
        :type head: ListNode
        :rtype: TreeNode
        """
        def sortedArrayToBST(nums):
            if not nums:
                return None
            n = len(nums)
            if n == 1:  # add these 2 line will speed up, of course
                return TreeNode(nums[0])
            i = int(n / 2)
            node = TreeNode(nums[i])
            node.left = sortedArrayToBST(nums[:i])
            node.right = sortedArrayToBST(nums[i + 1:])
            return node
        # to use the ascending order property, transform into index-based array
        _array = []
        while head:
            _array.append(head.val)
            head = head.next
        return sortedArrayToBST(_array)

s = Solution()
for _ in range(5):
    st = random.randint(1, 100)
    gap = random.randint(1, 1000)
    lst = sorted(random.sample(range(st, st + gap), min(random.randint(1, 20), gap)))
    print lst
    head = listToLinkedlist(lst)
    res = s.sortedListToBST(head)
    print_tree(res)
