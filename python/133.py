# Definition for a undirected graph node
class UndirectedGraphNode:
    def __init__(self, x):
        self.label = x
        self.neighbors = []


def printGraph(n):
    frontier, visited = [n], set()
    serialization = []
    while frontier:
        x = frontier.pop()
        if x in visited:
            continue
        visited.add(x)
        serialization.append(
            str(x.label) +
            (',{}'.format(','.join(str(y.label) for y in x.neighbors)) if x.neighbors else ''))
        for y in x.neighbors:
            if y in visited:
                continue
            frontier.append(y)
    print('#'.join(serialization))


class Solution:
    # @param node, a undirected graph node
    # @return a undirected graph node
    # 关键是对图的表示的定义
    def cloneGraph(self, node):
        if not node:
            return None
        node.ref = UndirectedGraphNode(node.label)
        frontier, visited = [node], set()
        while frontier:
            x = frontier.pop()
            if x in visited:
                continue
            for n in x.neighbors:
                if not hasattr(n, 'ref'):
                    n.ref = UndirectedGraphNode(n.label)
                x.ref.neighbors.append(n.ref)
                frontier.append(n)
            visited.add(x)
        return node.ref


s = Solution()
A, B, C, D, E = UndirectedGraphNode(1), UndirectedGraphNode(2), UndirectedGraphNode(3), UndirectedGraphNode(4), UndirectedGraphNode(5)  # NOQA
A.neighbors.append(B)
A.neighbors.append(C)
B.neighbors.append(C)
B.neighbors.append(D)
B.neighbors.append(E)
D.neighbors.append(E)
printGraph(A)
X = s.cloneGraph(A)
printGraph(X)
print(X, A)

Z = UndirectedGraphNode(0)
Z.neighbors.append(Z)
Z.neighbors.append(Z)
printGraph(Z)
X = s.cloneGraph(Z)
printGraph(X)

V = UndirectedGraphNode(-1)
U = UndirectedGraphNode(1)
V.neighbors.append(U)
printGraph(V)
P = s.cloneGraph(V)
printGraph(P)
