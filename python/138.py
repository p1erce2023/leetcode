# Definition for singly-linked list with a random pointer.
class RandomListNode(object):
    def __init__(self, x):
        self.label = x
        self.next = None
        self.random = None


def printList(head):
    it = head
    while it:
        print('{}({})'.format(it.label, it.random.label if it.random else 'None'), '-> ', end='')
        it = it.next
    print()


class Solution(object):
    def copyRandomList(self, head):
        """
        :type head: RandomListNode
        :rtype: RandomListNode
        """
        # trivial solution discuss见到一个O(1)的extra space，非常精巧！
        if not head:
            return None
        ret = RandomListNode(head.label)
        a, b, it, i = {head: 0}, [ret], head, 1
        jt = ret
        it = it.next
        while it:
            a[it] = i
            jt.next = RandomListNode(it.label)
            it, jt = it.next, jt.next
            b.append(jt)
            i += 1
        it, jt = head, ret
        while it:
            if it.random:
                jt.random = b[a[it.random]]
            it = it.next
            jt = jt.next
        return ret


s = Solution()
a = RandomListNode(1)
a.next = RandomListNode(2)
a.next.next = RandomListNode(3)
a.next.next.next = RandomListNode(4)
a.random = a.next.next.next
a.next.next.random = a
printList(a)
b = s.copyRandomList(a)
a = None
printList(b)
