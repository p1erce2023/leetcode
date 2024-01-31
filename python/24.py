# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param {ListNode} head
    # @return {ListNode}
    def swapPairs(self, head):
        h0 = ListNode(-1)
        h0.next = head
        p1, p2 = h0, head
        while p2 and p2.next:
            p1.next = p2.next
            p2.next.next, p2.next = p2, p2.next.next
            p1 = p2
            p2 = p2.next
        return h0.next

def myprint(head):
    while head:
        print head.val,
        head = head.next
    print ""


s = Solution()

a1 = ListNode(5)
a1.next = ListNode(6)
a1.next.next = ListNode(4)
a1.next.next.next = ListNode(3)
a1.next.next.next.next = ListNode(2)
a1.next.next.next.next.next = ListNode(1)

myprint(s.swapPairs(a1))
