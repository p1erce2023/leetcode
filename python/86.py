# -*- coding: utf-8 -*-
# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None
from utils import print_list


class Solution(object):
    def partition(self, head, x):
        """
        :type head: ListNode
        :type x: int
        :rtype: ListNode
        """
        # script 3 之前的思路都是局部修改,此处思路是建立新的双链表再拼起来
        r1 = fake_s = ListNode(0)
        r2 = fake_ge = ListNode(0)
        while head:
            if head.val < x:
                fake_s.next = head
                fake_s = fake_s.next
            else:
                fake_ge.next = head
                fake_ge = fake_ge.next
            head = head.next
        fake_s.next = r2.next
        fake_ge.next = None
        return r1.next

        # script 2
        fake_head = ListNode(x - 1)
        fake_head.next = head
        i, j = fake_head, head
        while j and j.val < x:
            i = j
            j = j.next
        s, t = i, j
        while t:
            while t and t.val >= x:
                s = t
                t = t.next
            if not t:
                return fake_head.next
            p, q = s, t
            while q and q.val < x:
                p = q
                q = q.next
            # . . i (j .1 s) (t .2 .3 p) q -> . . i (t .2 .3 p) (j .1 s) q
            s.next = q
            i.next = t
            p.next = j
            i = p
            t = q
        return fake_head.next

        # script 1
        fake_head = ListNode(x - 1)
        fake_head.next = head
        i, j, s, t = fake_head, head, fake_head, head
        while j:
            if j.val < x:
                if j != t:
                    i.next = j.next
                    s.next = j
                    s = j
                    j.next = t
                    j = i.next
                else:
                    i = j
                    j = j.next
                    s = i
                    t = j
            else:
                i = j
                j = j.next
        return fake_head.next


s = Solution()
A = [ListNode(1), ListNode(4), ListNode(3), ListNode(2), ListNode(6), ListNode(5), ListNode(2), ListNode(7)]
for i in xrange(len(A) - 1):
    A[i].next = A[i+1]
print_list(A[0])
print_list(s.partition(A[0], 3))

A = [ListNode(2), ListNode(1)]
for i in xrange(len(A) - 1):
    A[i].next = A[i+1]
print_list(A[0])
print_list(s.partition(A[0], 2))
