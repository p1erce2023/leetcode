class Solution:
    # @param {string} s
    # @param {string} p
    # @return {boolean}
    def isMatch(self, s, p):
        # script 2: dp algorithm, 100ms, most common one
        dp = [[False] * (len(p) + 1) for _ in xrange(len(s) + 1)]
        dp[0][0] = True
        for j in xrange(len(p)):
            if p[j] == "*":
                dp[0][j + 1] = dp[0][j - 1]
        i, j = 0, 0
        for i in xrange(len(s)):
            for j in xrange(len(p)):
                if p[j] == ".":
                    dp[i + 1][j + 1] = dp[i][j]
                elif p[j] == "*":
                    dp[i + 1][j + 1] = dp[i + 1][j - 1] or dp[i + 1][j] or \
                                        (dp[i][j + 1] and (p[j - 1] == s[i] or p[j - 1] == "."))
                else:
                    dp[i + 1][j + 1] = dp[i][j] and p[j] == s[i]
        return dp[-1][-1]


        # script 1: very slow, 236ms
        q = [(s, p)]
        while q:
            t_s, t_p = q.pop()
            if not t_s and not t_p:
                return True
            elif not t_p:
                continue
            if t_p[-1] == "*":
                precedent = t_p[-2]
                q.append((t_s, t_p[:-2]))
                for i in xrange(len(t_s) - 1, -1, -1):
                    if t_s[i] == precedent or precedent == ".":
                        q.append((t_s[:i], t_p[:-2]))
                    else:
                        break
                continue
            elif t_s and (t_s[-1] == t_p[-1] or t_p[-1] == "."):
                q.append((t_s[:-1], t_p[:-1]))
        return False


s = Solution()
assert s.isMatch("", ".*") == True
assert s.isMatch("aaafd", "a*f.*") == True
assert s.isMatch("bcdefd", "c*a*bcdef.*") == True
assert s.isMatch("aaba", "ab*a*c*a") == False
assert s.isMatch("aaab", "a*b") == True
assert s.isMatch("aaa", "a*a") == True
assert s.isMatch("aaaa", "aa*a") == True
assert s.isMatch("aa", "aa*a") == True
assert s.isMatch("ab", ".*c") == False
assert s.isMatch("aab", "c*a*b") == True
assert s.isMatch("aa", "a*") == True
assert s.isMatch("aa","a") == False
assert s.isMatch("aa","aa") == True
assert s.isMatch("aba","a.a") == True
assert s.isMatch("aaa","aa") == False
assert s.isMatch("aa", ".*") == True
assert s.isMatch("ab", ".*") == True

