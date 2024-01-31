class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """
        d = [False] * len(s)
        for i in range(len(s)):
            for j in range(-1, i):
                if (j == -1 or d[j]) and s[j + 1: i + 1] in wordDict:
                    d[i] = True
        return d[-1]


s = Solution()
print(s.wordBreak('ab', ['a', 'b']))
print(s.wordBreak('leetcode', ['leet', 'code']))
print(s.wordBreak('leetcode', ['le', 'code']))
print(s.wordBreak('leetcode', ['le', 'et', 'c', 'o', 'de']))
print(s.wordBreak('leetcode', ['le', 'et', 'c', 'de']))
