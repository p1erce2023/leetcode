from utils import print_tree
# Definition for binary tree with next pointer.
class TreeLinkNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
        self.next = None

class Solution(object):
    def connect(self, root):
        """
        :type root: TreeLinkNode
        :rtype: nothing
        """
        # perfect binary tree case
        if not root:
            return
        while root.left:
            node = root
            node.left.next = node.right
            while node.next:
                node.right.next = node.next.left
                node.next.left.next = node.next.right
                node = node.next
            root = root.left
        return

        # by layer, this is not constant extra space, but suit imperfect tree
        # if not root:
        #     return
        # layer, nextlayer = [root], []
        # while layer:
        #     n = len(layer)
        #     for i in xrange(n - 1):
        #         layer[i].next = layer[i + 1]
        #         if layer[i].left:
        #             nextlayer.append(layer[i].left)
        #         if layer[i].right:
        #             nextlayer.append(layer[i].right)
        #     if layer[-1].left:
        #         nextlayer.append(layer[-1].left)
        #     if layer[-1].right:
        #         nextlayer.append(layer[-1].right)
        #     layer, nextlayer = nextlayer, []

s = Solution()
root = TreeLinkNode(1)
root.left = TreeLinkNode(2)
root.right = TreeLinkNode(3)
root.left.left = TreeLinkNode(4)
root.left.right = TreeLinkNode(7)
root.right.left = TreeLinkNode(5)
root.right.right = TreeLinkNode(6)
print_tree(root)
s.connect(root)
print(root.left.right.next.val)
