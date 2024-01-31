# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


def myprint(l):
    t = l
    while t:
        print t.val,
        t = t.next
    print ""


class Solution:
    # @param {ListNode} l1
    # @param {ListNode} l2
    # @return {ListNode}
    def addTwoNumbers(self, l1, l2):
        re, zero = ListNode(0), ListNode(0)
        p1, p2, t = l1, l2, re
        carry, n = 0, 0
        end1, end2 = False, False
        while p1 and p2:
            n = carry + p1.val + p2.val
            if n >= 10:
                carry = 1
                t.val = n - 10
            else:
                carry = 0
                t.val = n 
            if not end1:
                if p1.next:
                    p1 = p1.next
                else:
                    end1 = True
                    p1 = zero
            if not end2:
                if p2.next:
                    p2 = p2.next
                else:
                    end2 = True
                    p2 = zero
            if not end1 or not end2 or carry:
                t.next = ListNode(0)
                t = t.next
            else:
                return re

        # script 2
        # re, zero = ListNode(0), ListNode(0)
        # p1, p2, t = l1, l2, re
        # carry, n = 0, 0
        # end1, end2 = False, False
        # while 1:
        #     n = carry + p1.val + p2.val
        #     if n >= 10:
        #         carry = 1
        #         t.val = n - 10
        #     else:
        #         carry = 0
        #         t.val = n 
        #     if not end1:
        #         if p1.next:
        #             p1 = p1.next
        #         else:
        #             end1 = True
        #             p1 = zero
        #     if not end2:
        #         if p2.next:
        #             p2 = p2.next
        #         else:
        #             end2 = True
        #             p2 = zero
        #     if not end1 or not end2 or carry:
        #         t.next = ListNode(0)
        #         t = t.next
        #     else:
        #         return re

        # script 1
        # re = ListNode(0)
        # p1, p2, t = l1, l2, re
        # carry, n = 0, 0
        # while 1:
        #     if p1 and p2:
        #         n = carry + p1.val + p2.val
        #         p1 = p1.next
        #         p2 = p2.next
        #     elif p1:
        #         n = carry + p1.val
        #         p1 = p1.next
        #     elif p2:
        #         n = carry + p2.val
        #         p2 = p2.next
        #     else:
        #         n = carry
        #     if n >= 10:
        #         carry = 1
        #         t.val = n - 10
        #     else:
        #         carry = 0
        #         t.val = n 
        #     if p1 or p2 or carry:
        #         t.next = ListNode(0)
        #         t = t.next
        #     else:
        #         return re
            

s = Solution()

l1 = ListNode(2)
l1.next = ListNode(4)
l1.next.next = ListNode(3)
l1.next.next.next = ListNode(5)
l1.next.next.next.next = ListNode(5)
myprint(l1)

l2 = ListNode(5)
l2.next = ListNode(6)
l2.next.next = ListNode(6)
myprint(l2)

re = s.addTwoNumbers(l1, l2)

myprint(re)
            


