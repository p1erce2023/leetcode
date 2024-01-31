# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if not head:
            return False
        if head == head.next:
            return True
        a, b = head, head
        while a.next and b.next and b.next.next:
            if b.next == a or b.next.next == a:
                return True
            a = a.next
            b = b.next.next
        return False


s = Solution()
head = ListNode(1)
head.next = ListNode(2)
head.next.next = ListNode(3)
head.next.next.next = head
print(s.hasCycle(head))
