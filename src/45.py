class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def jump(self, nums):
        # 56ms, yes, it it greedy
        n = len(nums)
        if n == 1:
            return 0
        p = 0
        l, r = 0, 1
        while True:
            nr = r
            for i in xrange(l, r):
                if i + nums[i] >= nr:
                    nr = i + nums[i]
            l, r = r, nr + 1
            p += 1
            if r >= n:
                return p

        # 100ms
        n = len(nums)
        s = [n] * n
        s[0] = 0
        p = 0
        for i in xrange(n):
            for j in xrange(p - i + 1, nums[i] + 1):
                if i + j < n:
                    s[i + j] = min(s[i + j], s[i] + 1)
            p = i + nums[i]
            if p >= n - 1:
                break
                    # print s
        return s[-1]


s = Solution()
print s.jump([2,4,7,1,1,1,0,1,1,1])  # 2
print s.jump([2,3,1,1,4])  # 2
print s.jump([0])  # 0
