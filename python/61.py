# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

def myprint(node):
    while node:
        print node.val,
        node = node.next
    print ""

class Solution(object):
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        l, t = [], head
        while t:
            l.append(t)
            t = t.next
        n = len(l)
        if not n:
            return None
        if n < k:
            k = k % n
        l[n-1].next = l[0]
        l[n-k-1].next = None
        return l[-k]

# 一开始没理解什么叫rotate to the right by k places, 其实就是循环右移k位
s = Solution()
a = ListNode(1)
a.next = ListNode(2)
a.next.next = ListNode(3)
a.next.next.next = ListNode(4)
a.next.next.next.next = ListNode(5)
myprint(a)
b = s.rotateRight(a, 6)
myprint(b)
