class Solution(object):
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        p = []
        for x in path.split("/"):
            if x == "..":
                if p: p.pop()
            elif x and x != ".":
                p.append(x)
        return "/" + "/".join(p)

s = Solution()
print s.simplifyPath("/../")
print s.simplifyPath("/home/pierce//")
print s.simplifyPath("/a/./b/../../c/")
print s.simplifyPath("/home//foo/")
