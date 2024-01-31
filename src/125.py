class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        if not s:
            return True
        i, j = 0, len(s) - 1
        s = s.lower()
        valid_alphanumeric = {c for c in 'abcdefghijklmnopqrstuvwxyz0123456789'}
        while i < j:
            if s[i] not in valid_alphanumeric:
                i += 1
                continue
            if s[j] not in valid_alphanumeric:
                j -= 1
                continue
            if s[i] != s[j]:
                return False
            i += 1
            j -= 1
        return True

s = Solution()
print s.isPalindrome("A man, a plan, a canal: Panama")
print s.isPalindrome("race a car")
