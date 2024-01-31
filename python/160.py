from utils import print_list, listToLinkedlist, linkTwoLinkedlist


class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        if not headA or not headB:
            return None
        tempa, tempb = headA, headB
        while tempa and tempb:
            if tempa.val == tempb.val:
                return tempa
            if not tempa.next and not tempb.next:
                return None
            if tempa.next:
                tempa = tempa.next
            else:
                tempa = headB
            if tempb.next:
                tempb = tempb.next
            else:
                tempb = headA
        return None


s = Solution()

headA = listToLinkedlist(['1', '2'] + list(range(4000001, 8000000)))
headB = listToLinkedlist(['x', 'y', 'z', 'o', 'p', 'q', 'l', 'm'] + list(range(3, 4000000)))
intersection = listToLinkedlist(['a', 'b', 'c'])
linkTwoLinkedlist(headA, intersection)
linkTwoLinkedlist(headB, intersection)
# print_list(headA)
# print_list(headB)
question = s.getIntersectionNode(headA, headB)
print(question)
if question:
    print(question.val)
