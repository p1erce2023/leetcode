from random import randint
from utils import print_list, listToLinkedlist, ListNode


class Solution(object):
    def insertionSortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        virtual = ListNode(0)
        virtual.next = head
        if not head or not head.next:
            return head
        x, _max = head, head.val
        while x.next:
            if x.next.val >= _max:
                _max = x.next.val
                x = x.next
            else:
                y = virtual
                while y.next.val <= x.next.val:
                    y = y.next
                a, b = y.next, x.next
                y.next, b.next, x.next = b, a, b.next
        return virtual.next


s, n = Solution(), 10
x = [randint(0, n**2) for _ in range(n)]
print(' -> '.join(str(i) for i in x))
head = s.insertionSortList(listToLinkedlist(x))
print_list(head)
