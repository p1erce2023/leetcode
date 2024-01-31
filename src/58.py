class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        i, n = -1, len(s)
        while n+i >= 0 and s[i] == " ": 
            i -= 1
        end = i
        while n+i >= 0 and s[i] != " ":
            i -= 1
        return end - i

        
s = Solution()
print s.lengthOfLastWord("")
print s.lengthOfLastWord("  ")
print s.lengthOfLastWord("abc")
print s.lengthOfLastWord("Hello Worl")
print s.lengthOfLastWord("Hello    orld")
print s.lengthOfLastWord("Hello World  ")
print s.lengthOfLastWord("Hello  World  ")
