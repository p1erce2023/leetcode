# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def myprint(l):
    while l:
        print l.val
        l = l.next
    print ""

class Solution:
    # @param {ListNode} l1
    # @param {ListNode} l2
    # @return {ListNode}
    def mergeTwoLists(self, l1, l2):
        # if not l1:
        #     return l2
        # if not l2:
        #     return l1

        # if l1.val < l2.val:
        #     h = l1
        #     l1 = l1.next
        # else:
        #     h = l2
        #     l2 = l2.next
        h = ListNode(0)
        t = h
        while l1 and l2:
            if l1.val < l2.val:
                t.next = l1
                t = l1
                l1 = l1.next
            else:
                t.next = l2
                t = l2
                l2 = l2.next

        if l1:
            t.next = l1
        elif l2:
            t.next = l2

        return h.next

s = Solution()
l1 = ListNode(5)
l2 = ListNode(1)
l2.next = ListNode(2)
l2.next.next = ListNode(4)
myprint(s.mergeTwoLists(l1, l2))
