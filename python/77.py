class Solution(object):
    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """
        # other's concise solution
        combs = [[]]
        for _ in range(k):
            combs = [[i] + c for c in combs for i in range(1, c[0] if c else n+1)]
        return combs

        # iterative
        if k > n or k <= 0:
            return []
        result, stack = [], [(list(range(1, n+1)), k, [])]
        while stack:
            s = stack.pop()
            if not s[1]:
                result.append(s[2])
            else:
                for i in range(len(s[0]) - s[1] + 1):
                    stack.append((s[0][i+1:], s[1] - 1, s[2] + [s[0][i]]))
        return result

        # recursive
        def select(lst, k):
            if k == 0:
                return []
            elif k == 1:
                return [[i] for i in lst]
            s = []
            for i in xrange(len(lst)-k+1):
                for r in select(lst[i+1:], k-1):
                    s.append([lst[i]] + r)
            return s
        return select(range(1, n + 1), k)

s = Solution()
print s.combine(5, 2)
# print s.combine(2, 2)
# print s.combine(5, 3)
# print s.combine(5, 0)
