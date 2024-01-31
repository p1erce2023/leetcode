class Solution:
    # @param {integer} n
    # @return {string}
    def countAndSay(self, n):
        if n == 1:
            return "1"
        r = "1"
        i = 1
        while i < n:
            t = []
            l = r[0]
            m = 1
            for c in r[1:]:
                if c == l:
                    m += 1
                else:
                    t.append("%s%s" % (m, l))
                    l = c
                    m = 1
            t.append("%s%s" % (m, l))
            r = "".join(t)
            i += 1
        return r

s = Solution()
for i in range(1, 10):
    print "result", s.countAndSay(i)