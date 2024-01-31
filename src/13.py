class Solution:
    # @param {string} s
    # @return {integer}
    def romanToInt(self, s):
        # script 3: after reading the discuss, know about the math pattern, 168ms
        num = 0
        correlation = {"M": 1000, "D": 500, "C": 100, "L": 50, "X": 10, "V": 5, "I": 1}
        for i in xrange(len(s) - 1):
            if correlation[s[i+1]] > correlation[s[i]]:
                num -= correlation[s[i]]
            else:
                num += correlation[s[i]]
        return num + correlation[s[-1]]

        # script 2: in a reverse order, still slow, 208ms
        num = 0
        correlation = {"M": 1000, "D": 500, "C": 100, "L": 50, "X": 10, "V": 5, "I": 1}
        sign = dict((k, 1) for k in correlation)
        for c in s[::-1]:
            num += sign[c] * correlation[c]
            if c in ("X", "V"):
                sign["I"] = -1
            elif c in ("L", "C"):
                sign["X"] = -1
            elif c in ("M", "D"):
                sign["C"] = -1
        return num


        # script 1: 228ms, use i+=1 instead of s=s[i:] saves 60ms, slow also though.
        num = 0
        i = 0
        while i < len(s):
            if s[i:].startswith("M"):
                num += 1000
                i += 1
            elif s[i:].startswith("CM"):
                num += 900
                i += 2
            elif s[i:].startswith("D"):
                num += 500
                i += 1
            elif s[i:].startswith("CD"):
                num += 400
                i += 2
            elif s[i:].startswith("C"):
                num += 100
                i += 1
            elif s[i:].startswith("XC"):
                num += 90
                i += 2
            elif s[i:].startswith("L"):
                num += 50
                i += 1
            elif s[i:].startswith("XL"):
                num += 40
                i += 2
            elif s[i:].startswith("X"):
                num += 10
                i += 1
            elif s[i:].startswith("IX"):
                num += 9
                i += 2
            elif s[i:].startswith("V"):
                num += 5
                i += 1
            elif s[i:].startswith("IV"):
                num += 4
                i += 2
            elif s[i:].startswith("I"):
                num += 1
                i += 1
        return num


s = Solution()
assert s.romanToInt("C") == 100
assert s.romanToInt("MDXXXIX") == 1539
assert s.romanToInt("MCMXCIX") == 1999