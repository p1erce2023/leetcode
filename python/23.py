# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param {ListNode[]} lists
    # @return {ListNode}
    def mergeKLists(self, lists):
        from heapq import heappush, heappop, heapify
        h = [(l.val, i) for i, l in enumerate(lists) if l]
        heapify(h)
        s = ListNode(-1)
        p = s
        q = lists[:]
        while any(l for l in q):
            r = heappop(h)
            p.next = q[r[1]]
            p = p.next
            q[r[1]] = q[r[1]].next
            if q[r[1]]:
                heappush(h, (q[r[1]].val, r[1]))
        return s.next

l1 = ListNode(1)
l1.next = ListNode(2)
l1.next.next = ListNode(3)

l2 = ListNode(-10)
l2.next = ListNode(9)
l2.next.next = ListNode(19)

l3 = ListNode(-5)
l3.next = ListNode(2)
l3.next.next = ListNode(5)
l3.next.next.next = ListNode(12)

def myprint(h):
    while h:
        print h.val,
        h = h.next
    print ""

s = Solution()
myprint(s.mergeKLists([l1, l2, l3]))
myprint(s.mergeKLists([[]]))