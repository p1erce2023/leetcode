class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        return ' '.join(reversed(s.split()))


s = Solution()
print(s.reverseWords('  the sky is   blue '))
