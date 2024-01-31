from utils import listToLinkedlist, print_list


# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def reorderList(self, head):
        """
        :type head: ListNode
        :rtype: void Do not return anything, modify head in-place instead.
        """
        n, x = 0, head
        while x:
            x = x.next
            n += 1
        if n < 3:
            return
        l, x = int((n + 1) / 2), head
        for _ in range(l - 1):
            x = x.next
        y = x.next
        # reverse last half list
        while y.next:
            x.next, y.next.next, y.next = y.next, x.next, y.next.next
        # intersect
        a, b = head, x.next
        while a != x:
            c, d = a.next, b.next
            a.next, b.next, x.next = b, a.next, b.next
            a, b = c, d
        # totally O(3n)
        return


s = Solution()
head = listToLinkedlist([1, 2])
s.reorderList(head)
print_list(head)
