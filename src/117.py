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
        if not root:
            return
        node, layer, node_iter = root, root.left or root.right, None
        while layer:
            while node:
                if not node.left and not node.right:
                    node = node.next
                    continue
                node_out_next, node_next = None, node.next
                while node_next:
                    if node_next.left:
                        node_out_next = node_next.left
                        break
                    if node_next.right:
                        node_out_next = node_next.right
                        break
                    node_next = node_next.next
                if node.left and node.right:
                    node.left.next = node.right
                    node.right.next = node_out_next
                elif node.left:
                    node.left.next = node_out_next
                elif node.right:
                    node.right.next = node_out_next
                node = node.next
            node, layer, node_iter = layer, None, layer
            while node_iter:
                if node_iter.left:
                    layer = node_iter.left
                    break
                if node_iter.right:
                    layer = node_iter.right
                    break
                node_iter = node_iter.next
        return


s = Solution()
head = TreeLinkNode(0)
root = TreeLinkNode(1)
head.right = root
root.left = TreeLinkNode(2)
root.right = TreeLinkNode(3)
root.left.left = TreeLinkNode(4)
root.left.right = TreeLinkNode(5)
root.right.right = TreeLinkNode(7)
root.left.left.right = TreeLinkNode(8)
root.right.right.left = TreeLinkNode(9)
root.left.left.right.right = TreeLinkNode(6)
print_tree(head)
s.connect(head)
inspect = head
layer, nxt = [head], []
while layer:
    for node in layer:
        print node.val, node.next.val if node.next else 'None'
        if node.left:
            nxt.append(node.left)
        if node.right:
            nxt.append(node.right)
    nxt, layer = [], nxt
