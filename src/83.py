# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        node1 = head
        node2 = head
        if node1:
            node2 = head.next
        else:
            return head
        while node2:
            if node1.val == node2.val:
                node2 = node2.next
            else:
                node1.next = node2
                node1 = node2
                node2 = node2.next
        node1.next = node2
        return head

def myprint(p):
    while p:
        print p.val,
        p = p.next
    print
s = Solution()
head = ListNode(1)
head.next = ListNode(2)
head.next.next = ListNode(3)
head.next.next.next = ListNode(3)
head.next.next.next.next = ListNode(4)
head.next.next.next.next.next = ListNode(4)
head.next.next.next.next.next.next = ListNode(5)
myprint(head)
myprint(s.deleteDuplicates(head))
