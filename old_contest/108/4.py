class Solution:
    def beautifulArray(self, N):
        """
        :type N: int
        :rtype: List[int]
        很厉害 divide and conquer
        2个特性 若[a, b, c] 美，那么[a*2, b*2, c*2]也美，[a+1, b+1, c+1]也美
        另外奇偶对半分后*2肯定为偶，而横跨的之和肯定为奇

        吐槽 leetcode python 计时 1竟然比2快
        """
        if N == 1:
            return [1]
        else:
            lx = self.beautifulArray(N // 2)
            rx = self.beautifulArray(N - N // 2)
            return [2*x - 1 for x in rx] + [2*x for x in lx]

    def beautifulArray2(self, N):
        def get(x):
            if self.cache[x]:
                return self.cache[x]
            else:
                xx = get(x // 2)
                yy = get(x - x // 2)
                self.cache[x] = [2*x - 1 for x in yy] + [2*x for x in xx]
                return self.cache[x]

        self.cache = [None] * (N + 1)
        self.cache[1] = [1]
        return get(N)


s = Solution()
for i in range(1, 5000):
    assert(s.beautifulArray2(i) == s.beautifulArray(i))
