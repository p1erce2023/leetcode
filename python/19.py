# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param {ListNode} head
    # @param {integer} n
    # @return {ListNode}
    def removeNthFromEnd(self, head, n):
        # after reading discuss, smart solution! 48ms
        p1 = head
        for i in xrange(n):
            p1 = p1.next
        if not p1:
            return head.next
        p2 = head
        while p1.next:
            p1 = p1.next
            p2 = p2.next
        p2.next = p2.next.next
        return head

        # 60ms, average
        if not n:
            return head

        indice = []
        p = head
        while p:
            indice.append(p)
            p = p.next

        if n == len(indice):
            return head.next
        
        indice[-n-1].next = indice[-n].next
        return head

def myprint(head):
    while head:
        print head.val,
        head = head.next
    print ""


s = Solution()

head = ListNode(5)
head.next = ListNode(6)
head.next.next = ListNode(7)
myprint(head)
myprint(s.removeNthFromEnd(head, 3))
