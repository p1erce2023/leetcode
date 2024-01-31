class Solution:
    # @param {string[]} strs
    # @return {string}
    def longestCommonPrefix(self, strs):
        # indeed easy, no bug, nice result, 44ms
        if not strs or strs[0] == "":
            return ""
        elif len(strs) == 1:
            return strs[0]

        cp = []
        for i in xrange(len(strs[0])):
            t = strs[0][i]
            for s in strs:
                if i >= len(s) or t != s[i]:
                    return "".join(cp)
            cp.append(t)
        return "".join(cp)


s = Solution()
print s.longestCommonPrefix(["a"])
print s.longestCommonPrefix([])
print s.longestCommonPrefix(["aab", "aa"])
print s.longestCommonPrefix(["ca", "c"])