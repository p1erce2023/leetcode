class Solution(object):
    def isInterleave(self, s1, s2, s3):
        """
        :type s1: str
        :type s2: str
        :type s3: str
        :rtype: bool
        """
        l1, l2, l3 = len(s1), len(s2), len(s3)
        if min(l1, l2) == 0:
            return True if s1 + s2 == s3 else False
        if l1 + l2 != l3:
            return False
        s = [[False] * (l2 + 1) for _ in range(l1 + 1)]
        s[0][0] = True
        for i1 in range(l1 + 1):
            for i2 in range(l2 + 1):
                if s[i1][i2]:
                    if i1 < l1 and s3[i1 + i2] == s1[i1]:
                        s[i1 + 1][i2] = True
                    if i2 < l2 and s3[i1 + i2] == s2[i2]:
                        s[i1][i2 + 1] = True
        return s[-1][-1]


s = Solution()
print(s.isInterleave("aabcc", "dbbca", "aadbbcbcac"))
print(s.isInterleave("aa", "ab", "abaa"))
print(s.isInterleave("aabcc", "dbbca", "aadbbbaccc"))
