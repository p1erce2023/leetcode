class Solution(object):
    def canFinish(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: bool
        """
        dep = {n: set() for n in range(numCourses)}
        for pair in prerequisites:
            pool = set(dep[pair[1]])
            deps = set(pool)
            while pool:
                i = pool.pop()
                pool |= dep[i] - deps
                deps |= dep[i]
            if pair[0] in deps:
                return False
            dep[pair[0]].add(pair[1])
        return True


s = Solution()
print(s.canFinish(2, [[1, 0], [0, 1]]))
print(s.canFinish(2, [[1, 0]]))
print(s.canFinish(4, [[0, 1], [2, 3], [1, 2], [3, 0]]))
