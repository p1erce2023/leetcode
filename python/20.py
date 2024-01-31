class Solution:
    # @param {string} s
    # @return {boolean}
    def isValid(self, s):
        # 44ms, beat 60%
        stack = []
        left = set(["{", "[", "("])
        right = {"}": "{", "]": "[", ")": "("}
        for c in s:
            if c in left:
                stack.append(c)
            else:
                if not stack:
                    return False
                elif stack[-1] == right[c]:
                    stack.pop()
                else:
                    return False
        
        if stack:
            return False
        else:
            return True


s = Solution()
print s.isValid("(([][]))")
print s.isValid("(([[]]{}[]))")
print s.isValid("(([[]{][]))")
print s.isValid("")
print s.isValid("]]")
print s.isValid("[[]]]")
print s.isValid("([[]{][]))")