class Solution:
    # @param {integer} x
    # @return {boolean}
    def isPalindrome(self, x):
        # 284ms
        if x < 0:
            return False

        y = x
        l = 0
        while y:
            y = y / 10
            l += 1
        # actually, use l = len(str(x)) can also pass, with 20ms less time

        y = x
        i = 0
        while i < l/2:
            if (y / (10 ** (l - i - 1))) % 10 == (y % (10 ** (i + 1))) / (10 ** i):
                i += 1
            else:
                return False

        return True


s = Solution()

assert s.isPalindrome(12344321)
assert s.isPalindrome(12321)
assert s.isPalindrome(121)
assert s.isPalindrome(11)
assert s.isPalindrome(1)
assert not s.isPalindrome(10)
assert not s.isPalindrome(1000021)
assert not s.isPalindrome(122)
assert not s.isPalindrome(-4)
