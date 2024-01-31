class Solution(object):
    def numTrees(self, n):
        """
        :type n: int
        :rtype: int
        f(0) = 1
        f(1) = 1
        f(n) = f(0)*f(n-1) + f(1)*f(n-2) + ... + f(n-1)*f(0)  also recursive way
        """
        f = [1]
        for i in xrange(1, n + 1):
            f.append(sum(f[j] * f[i - j - 1] for j in xrange(i)))
        return f[n]

s = Solution()
print s.numTrees(3)
