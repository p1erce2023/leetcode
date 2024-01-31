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
        node1 = ListNode('a')
        node1.next = head
        node = node1
        node2,node3 = head,head
        if node2:
            node3 = head.next
        else:
            return head
        while node3:
            if node2.val == node3.val:
                node3 = node3.next
            else:
                if node2.next == node3:
                    node1.next = node2
                    node1 = node2
                    node2 = node3
                    node3 = node3.next
                else:
                    node2 = node3
                    node3 = node3.next
        if node2.next == node3:
            node1.next = node2
        else:
            node1.next = None
        return node.next

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


head = ListNode(1)
head.next = ListNode(1)
myprint(head)
myprint(s.deleteDuplicates(head))
