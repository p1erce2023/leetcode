class Solution:
    # @param {string} str
    # @return {integer}
    def myAtoi(self, str):
        if not str:
            return 0

        sign = 1
        i = 0
        begin_space, begin_sign, num = True, True, True
        re = 0
        numerical = set(["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"])
        n_array = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"]

        while i < len(str):
            if begin_space and str[i] == " ":
                i += 1
                continue
            elif begin_space:
                begin_space = False

            if not begin_space and begin_sign:
                if str[i] == "+":
                    begin_sign = False
                    i += 1
                    continue
                elif str[i] == "-":
                    sign = -1
                    begin_sign = False
                    i += 1
                    continue
                elif str[i] in numerical:
                    begin_sign = False
                else:
                    return 0

            if not begin_sign:
                if num and str[i] in numerical:
                    re = re * 10 + n_array.index(str[i])
                    if sign * re > 2147483647:
                        return 2147483647

                    if sign * re < -2147483648:
                        return -2147483648
                elif num:
                    num = False

            if not num:
                break

            i += 1

        if begin_space:
            return 0

        return sign * re


s = Solution()
assert s.myAtoi("0") == 0
assert s.myAtoi("") == 0
assert s.myAtoi("   ") == 0
assert s.myAtoi("-0") == 0
assert s.myAtoi("+0") == 0
assert s.myAtoi("+10") == 10
assert s.myAtoi("    10") == 10
assert s.myAtoi("8.24") == 8
assert s.myAtoi("18") == 18
assert s.myAtoi("-18") == -18
