# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param {ListNode} head
    # @param {integer} k
    # @return {ListNode}
    def reverseKGroup(self, head, k):
        # constant memory, not k
        if k <= 1:
            return head
        h = ListNode(-1)
        h.next = head
        p = h
        while p:
            s, i = p, k
            while s and i:
                s = s.next
                i -= 1
            if i or not s:
                return h.next
            t = s.next
            np = p.next
            q = p.next.next
            np.next = t
            while q != t:
                p.next, q.next, q = q, p.next, q.next
            p = np


def myprint(h):
    while h:
        print h.val,
        h = h.next
    print ""

s = Solution()
h = ListNode(1)
h.next = ListNode(2)
h.next.next = ListNode(3)
h.next.next.next = ListNode(4)
h.next.next.next.next = ListNode(5)
h.next.next.next.next.next = ListNode(6)
h.next.next.next.next.next.next = ListNode(7)
h.next.next.next.next.next.next.next = ListNode(8)
myprint(s.reverseKGroup(h, 3))
# myprint(s.reverseKGroup(h, 2))
# myprint(s.reverseKGroup(h, 0))
# myprint(s.reverseKGroup(h, 1))
# myprint(s.reverseKGroup(h, 4))
# myprint(s.reverseKGroup(h, 5))
# myprint(s.reverseKGroup(h, 6))
# myprint(s.reverseKGroup(h, 7))
# myprint(s.reverseKGroup(h, 8))
# myprint(s.reverseKGroup(h, 9))
# myprint(s.reverseKGroup(h, 10))
