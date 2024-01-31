class Solution(object):
    def findOrder(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: bool
        """
        ''' 一开始对bfs弄错了，加入queue是可以加入0依赖的 '''
        graph = [(set(), set()) for _ in range(numCourses)]
        for pair in prerequisites:
            graph[pair[0]][0].add(pair[1])
            graph[pair[1]][1].add(pair[0])
        res = []
        queue = [i for i, node in enumerate(graph) if not len(node[0])]
        while queue:
            x = queue.pop()
            res.append(x)
            for i in graph[x][1]:
                graph[i][0].remove(x)
                if not graph[i][0]:
                    queue.append(i)
        return res if len(res) == numCourses else []


s = Solution()
# print(s.findOrder(3, [[1, 0], [1, 2], [0, 1]]))
print(s.findOrder(7, [[1, 0], [2, 1], [2, 3], [6, 2], [4, 3], [4, 5], [6, 4]]))
# print(s.findOrder(2, [[1, 0], [0, 1]]))
# print(s.findOrder(3, [[1, 0], [2, 1]]))
# print(s.findOrder(3, [[2, 0], [2, 1]]))
# print(s.findOrder(2, [[1, 0]]))
# print(s.findOrder(4, [[0, 1], [2, 3], [1, 2], [3, 0]]))
