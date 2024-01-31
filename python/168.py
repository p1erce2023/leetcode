class Solution(object):
    def convertToTitle(self, n):
        """
        :type n: int
        :rtype: str
        """
        x = []
        n = n - 1
        if not n:
            return 'A'
        while n > 0:
            i = int(n / 26)
            j = n - i * 26
            n = i - 1
            x.append(chr(65 + j))
            if n == 0:
                x.append('A')
        return ''.join(reversed(x))


s = Solution()
for i in range(1, 4):
    print(s.convertToTitle(i))
print(s.convertToTitle(26))
print(s.convertToTitle(29))
print(s.convertToTitle(52))
print(s.convertToTitle(78))
print(s.convertToTitle(144))
print(s.convertToTitle(676))
print(s.convertToTitle(702))
