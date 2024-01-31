class Solution(object):
    def grayCode(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        # advance property
        return [num ^ (num >> 1) for num in xrange(2**n)]

        # resort to https://en.wikipedia.org/wiki/Gray_code
        # binary system => complete property
        result = [0]
        for i in xrange(n):
            result += [x + pow(2, i) for x in reversed(result)]
        return result

'''
0 1
00 01 11 10
000 001 011 010 110 111 101 100
'''
s = Solution()
print [bin(x) for x in s.grayCode(4)]
