class Solution:
    # @param {integer} num
    # @return {string}
    def intToRoman(self, num):
        # 132ms, nice implementation, easy problem
        roman = []
        digits = [1000, 100, 10, 1]
        trans = [['M'], ['C', 'D'], ['X', 'L'], ['I', 'V']]
        for i, d in enumerate(digits):
            t = num / d
            num = num % d
            if t == 9:
                roman.append(trans[i][0] + trans[i-1][0])
            elif t >= 5:
                roman.append(trans[i][1] + trans[i][0] * (t - 5))
            elif t == 4:
                roman.append(trans[i][0] + trans[i][1])
            elif t:
                roman.append(trans[i][0] * t)
        return "".join(roman)


s = Solution()
assert s.intToRoman(1539) == "MDXXXIX"
assert s.intToRoman(1999) == "MCMXCIX"