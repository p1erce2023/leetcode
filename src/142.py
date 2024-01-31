# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def detectCycle(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head:
            return None
        if head == head.next:
            return head
        a, b = head, head
        while a.next and b.next and b.next.next:
            a, b = a.next, b.next.next
            if a == b:
                a = head
                while a != b:
                    a, b = a.next, b.next
                return a
        return None
