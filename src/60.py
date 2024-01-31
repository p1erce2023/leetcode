class Solution(object):
    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        f = [1] * n
        for i in xrange(1, n):
            f[i] = f[i - 1] * i
        re = []
        nums = list(range(n))
        _k, j = k - 1, 0
        while nums:
            m = f[-1 - j]
            i = _k / m
            _k = _k % m
            j += 1
            re.append(nums[i])
            nums.remove(nums[i])
        return ''.join(str(y+1) for y in re)


f = lambda x: x and x * f(x - 1) or 1
s = Solution()
y = 4
for x in range(f(y)):
    print s.getPermutation(y, x + 1)  # 1234
