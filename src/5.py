class Solution:
    # @param {string} s
    # @return {string}
    def longestPalindrome(self, s):
        # average 316ms, is this the O(n) manacher algorithm? seems NOT
        # using max_len to accelerate computation when there is no hope exceed max_len
        # begin from the middle, then max_len has more chance get big num
        # with the instruction from 4.py, transform "abcba" to "#a#b#c#b#a#" to avoid sigular/even probelm
        if not s:
            return None
        re, max_len = "", 0
        n = len(s)
        for i in xrange(n, 0, -1):
            if i < max_len:
                break
            if i % 2:
                j = 0
            else:
                j = 1
            while i - j > 0 and i + j < 2 * n and s[(i - 1 - j) / 2] == s[(i - 1 + j) / 2]:
                j += 2
            j -= 2

            if j + 1 > max_len:
                re = s[(i - 1 - j) / 2:(i - 1 + j) / 2 + 1]
                max_len = j + 1

        for i in xrange(n + 1, 2 * n):
            if 2 * n - i < max_len:
                break
            if i % 2:
                j = 0
            else:
                j = 1
            while i - j > 0 and i + j < 2 * n and s[(i - 1 - j) / 2] == s[(i - 1 + j) / 2]:
                j += 2
            j -= 2

            if j + 1 > max_len:
                re = s[(i - 1 - j) / 2:(i - 1 + j) / 2 + 1]
                max_len = j + 1
        return re



s = Solution()

assert s.longestPalindrome("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa") == "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
assert s.longestPalindrome("aa") == "aa"
assert s.longestPalindrome("abababa") == "abababa"
assert s.longestPalindrome("aaa") == "aaa"
assert s.longestPalindrome("abcba") == "abcba"
assert s.longestPalindrome("xabcbay") == "abcba"
