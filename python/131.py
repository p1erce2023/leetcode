class Solution(object):
    def partition(self, s):
        """
        :type s: str
        :rtype: List[List[str]]
        """
        if not s:
            return [[]]
        n = len(s)
        if n == 1:
            return [[s]]
        res = []
        for i in range(1, n + 1):
            if self.isPalindrome(s[:i], i):
                for elem in self.partition(s[i:]):
                    elem.insert(0, s[:i])
                    res.append(elem)
        return res

    def isPalindrome(self, s, n):
        c = int(n / 2)
        for i in range(c):
            if s[i] != s[-i - 1]:
                return False
        return True


s = Solution()
print(s.partition('cababac'))
