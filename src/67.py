class Solution(object):
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        # pathonic way
        return bin(int(a, 2) + int(b, 2))[2:]
        # BTW, timeit.timeit('int("010010101010101", 2)') is much faster than
        # timeit.timeit('eval("0b" + "010010101010101")')

        # algorithm
        n, m = len(a), len(b)
        a = [int(x) for x in a]
        b = [int(x) for x in b]
        if n < m:
            n, m = m, n
            a, b = b, a
        c = [0] * n
        i = 0
        t = 0
        while i < m:
            c[-1-i] = a[-1-i] ^ b[-1-i] ^ t
            t = (a[-1-i] & b[-1-i]) + ((a[-1-i] ^ b[-1-i]) & t)
            i += 1
        while i < n:
            c[-1-i] = a[-1-i] ^ t
            t = a[-1-i] & t
            i += 1
        if t:
            c.insert(0, t)
        return "".join([str(x) for x in c])

s = Solution()
print s.addBinary("101", "11")
