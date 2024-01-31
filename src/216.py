class Solution:
    def combinationSum3(self, k, n):
        """
        :type k: int
        :type n: int
        :rtype: List[List[int]]
        """
        if n > 45 or n < 1:
            return []
        res = []
        q = [(0, [], k, n)]
        while q:
            x, y, k, n = q.pop()
            if k == 1:
                if x < n < 10:
                    res.append(y + [n])
                continue
            if x > n or n > 9 * k:
                continue
            q.extend((i, y + [i], k - 1, n - i) for i in range(x + 1, min(n, 10)))
        return res

        # recursion is slow 上面迭代很快 不过说起来leetcode的python计时本来就不准
        def func(x, y, k, n, res):
            if k == 1:
                if x < n < 10:
                    res.append(y + [n])
                return
            if x > n or n > 9 * k:
                return
            for i in range(x + 1, min(n, 10)):
                y.append(i)
                func(i, y, k - 1, n - i, res)
                y.pop()

        if n > 45 or n < 1:
            return []
        res = []
        func(0, [], k, n, res)
        return res


s = Solution()
print(s.combinationSum3(3, 9))
print(s.combinationSum3(4, 25))
print(s.combinationSum3(2, 20))
