from utils import print_list
# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def reverseBetween(self, head, m, n):
        """
        :type head: ListNode
        :type m: int
        :type n: int
        :rtype: ListNode
        Reverse a linked list from position m to n. Do it in-place and in one-pass.
        """
        h = ListNode(0)
        h.next, l, r, c = head, h, head, 1
        while c < m:
            l, r = r, r.next
            c += 1
        while c < n:
            # print c, l.val, r.val
            # t, l.next = l.next, r.next
            # l.next.next, r.next = t, r.next.next
            l.next, r.next.next, r.next = r.next, l.next, r.next.next  # order matters
            c += 1
            # print_list(h)
        return h.next


s = Solution()
head = ListNode(-1)
head.next = ListNode(-2)
head.next.next = ListNode(-3)
head.next.next.next = ListNode(-4)
head.next.next.next.next = ListNode(-5)
head.next.next.next.next.next = ListNode(-6)
head.next.next.next.next.next.next = ListNode(-7)
# print_list(head)
head = s.reverseBetween(head, 2, 4)
print_list(head)
